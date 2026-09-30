# Methodology

## 📌 Overview

The Smart Irrigation Monitoring System was developed by integrating sensors, an ESP32 controller, a relay module, a water pump, an LCD display, LED indicators, and the Blynk IoT platform.

---

## 🔧 Methodology

### 1. Component Selection

The required hardware components were selected based on the requirements of the irrigation system.

Main components include:

- ESP32 Wi-Fi Module
- Soil Moisture Sensor
- DHT11/DHT22 Sensor
- Relay Module
- 12V DC Water Pump
- 16×2 LCD
- Red LED
- Green LED
- Power Supply
- Connecting Wires
- Pipes / Drip Tubes

---

### 2. Hardware Assembly

The components were connected according to the system design.

The soil moisture sensor and DHT sensor were connected to the ESP32.

The relay module was connected between the ESP32 and water pump for pump control.

The LCD and LED indicators were connected to display system status.

---

### 3. Sensor Monitoring

The soil moisture sensor continuously monitors the moisture condition of the soil.

The DHT sensor measures:

- Temperature
- Humidity

The sensor values are processed by the ESP32.

---

### 4. Irrigation Control

The ESP32 processes the sensor readings and determines the irrigation condition.

```text
Low Soil Moisture
        ↓
    Relay ON
        ↓
    Pump ON
