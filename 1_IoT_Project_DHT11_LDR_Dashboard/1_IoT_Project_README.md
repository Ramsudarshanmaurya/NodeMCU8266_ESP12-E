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
| 10K Resistor | GND side | GND |

---

## 🌐 System Architecture

```
┌─────────────────────────────────────────┐
│         Hardware Layer                   │
│   DHT11 Sensor    LDR Sensor            │
│   (Temp+Humi)     (Light)               │
└──────────────┬──────────────────────────┘
               ↓
┌─────────────────────────────────────────┐
│         ESP12-E (ESP8266)               │
│   WiFi Connected | Arduino IDE          │
└──────────────┬──────────────────────────┘
               ↓ WiFi / MQTT
┌─────────────────────────────────────────┐
│         HiveMQ MQTT Broker              │
│   broker.hivemq.com : 1883             │
└──────────────┬──────────────────────────┘
               ↓
┌─────────────────────────────────────────┐
│         Node-RED Flow                   │
│   MQTT In → Gauge + Chart              │
└──────────────┬──────────────────────────┘
               ↓
┌─────────────────────────────────────────┐
│      Live Dashboard (127.0.0.1:1880/ui) │
│   Page 1: Gauges | Page 2: Charts      │
└─────────────────────────────────────────┘
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

### Page 1 — Sensors (Gauges)

| 🌡️ Temperature | 💧 Humidity | 💡 Light |
|:---:|:---:|:---:|
| 0 - 50 °C | 0 - 100 % | 0 - 1024 lux |
| Live Gauge | Live Gauge | Live Gauge |

### Page 2 — Charts (Live Graphs)

| 📈 Temperature Graph | 📈 Humidity Graph | 📈 Light Graph |
|:---:|:---:|:---:|
| Line Chart | Line Chart | Line Chart |
| Real-time | Real-time | Real-time |

---

## 🖼️ Images

> Add images in `Images/` folder — they will show here automatically!

| Circuit | Dashboard | Node-RED Flow |
|:---:|:---:|:---:|
| ![Circuit](Images/01_circuit.jpg) | ![Dashboard](Images/02_dashboard.jpg) | ![Flow](Images/03_nodered_flow.jpg) |

| Serial Monitor | Gauge View | Chart View |
|:---:|:---:|:---:|
| ![Serial](Images/04_serial_monitor.jpg) | ![Gauge](Images/05_gauge.jpg) | ![Chart](Images/06_chart.jpg) |

---

## 🎥 Demo Video

> Add your video in `Video/` folder or paste YouTube link here!

<!--
[![Demo Video](Images/thumbnail.jpg)](your_youtube_link)
-->

---

## 📈 Graphs & Charts

> Add graph screenshots in `Assets/graphs/` folder!

<!--
![Temperature Graph](Assets/graphs/temperature_graph.png)
![Humidity Graph](Assets/graphs/humidity_graph.png)
![Light Graph](Assets/graphs/ldr_chart.png)
-->

---

## 💻 Code

📄 [View Full Code](Code/1_iot_project.ino)

### Libraries Used

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
│   ├── 01_circuit.jpg
│   ├── 02_dashboard.jpg
│   ├── 03_nodered_flow.jpg
│   ├── 04_serial_monitor.jpg
│   ├── 05_gauge.jpg
│   └── 06_chart.jpg
│
├── Video/
│   └── 01_demo.mp4
│
├── Schematics/
│   └── circuit_diagram.png
│
├── NodeRED_Flow/
│   └── flow.json
│
├── Documents/
│   └── project_details.pdf
│
└── Assets/
    ├── graphs/
    │   ├── temperature_graph.png
    │   └── humidity_graph.png
    └── charts/
        └── ldr_chart.png
```

---

## ⚙️ Software Setup

### 1. Arduino IDE Setup
- Install ESP8266 Board
- Install DHT library
- Install PubSubClient library

### 2. Node-RED Setup
- Install node-red-dashboard
- Import flow.json
- Deploy

### 3. MQTT Broker
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

<div align="center">
Made with ❤️ by Ramsudarshan Maurya
</div>
