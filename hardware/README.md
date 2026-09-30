# Hardware

## 📌 Overview

This folder contains the hardware components and hardware-related documentation used in the **Smart Irrigation Monitoring System**.

The system combines sensors, an ESP32 controller, relay module, water pump, LCD display and LED indicators to monitor soil conditions and control irrigation.

---

## 🔧 Main Components

| No. | Component | Function |
|---:|---|---|
| 1 | ESP32 Wi-Fi Module | Main controller and IoT communication |
| 2 | Soil Moisture Sensor | Measures soil moisture |
| 3 | DHT11/DHT22 | Measures temperature and humidity |
| 4 | Relay Module | Controls the water pump |
| 5 | 12V DC Water Pump | Supplies water for irrigation |
| 6 | 16×2 LCD | Displays sensor and pump information |
| 7 | Green LED | Indicates sufficient soil moisture |
| 8 | Red LED | Indicates low soil moisture |
| 9 | Power Supply | Provides electrical power |
| 10 | Connecting Wires | Connects system components |
| 11 | Pipes / Drip Tubes | Carries water to the irrigation area |
| 12 | Enclosure | Protects the electronic components |

---

## ⚙️ Hardware Operation

The soil moisture sensor monitors the condition of the soil and sends the reading to the ESP32.

The ESP32 processes the sensor information and controls the relay.

```text
Soil Moisture Sensor
        ↓
      ESP32
        ↓
   Relay Module
        ↓
    Water Pump
