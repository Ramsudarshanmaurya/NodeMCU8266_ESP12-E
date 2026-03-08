# ⚡ NodeMCU8266 / ESP12-E IoT Projects

<div align="center">

![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-blue?style=for-the-badge&logo=espressif)
![MQTT](https://img.shields.io/badge/MQTT-HiveMQ-orange?style=for-the-badge)
![Node-RED](https://img.shields.io/badge/Node--RED-Dashboard-red?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-IDE-teal?style=for-the-badge&logo=arduino)
![IoT](https://img.shields.io/badge/IoT-Projects-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**WiFi-based IoT Projects using ESP8266 / ESP12-E**
Real Hardware | MQTT | Node-RED Dashboard | Live Monitoring

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

## 🛠️ Technologies Used

![C++](https://img.shields.io/badge/C++-Arduino-blue?style=flat-square)
![WiFi](https://img.shields.io/badge/WiFi-ESP8266-lightblue?style=flat-square)
![MQTT](https://img.shields.io/badge/MQTT-Protocol-orange?style=flat-square)
![HiveMQ](https://img.shields.io/badge/Broker-HiveMQ-yellow?style=flat-square)
![Node-RED](https://img.shields.io/badge/Node--RED-Flow-red?style=flat-square)
![Dashboard](https://img.shields.io/badge/Dashboard-UI-purple?style=flat-square)
![DHT11](https://img.shields.io/badge/Sensor-DHT11-green?style=flat-square)
![LDR](https://img.shields.io/badge/Sensor-LDR-brown?style=flat-square)

---

## 📁 All Projects

| # | Project Name | Description | Sensors | Status |
|---|-------------|-------------|---------|--------|
| 1 | [IoT Dashboard - DHT11 + LDR](#-project-1--iot-dashboard---dht11--ldr--node-red) | Real-time Temperature, Humidity & Light monitoring with Node-RED Dashboard | DHT11, LDR | ✅ Done |
| 2 | Coming Soon... | Next IoT Project | - | 🔄 |
| 3 | Coming Soon... | Next IoT Project | - | 🔄 |

---

## 🔥 Project 1 — IoT Dashboard - DHT11 + LDR + Node-RED

<div align="center">

![Project Badge](https://img.shields.io/badge/Project-1-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-green?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Tested-orange?style=for-the-badge)

</div>

### 📋 Description
> Real-time IoT monitoring system using ESP12-E (ESP8266) with DHT11 and LDR sensors.
> Data published via MQTT to HiveMQ broker and visualized on Node-RED Dashboard with live Gauges and Charts.

---

### 🔧 Hardware Used

| Component | Purpose |
|-----------|---------|
| ESP12-E (ESP8266) | WiFi microcontroller |
| DHT11 | Temperature & Humidity sensor |
| LDR | Light intensity sensor |
| 10K Resistor | LDR voltage divider |
| Jumper Wires | Connections |

---

### 📌 Pin Connections

| Sensor | Pin | ESP12-E |
|--------|-----|---------|
| DHT11 VCC | Power | 3.3V |
| DHT11 GND | Ground | GND |
| DHT11 DATA | Signal | D2 (GPIO4) |
| LDR Leg 1 | Power | 3.3V |
| LDR Leg 2 | Analog | A0 |
| 10K Resistor | GND side | GND |

---

### 🌐 System Architecture

```
DHT11 + LDR Sensors
        ↓
  ESP12-E (ESP8266)
        ↓ WiFi
  HiveMQ MQTT Broker
        ↓
     Node-RED
        ↓
Live Dashboard (Gauges + Charts)
```

---

### 📡 MQTT Topics

| Topic | Data | Unit |
|-------|------|------|
| `tempNode` | Temperature | °C |
| `humiNode` | Humidity | % |
| `ldrNode` | Light Value | lux |

---

### 📊 Dashboard

**Page 1 — Sensors (Gauges)**

| 🌡️ Temperature | 💧 Humidity | 💡 Light |
|:---:|:---:|:---:|
| Live °C | Live % | Live lux |

**Page 2 — Charts (Live Graphs)**

| 📈 Temp Graph | 📈 Humidity Graph | 📈 Light Graph |
|:---:|:---:|:---:|
| Line Chart | Line Chart | Line Chart |

---

### 🖼️ Images

> Add your images in `1_IoT_Project_DHT11_LDR_Dashboard/Images/` folder
> They will automatically show here!

<!-- Add images below like this:
![Circuit](1_IoT_Project_DHT11_LDR_Dashboard/Images/01_circuit.jpg)
![Dashboard](1_IoT_Project_DHT11_LDR_Dashboard/Images/02_dashboard.jpg)
![Node-RED Flow](1_IoT_Project_DHT11_LDR_Dashboard/Images/03_nodered_flow.jpg)
-->

---

### 🎥 Demo Video

> Add your video link here!

<!-- 
[![Demo Video](thumbnail.jpg)](your_video_link)
-->

---

### 📈 Graphs & Charts

> Add graph screenshots in `1_IoT_Project_DHT11_LDR_Dashboard/Assets/graphs/`

---

### 💻 Code

📄 [View Code](1_IoT_Project_DHT11_LDR_Dashboard/Code/1_iot_project.ino)

---

### 📁 Project Folder Structure

```
1_IoT_Project_DHT11_LDR_Dashboard/
├── README.md
├── Code/
│   └── 1_iot_project.ino
├── Images/
│   ├── 01_circuit.jpg
│   ├── 02_dashboard.jpg
│   └── 03_nodered_flow.jpg
├── Video/
│   └── 01_demo.mp4
├── Schematics/
│   └── circuit_diagram.png
├── NodeRED_Flow/
│   └── flow.json
├── Documents/
│   └── project_details.pdf
└── Assets/
    ├── graphs/
    │   ├── temperature_graph.png
    │   └── humidity_graph.png
    └── charts/
        └── ldr_chart.png
```

---

<div align="center">

### 🔗 Connect With Me

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue?style=for-the-badge&logo=linkedin)](https://linkedin.com/in/ramsudarshanmaurya)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black?style=for-the-badge&logo=github)](https://github.com/Ramsudarshanmaurya)
[![Portfolio](https://img.shields.io/badge/Portfolio-Visit-green?style=for-the-badge)](https://ramsudarshanmaurya.engineer)
[![Email](https://img.shields.io/badge/Email-Contact-red?style=for-the-badge&logo=gmail)](mailto:ramsudarshanmaurya@gmail.com)

**⭐ Star this repo if you found it helpful!**

</div>

---

<div align="center">
Made with ❤️ by Ramsudarshan Maurya
</div>
