# SMART IRRIGATION MONITORING SYSTEM

## 📌 Project Overview

The **Smart Irrigation Monitoring System** is an IoT-based automated irrigation system developed to monitor soil moisture, temperature, and humidity and control irrigation automatically.

The system uses an **ESP32 microcontroller**, soil moisture sensor, temperature and humidity sensor, relay module, water pump, LCD display, LEDs, and the **Blynk IoT platform**.

When the soil moisture level becomes low, the ESP32 activates the relay and water pump. When sufficient moisture is reached, the pump is automatically switched OFF.

The system also provides remote monitoring and control through the Blynk mobile/web platform.

---

## 🎯 Objectives

- Monitor soil moisture continuously.
- Measure temperature and humidity.
- Automatically control the irrigation pump.
- Reduce unnecessary water usage.
- Reduce manual irrigation work.
- Display sensor information on an LCD.
- Provide remote monitoring using Blynk.
- Support sustainable and efficient irrigation.

---

## ⚙️ Main Components

| Component | Purpose |
|---|---|
| ESP32 | Main controller and Wi-Fi communication |
| Soil Moisture Sensor | Measures soil moisture |
| DHT11/DHT22 | Measures temperature and humidity |
| Relay Module | Controls the water pump |
| 12V DC Water Pump | Supplies water to the plants |
| 16×2 LCD | Displays sensor and pump status |
| Green LED | Indicates sufficient moisture |
| Red LED | Indicates low moisture |
| Power Supply | Provides electrical power |
| Connecting Wires | Electrical connections |
| Blynk | IoT monitoring and remote control |
| Arduino IDE | Programming environment |

---

## 🔄 Working Principle

The soil moisture sensor is placed in the soil near the plant root area.

The sensor continuously provides moisture information to the ESP32.

### When the soil is dry:

```text
Soil Moisture Low
       ↓
     ESP32
       ↓
   Decision Logic
       ↓
     Relay ON
       ↓
   Pump ON
       ↓
   Water Supply
