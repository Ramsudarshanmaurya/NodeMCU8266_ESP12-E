# ⚡ IoT Dashboard — DHT11 + LDR + MQ135 + Ultrasonic + OLED + LED Control

<div align="center">

![Project](https://img.shields.io/badge/Project-2-blue?style=for-the-badge)
![ESP8266](https://img.shields.io/badge/ESP8266-ESP12--E-red?style=for-the-badge&logo=espressif)
![DHT11](https://img.shields.io/badge/Sensor-DHT11-green?style=for-the-badge)
![LDR](https://img.shields.io/badge/Sensor-LDR-yellow?style=for-the-badge)
![MQ135](https://img.shields.io/badge/Sensor-MQ135-orange?style=for-the-badge)
![Ultrasonic](https://img.shields.io/badge/Sensor-HC--SR04-purple?style=for-the-badge)
![OLED](https://img.shields.io/badge/Display-OLED--SSD1306-white?style=for-the-badge)
![MQTT](https://img.shields.io/badge/MQTT-HiveMQ-orange?style=for-the-badge)
![Node-RED](https://img.shields.io/badge/Node--RED-Dashboard-red?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Tested-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Real-time Temperature, Humidity, Light, Air Quality & Distance Monitoring**
**+ OLED Display + LED Control via Node-RED**
ESP8266 | MQTT | HiveMQ | Node-RED | Live Dashboard

</div>

---

## 📋 Description

> Advanced IoT monitoring system using **ESP12-E (ESP8266)** with **DHT11**, **LDR**, **MQ135**, **HC-SR04 Ultrasonic** sensors and **SSD1306 OLED Display**.
> - **OLED Display** shows all sensor values in real-time.
> - **OLED Alert** shows "!! ALERT !!" when object detected within **15cm**.
> - **LED1 (D4)** automatically glows when object detected within **15cm**.
> - **LED2 (D8)** is controlled remotely via **Node-RED Dashboard Switch** using MQTT.
> - All data published via **MQTT Protocol** to **HiveMQ Broker** and visualized on **Node-RED Dashboard**.

---

## 🔧 Hardware Used

| Component | Description | Quantity |
|-----------|-------------|----------|
| ESP12-E (ESP8266) | WiFi Microcontroller | 1 |
| DHT11 | Temperature & Humidity Sensor | 1 |
| LDR Module | Light Dependent Resistor (Digital) | 1 |
| MQ135 | Air Quality / Gas Sensor (Analog) | 1 |
| HC-SR04 | Ultrasonic Distance Sensor | 1 |
| SSD1306 OLED | 128x64 I2C Display | 1 |
| LED 1 | Ultrasonic Trigger LED (≤15cm) | 1 |
| LED 2 | Node-RED Switch Controlled LED | 1 |
| 220Ω Resistor | Current Limiting for LEDs | 2 |
| 10K Resistor | Pull-down for D4 LED | 1 |
| 1KΩ Resistor | Voltage Divider ECHO pin | 1 |
| 2KΩ Resistor | Voltage Divider ECHO pin | 1 |
| Jumper Wires | Connections | As needed |
| Breadboard | Circuit Assembly | 1 |

---

## 📌 Pin Connections

| Component | Pin | ESP12-E Pin |
|-----------|-----|-------------|
| DHT11 VCC | Power | 3.3V |
| DHT11 GND | Ground | GND |
| DHT11 DATA | Signal | D5 (GPIO14) |
| LDR VCC | Power | 3.3V |
| LDR GND | Ground | GND |
| LDR DOUT | Digital Signal | D3 (GPIO0) |
| MQ135 VCC | Power | 3.3V |
| MQ135 GND | Ground | GND |
| MQ135 AOUT | Analog Signal | A0 |
| HC-SR04 VCC | Power | **VIN (5V)** ⚠️ |
| HC-SR04 GND | Ground | GND |
| HC-SR04 TRIG | Trigger | D6 (GPIO12) |
| HC-SR04 ECHO | **Voltage Divider** → | D7 (GPIO13) ⚠️ |
| OLED VCC | Power | 3.3V |
| OLED GND | Ground | GND |
| OLED SDA | I2C Data | D2 (GPIO4) |
| OLED SCL | I2C Clock | D1 (GPIO5) |
| LED1 (+) | Anode | D4 (GPIO2) |
| LED1 (-) | Cathode via 220Ω | GND |
| LED2 (+) | Anode | D8 (GPIO15) |
| LED2 (-) | Cathode via 220Ω | GND |

### ⚠️ HC-SR04 ECHO Voltage Divider (5V → 3.3V)
```
HC-SR04 ECHO → [1KΩ] → D7 (ESP8266)
                             |
                           [2KΩ]
                             |
                            GND
```

---

## 🖥️ OLED Display Screens

**Normal Mode:**
```
Temp : 31.5 C
Humi : 24.0 %
LDR  : Light
MQ135: 99
Dist : 42.3 cm
```

**Alert Mode (Object ≤ 15cm):**
```
!! ALERT !!
Object Detected!
Distance: 9.1 cm
LED1 → ON
```

---

## 🌐 System Architecture

```
DHT11 + LDR + MQ135 + HC-SR04
            ↓
     ESP12-E (ESP8266)
       ↓           ↓
  OLED Display   WiFi
                  ↓
          HiveMQ MQTT Broker
          broker.hivemq.com:1883
            ↓           ↑
         Node-RED    MQTT Subscribe
            ↓        (LED2 Control)
    Live Dashboard (127.0.0.1:1880/ui)
    Gauges + Charts + Switch
```

---

## 📡 MQTT Topics

### Publish (ESP → Node-RED)

| Topic | Sensor | Data | Type |
|-------|--------|------|------|
| `tempNode` | DHT11 | Temperature | °C |
| `humiNode` | DHT11 | Humidity | % |
| `ldrNode` | LDR | Light / Dark | Text |
| `mq135Node` | MQ135 | Air Quality | 0-1024 |
| `distanceNode` | HC-SR04 | Distance | cm |
| `led1StatusNode` | LED1 | ON / OFF | Auto |

### Subscribe (Node-RED → ESP)

| Topic | Control | Data |
|-------|---------|------|
| `led2ControlNode` | LED2 Switch | 1/0 or ON/OFF |

---

## 🔴 LED Logic

| LED | Pin | Trigger | Condition |
|-----|-----|---------|-----------|
| LED1 | D4 | HC-SR04 | Auto ON when object ≤ 15cm |
| LED2 | D8 | Node-RED Switch | Manual ON/OFF via MQTT |

---

## 📊 Node-RED Dashboard

**Page 1 — Sensors**

| 🌡️ Temp | 💧 Humi | 💡 LDR | 💨 MQ135 | 📏 Distance | 🔴 LED1 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| Gauge | Gauge | Text | Gauge | Gauge | Text |

**Page 2 — Charts**

| 🌡️ Temp | 💧 Humi | 💡 LDR | 💨 MQ135 | 📏 Distance |
|:---:|:---:|:---:|:---:|:---:|
| Line Chart | Line Chart | Line Chart | Line Chart | Line Chart |

**Page 3 — Control**

| 💡 LED2 Switch |
|:---:|
| Toggle ON/OFF |

---

## 🖼️ Images

| | | |
|:---:|:---:|:---:|
| ![image1](Images/image1.jpeg) | ![image2](Images/image2.jpeg) | ![image3](Images/image3.jpeg) |
| Circuit Diagram | Dashboard View | Node-RED Flow |
| ![image4](Images/image4.jpeg) | ![image5](Images/image5.jpeg) | ![image6](Images/image6.jpeg) |
| Serial Monitor | OLED Display | Chart View |

---

## 🎥 Demo Video

| Video | Description |
|:---:|:---:|
| [▶️ Watch Demo](Video/video1.mp4) | Full project working demo |

---

## 💻 Code

📄 [View Full Code](Code/2_iot_project.ino)

| Library | Purpose |
|---------|---------|
| ESP8266WiFi.h | WiFi Connection |
| PubSubClient.h | MQTT Protocol |
| DHT.h | DHT11 Sensor |
| Wire.h | I2C Communication |
| Adafruit_GFX.h | OLED Graphics |
| Adafruit_SSD1306.h | OLED Display |

---

## ⚙️ Setup Guide

**Arduino IDE:**
- Board: NodeMCU 1.0 (ESP-12E Module)
- Install ESP8266 Board Package
- Install Libraries:
  - DHT sensor library (Adafruit)
  - PubSubClient
  - Adafruit SSD1306
  - Adafruit GFX Library
- Baud Rate: 115200

**Node-RED:**
- Install `node-red-dashboard`
- Import `NodeRED_Flow/flow.json`
- Deploy and open `127.0.0.1:1880/ui`

**MQTT Broker:**
- Server: `broker.hivemq.com`
- Port: `1883`

---

## 📁 Folder Structure

```
2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/
│
├── README.md
│
├── Code/
│   └── 2_iot_project.ino
│
├── Images/
│   ├── image1.jpeg   ← Circuit Diagram
│   ├── image2.jpeg   ← Dashboard View
│   ├── image3.jpeg   ← Node-RED Flow
│   ├── image4.jpeg   ← Serial Monitor
│   ├── image5.jpeg   ← OLED Display
│   └── image6.jpeg   ← Chart View
│
├── Video/
│   └── video1.mp4
│
├── NodeRED_Flow/
│   └── flow.json
│
└── Documents/
    └── IoT_NodeRED_Documentation.docx
```

---

<div align="center">

### 🔗 Connect With Me

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue?style=for-the-badge&logo=linkedin)](https://linkedin.com/in/ramsudarshanmaurya)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black?style=for-the-badge&logo=github)](https://github.com/Ramsudarshanmaurya)
[![Portfolio](https://img.shields.io/badge/Portfolio-Visit-green?style=for-the-badge)](https://ramsudarshanmaurya.engineer)
[![Email](https://img.shields.io/badge/Email-Contact-red?style=for-the-badge&logo=gmail)](mailto:ramsudarshanmaurya@gmail.com)

**⭐ Star this repo if you found it helpful!**

[⬆ Back to Main README](../README.md)

</div>

---

## 👤 About Me

| | |
|---|---|
| 👨‍💻 **Name** | Ramsudarshan Maurya |
| 🏢 **Company** | UniConverge Technologies |
| 📍 **Location** | Noida Sector 62 |
| 📧 **Email** | [ramsudarshanmaurya@gmail.com](mailto:ramsudarshanmaurya@gmail.com) |
| 💼 **LinkedIn** | [in/ramsudarshanmaurya](https://linkedin.com/in/ramsudarshanmaurya) |
| 🌐 **Portfolio** | [ramsudarshanmaurya.engineer](https://ramsudarshanmaurya.engineer) |
| 🐙 **GitHub** | [Ramsudarshanmaurya](https://github.com/Ramsudarshanmaurya) |
| 📁 **Drive** | [Project Files](https://drive.google.com/drive/folders/1SslKdhRWbyK213nZJpzLBBzx7PcJapPm?usp=sharing) |

---

<div align="center">
Made with ❤️ by Ramsudarshan Maurya
</div>
