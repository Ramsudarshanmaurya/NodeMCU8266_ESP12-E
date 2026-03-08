#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11
#define LDRPIN A0

const char* ssid = "RSMaurya";
const char* password = "RS8808044818";
const char* mqtt_server = "broker.hivemq.com";

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if(attempts > 20) {
      Serial.println("\nWiFi Failed! Restarting...");
      ESP.restart();
    }
  }
  Serial.println("\n✅ WiFi Connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  int tries = 0;
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    
    String clientId = "ESP8266-" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("✅ MQTT Connected!");
    } else {
      Serial.print("❌ Failed! rc=");
      Serial.print(client.state());
      Serial.println(" Retry in 3 sec...");
      tries++;
      if(tries > 5) {
        Serial.println("Too many failures. Restarting...");
        ESP.restart();
      }
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);
  dht.begin();
  pinMode(LDRPIN, INPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  Serial.println("Setup Done!");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    float temp = dht.readTemperature();
    float humi = dht.readHumidity();
    int ldr = analogRead(LDRPIN);

    if (isnan(temp) || isnan(humi)) {
      Serial.println("❌ DHT Sensor Error!");
      return;
    }

    Serial.print("🌡️ Temp: ");
    Serial.print(temp);
    Serial.print("°C  💧 Humi: ");
    Serial.print(humi);
    Serial.print("%  💡 LDR: ");
    Serial.println(ldr);

    client.publish("tempNode", String(temp).c_str());
    client.publish("humiNode", String(humi).c_str());
    client.publish("ldrNode", String(ldr).c_str());
    Serial.println("✅ Data Published!");
  }
}