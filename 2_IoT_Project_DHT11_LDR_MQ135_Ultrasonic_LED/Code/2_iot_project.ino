#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ─────────────────────────────────────────
//  OLED CONFIG
// ─────────────────────────────────────────
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ─────────────────────────────────────────
//  PIN DEFINITIONS
// ─────────────────────────────────────────
#define DHTPIN        D5    // DHT11 Data Pin
#define DHTTYPE       DHT11
#define LDRPIN        D3    // LDR Digital Pin
#define MQ135PIN      A0    // MQ135 Analog Pin
#define TRIG_PIN      D6    // Ultrasonic Trigger
#define ECHO_PIN      D7    // Ultrasonic Echo
#define LED1_PIN      D4    // External LED - Ultrasonic (Active HIGH)
#define LED2_PIN      D8    // External LED - Node-RED Switch Control
// OLED SDA → D2, SCL → D1 (I2C default)

// ─────────────────────────────────────────
//  WIFI & MQTT CONFIG
// ─────────────────────────────────────────
const char* ssid        = "RSMaurya";
const char* password    = "RS8808044818";
const char* mqtt_server = "broker.hivemq.com";

// ─────────────────────────────────────────
//  MQTT TOPICS
// ─────────────────────────────────────────
#define TOPIC_TEMP      "tempNode"
#define TOPIC_HUMI      "humiNode"
#define TOPIC_LDR       "ldrNode"
#define TOPIC_MQ135     "mq135Node"
#define TOPIC_DISTANCE  "distanceNode"
#define TOPIC_LED1      "led1StatusNode"
#define TOPIC_LED2_SUB  "led2ControlNode"

// ─────────────────────────────────────────
//  OBJECTS
// ─────────────────────────────────────────
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg    = 0;
long lastOLED   = 0;
bool objectDetected = false;
float lastTemp  = 0;
float lastHumi  = 0;
String lastLDR  = "Dark";
int lastMQ135   = 0;
float lastDist  = 0;

// ─────────────────────────────────────────
//  OLED DISPLAY
// ─────────────────────────────────────────
void updateOLED(bool detected, float dist) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  if (detected) {
    // ── Object Detected Screen ──
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("!! ALERT !!");
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.println("Object Detected!");
    display.setCursor(0, 32);
    display.print("Distance: ");
    display.print(dist);
    display.println(" cm");
    display.setCursor(0, 44);
    display.println("LED1 → ON");
  } else {
    // ── Normal Sensor Screen ──
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Temp : ");
    display.print(lastTemp);
    display.println(" C");

    display.setCursor(0, 12);
    display.print("Humi : ");
    display.print(lastHumi);
    display.println(" %");

    display.setCursor(0, 24);
    display.print("LDR  : ");
    display.println(lastLDR);

    display.setCursor(0, 36);
    display.print("MQ135: ");
    display.println(lastMQ135);

    display.setCursor(0, 48);
    display.print("Dist : ");
    display.print(lastDist);
    display.println(" cm");
  }

  display.display();
}

// ─────────────────────────────────────────
//  WIFI SETUP
// ─────────────────────────────────────────
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("📶 Connecting to WiFi: ");
  Serial.println(ssid);

  // Show on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.println(ssid);
  display.display();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {
      Serial.println("\n❌ WiFi Failed! Restarting...");
      ESP.restart();
    }
  }

  Serial.println("\n✅ WiFi Connected!");
  Serial.print("📍 IP: ");
  Serial.println(WiFi.localIP());

  // Show IP on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("WiFi Connected!");
  display.setCursor(0, 16);
  display.println(WiFi.localIP());
  display.display();
  delay(2000);
}

// ─────────────────────────────────────────
//  MQTT CALLBACK (Node-RED → ESP)
// ─────────────────────────────────────────
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("📩 MQTT Received [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(message);

  if (String(topic) == TOPIC_LED2_SUB) {
    if (message == "1" || message == "true" || message == "ON") {
      digitalWrite(LED2_PIN, HIGH);
      Serial.println("💡 LED2 → ON");
    } else {
      digitalWrite(LED2_PIN, LOW);
      Serial.println("💡 LED2 → OFF");
    }
  }
}

