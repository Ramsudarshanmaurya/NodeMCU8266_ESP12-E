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

## 🛠️ Technologies Used

![C++](https://img.shields.io/badge/C++-Arduino-blue?style=flat-square)
![WiFi](https://img.shields.io/badge/WiFi-ESP8266-lightblue?style=flat-square)
![MQTT](https://img.shields.io/badge/MQTT-Protocol-orange?style=flat-square)
![HiveMQ](https://img.shields.io/badge/Broker-HiveMQ-yellow?style=flat-square)
![Node-RED](https://img.shields.io/badge/Node--RED-Flow-red?style=flat-square)
![Dashboard](https://img.shields.io/badge/Dashboard-UI-purple?style=flat-square)
![DHT11](https://img.shields.io/badge/Sensor-DHT11-green?style=flat-square)
![LDR](https://img.shields.io/badge/Sensor-LDR-brown?style=flat-square)
![MQ135](https://img.shields.io/badge/Sensor-MQ135-orange?style=flat-square)
![HC-SR04](https://img.shields.io/badge/Sensor-HC--SR04-purple?style=flat-square)
![OLED](https://img.shields.io/badge/Display-OLED-white?style=flat-square)

---

## 📁 All Projects

| # | Project Name | Description | Sensors | Status |
|---|-------------|-------------|---------|--------|
| 1 | [IoT Dashboard - DHT11 + LDR](1_IoT_Project_DHT11_LDR_Dashboard/README.md) | Real-time Temperature, Humidity & Light monitoring with Node-RED Dashboard | DHT11, LDR | ✅ Done |
| 2 | [IoT Dashboard - DHT11 + LDR + MQ135 + Ultrasonic + OLED](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/README.md) | Advanced monitoring with Air Quality, Distance, OLED Display & LED Control | DHT11, LDR, MQ135, HC-SR04, OLED | ✅ Done |
| 3 | Coming Soon... | Next IoT Project | - | 🔄 |

---

## 🔥 Project 1 — IoT Dashboard - DHT11 + LDR + Node-RED

<div align="center">

![Project Badge](https://img.shields.io/badge/Project-1-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-green?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Tested-orange?style=for-the-badge)

</div>

> Real-time IoT monitoring system using **ESP12-E (ESP8266)** with **DHT11** and **LDR** sensors.
> Data published via **MQTT** to **HiveMQ** broker and visualized on **Node-RED Dashboard** with live Gauges and Charts.

| Hardware | Protocol | Platform | Dashboard |
|:---:|:---:|:---:|:---:|
| ESP12-E + DHT11 + LDR | MQTT / HiveMQ | Node-RED | Gauges + Charts |

### 🖼️ Preview

| | | |
|:---:|:---:|:---:|
| ![Circuit](1_IoT_Project_DHT11_LDR_Dashboard/Images/image1.jpg) | ![Dashboard](1_IoT_Project_DHT11_LDR_Dashboard/Images/image2.png) | ![Flow](1_IoT_Project_DHT11_LDR_Dashboard/Images/image3.png) |
| Circuit Diagram | Dashboard View | Node-RED Flow |
| ![Serial](1_IoT_Project_DHT11_LDR_Dashboard/Images/image4.png) | ![Gauge](1_IoT_Project_DHT11_LDR_Dashboard/Images/image5.png) | |
| Serial Monitor | Gauge View | |

📄 [View Full Project →](1_IoT_Project_DHT11_LDR_Dashboard/README.md)

---

## 🔥 Project 2 — IoT Dashboard - DHT11 + LDR + MQ135 + Ultrasonic + OLED + LED Control

<div align="center">

![Project Badge](https://img.shields.io/badge/Project-2-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-green?style=for-the-badge)
![Hardware](https://img.shields.io/badge/Hardware-Tested-orange?style=for-the-badge)

</div>

> Advanced IoT monitoring system using **ESP12-E (ESP8266)** with **DHT11**, **LDR**, **MQ135**, **HC-SR04 Ultrasonic** sensors and **SSD1306 OLED Display**.
> OLED shows real-time sensor data and **"!! ALERT !!"** when object detected within **15cm**.
> **LED1** auto-triggers at 15cm. **LED2** controlled via **Node-RED Dashboard Switch**.

| Hardware | Protocol | Platform | Dashboard |
|:---:|:---:|:---:|:---:|
| ESP12-E + DHT11 + LDR + MQ135 + HC-SR04 + OLED | MQTT / HiveMQ | Node-RED | Gauges + Charts + Switch |

### 🖼️ Preview

| | | |
|:---:|:---:|:---:|
| ![Circuit](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image1.jpeg) | ![Dashboard](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image2.png) | ![Flow](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image3.png) |
| Circuit Diagram | Dashboard View | Node-RED Flow |
| ![Serial](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image4.png) | ![OLED](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image5.png) | ![Chart](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/images/image6.png) |
| Serial Monitor | OLED Display | Chart View |

📄 [View Full Project →](2_IoT_Project_DHT11_LDR_MQ135_Ultrasonic_OLED/README.md)

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
