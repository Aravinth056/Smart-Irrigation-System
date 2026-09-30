# Software

## 📌 Overview

This folder contains the software and programming documentation for the **Smart Irrigation Monitoring System**.

The system uses an **ESP32** microcontroller programmed using the **Arduino IDE**.

---

## 💻 Software Used

- Arduino IDE
- ESP32 Board Package
- Blynk IoT Platform

---

## ⚙️ Software Functions

The program performs the following functions:

- Reads soil moisture data
- Reads temperature and humidity
- Processes sensor readings using ESP32
- Controls the water pump through a relay
- Controls red and green LED indicators
- Displays information on the 16×2 LCD
- Sends sensor data to Blynk
- Allows remote monitoring through Blynk
- Supports manual pump control through Blynk

---

## 🔄 Control Logic

```text
Read Soil Moisture
        ↓
Read Temperature & Humidity
        ↓
     ESP32
        ↓
Check Irrigation Condition
        ↓
 ┌───────────────┐
 │               │
Low Moisture   Sufficient Moisture
 │               │
 ↓               ↓
Pump ON        Pump OFF
Red LED ON     Green LED ON