// ─────────────────────────────────────────
//  MQTT RECONNECT
// ─────────────────────────────────────────
void reconnect() {
  int tries = 0;
  while (!client.connected()) {
    Serial.print("🔌 Connecting to MQTT...");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Connecting MQTT...");
    display.display();

    String clientId = "ESP8266-" + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("✅ MQTT Connected!");
      client.subscribe(TOPIC_LED2_SUB);
      Serial.println("📡 Subscribed: " + String(TOPIC_LED2_SUB));

      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("MQTT Connected!");
      display.display();
      delay(1000);

    } else {
      Serial.print("❌ Failed! rc=");
      Serial.print(client.state());
      Serial.println(" Retry in 3 sec...");
      tries++;
      if (tries > 5) {
        Serial.println("⚠️ Too many failures. Restarting...");
        ESP.restart();
      }
      delay(3000);
    }
  }
}

// ─────────────────────────────────────────
//  ULTRASONIC DISTANCE
// ─────────────────────────────────────────
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  float distance = (duration * 0.034) / 2;
  return distance;
}

// ─────────────────────────────────────────
//  SETUP
// ─────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(100);

  // OLED Init
  Wire.begin(D2, D1); // SDA = D2, SCL = D1
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("❌ OLED not found!");
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("IoT Project 2");
  display.println("Initializing...");
  display.display();
  delay(1000);

  // Sensor & Pin Init
  dht.begin();
  pinMode(LDRPIN,   INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  Serial.println("✅ Setup Done!");
}

// ─────────────────────────────────────────
//  LOOP
// ─────────────────────────────────────────
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // ── Ultrasonic Check (every loop - fast response) ──
  float distance = getDistance();
  objectDetected = (distance > 0 && distance <= 15.0);

  if (objectDetected) {
    digitalWrite(LED1_PIN, HIGH);
    Serial.print("🚨 Object Detected! Distance: ");
    Serial.print(distance);
    Serial.println(" cm → LED1 ON");
  } else {
    digitalWrite(LED1_PIN, LOW);
  }

  // ── OLED Update (every 500ms) ──
  long now = millis();
  if (now - lastOLED > 500) {
    lastOLED = now;
    lastDist = distance > 0 ? distance : lastDist;
    updateOLED(objectDetected, distance);
  }

  // ── Sensor Publish (every 5 seconds) ──
  if (now - lastMsg > 5000) {
    lastMsg = now;

    lastTemp  = dht.readTemperature();
    lastHumi  = dht.readHumidity();
    int ldr   = digitalRead(LDRPIN);    // 1=Light, 0=Dark
    lastMQ135 = analogRead(MQ135PIN);   // 0-1024
    float dist_pub = getDistance();

    if (isnan(lastTemp) || isnan(lastHumi)) {
      Serial.println("❌ DHT Sensor Error!");
      return;
    }

    lastLDR = (ldr == 1) ? "Light" : "Dark";

    Serial.print("🌡️ Temp: ");     Serial.print(lastTemp);  Serial.print("°C  ");
    Serial.print("💧 Humi: ");     Serial.print(lastHumi);  Serial.print("%  ");
    Serial.print("💡 LDR: ");      Serial.print(lastLDR);   Serial.print("  ");
    Serial.print("💨 MQ135: ");    Serial.print(lastMQ135); Serial.print("  ");
    Serial.print("📏 Distance: "); Serial.print(dist_pub);  Serial.println(" cm");

    client.publish(TOPIC_TEMP,     String(lastTemp).c_str());
    client.publish(TOPIC_HUMI,     String(lastHumi).c_str());
    client.publish(TOPIC_LDR,      lastLDR.c_str());
    client.publish(TOPIC_MQ135,    String(lastMQ135).c_str());
    client.publish(TOPIC_DISTANCE, String(dist_pub).c_str());
    client.publish(TOPIC_LED1,     objectDetected ? "ON" : "OFF");

    Serial.println("✅ Data Published!");
  }
}
