# ⚡ IoT Dashboard — DHT11 + LDR + Node-RED

<div align="center">

![Project](https://img.shields.io/badge/Project-1-blue?style=for-the-badge)
![ESP8266](https://img.shields.io/badge/ESP8266-ESP12--E-red?style=for-the-badge&logo=espressif)
![DHT11](https://img.shields.io/badge/Sensor-DHT11-green?style=for-the-badge)
![LDR](https://img.shields.io/badge/Sensor-LDR-yellow?style=for-the-badge)
![MQTT](https://img.shields.io/badge/MQTT-HiveMQ-orange?style=for-the-badge)
![Node-RED](https://img.shields.io/badge/Node--RED-Dashboard-red?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Tested-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**Real-time Temperature, Humidity & Light Monitoring System**
ESP8266 | MQTT | HiveMQ | Node-RED | Live Dashboard

</div>

---

## 📋 Description

> Real-time IoT monitoring system using **ESP12-E (ESP8266)** with **DHT11** and **LDR** sensors.
> Data published via **MQTT Protocol** to **HiveMQ Broker** and visualized on **Node-RED Dashboard**
> with live **Gauges** and **Charts** on 2 separate pages.

---

## 🔧 Hardware Used

| Component | Description | Quantity |
|-----------|-------------|----------|
| ESP12-E (ESP8266) | WiFi Microcontroller | 1 |
| DHT11 | Temperature & Humidity Sensor | 1 |
| LDR | Light Dependent Resistor | 1 |
| 10K Resistor | Voltage Divider for LDR | 1 |
| Jumper Wires | Connections | As needed |
| Breadboard | Circuit Assembly | 1 |

---

## 📌 Pin Connections

| Sensor | Pin | ESP12-E Pin |
|--------|-----|-------------|
| DHT11 VCC | Power | 3.3V |
| DHT11 GND | Ground | GND |
| DHT11 DATA | Signal | D2 (GPIO4) |
| LDR Leg 1 | Power | 3.3V |
| LDR Leg 2 | Analog | A0 |
| 10K Resistor | One end — LDR Leg 2, Other end — GND | GND |

---

## 🌐 System Architecture

```
DHT11 + LDR Sensors
        ↓
  ESP12-E (ESP8266)
        ↓ WiFi
  HiveMQ MQTT Broker
  broker.hivemq.com:1883
        ↓
     Node-RED
        ↓
Live Dashboard (127.0.0.1:1880/ui)
Gauges + Charts
```

---

## 📡 MQTT Topics

| Topic | Sensor | Data | Unit |
|-------|--------|------|------|
| `tempNode` | DHT11 | Temperature | °C |
| `humiNode` | DHT11 | Humidity | % |
| `ldrNode` | LDR | Light Value | lux |

---

## 📊 Node-RED Dashboard

**Page 1 — Sensors (Gauges)**

| 🌡️ Temperature | 💧 Humidity | 💡 Light |
|:---:|:---:|:---:|
| 0 - 50 °C | 0 - 100 % | 0 - 1024 lux |

**Page 2 — Charts (Live Graphs)**

| 📈 Temperature Graph | 📈 Humidity Graph | 📈 Light Graph |
|:---:|:---:|:---:|
| Line Chart | Line Chart | Line Chart |

---

## 🖼️ Images

| | | |
|:---:|:---:|:---:|
| ![image1](Images/image1.jpg) | ![image2](Images/image2.png) | ![image3](Images/image3.png) |
| Circuit Diagram | Dashboard View | Node-RED Flow |
| ![image4](Images/image4.png) | ![image5](Images/image5.png) | ![image6](Images/image6.png) |
| Serial Monitor | Gauge View | Chart View |

---

## 🎥 Demo Video

| Video | Description |
|:---:|:---:|
| [▶️ Watch Demo](Video/video1.mp4) | Full project working demo |

---

## 💻 Code

📄 [View Full Code](Code/1_iot_project.ino)

| Library | Purpose |
|---------|---------|
| ESP8266WiFi.h | WiFi Connection |
| PubSubClient.h | MQTT Protocol |
| DHT.h | DHT11 Sensor |

---

## 📁 Folder Structure

```
1_IoT_Project_DHT11_LDR_Dashboard/
│
├── README.md
│
├── Code/
│   └── 1_iot_project.ino
│
├── Images/
│   ├── image1.jpeg   ← Circuit Diagram
│   ├── image2.jpeg   ← Dashboard View
│   ├── image3.jpeg   ← Node-RED Flow
│   ├── image4.jpeg   ← Serial Monitor
│   ├── image5.jpeg   ← Gauge View
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

## ⚙️ Setup Guide

**Arduino IDE:**
- Install ESP8266 Board
- Install DHT library (Adafruit)
- Install PubSubClient library

**Node-RED:**
- Install node-red-dashboard
- Import NodeRED_Flow/flow.json
- Deploy and open 127.0.0.1:1880/ui

**MQTT Broker:**
- Server: broker.hivemq.com
- Port: 1883

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
