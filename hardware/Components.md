# Hardware Components

## 📌 Overview

This file provides detailed information about the hardware components used in the **Smart Irrigation Monitoring System**.

---

## 🔧 Components

| No. | Component | Specification | Function |
|---:|---|---|---|
| 1 | ESP32 Wi-Fi Module | Dual-core, Wi-Fi & Bluetooth | Main controller and IoT communication |
| 2 | Soil Moisture Sensor | Analog output, 3.3V/5V | Measures soil moisture |
| 3 | DHT11/DHT22 | Digital, 3.3V/5V | Measures temperature and humidity |
| 4 | Relay Module | 5V, 10A | Controls the water pump |
| 5 | Water Pump | 12V DC, 3–5 L/min | Supplies water for irrigation |
| 6 | 16×2 LCD | 5V, I2C | Displays system information |
| 7 | Green LED | 2–3V | Indicates sufficient moisture |
| 8 | Red LED | 2–3V | Indicates low moisture |
| 9 | Power Supply | 12V Adapter/Battery | Provides electrical power |
| 10 | Connecting Wires | Jumper wires | Provides electrical connections |
| 11 | Pipes / Drip Tubes | — | Carries water to the irrigation area |
| 12 | Enclosure | — | Protects electronic components |

---

## 1. ESP32 Wi-Fi Module

The ESP32 is the main control unit of the system.

It receives information from the sensors, processes the data, controls the relay and communicates with the Blynk IoT platform through Wi-Fi.

### Main Features

- Dual-core processor
- Wi-Fi connectivity
- Bluetooth connectivity
- GPIO
- ADC
- I2C
- SPI
- UART

---

## 2. Soil Moisture Sensor

The soil moisture sensor is used to measure the moisture condition of the soil.

The sensor provides an analog signal to the ESP32.

The moisture reading is used by the system to determine whether irrigation is required.

---

## 3. DHT11 / DHT22

The DHT sensor measures:

- Temperature
- Relative humidity

The sensor provides digital data to the ESP32.

The measured values can be displayed on the LCD and transmitted to Blynk.

---

## 4. Relay Module

The relay module works as an electrically controlled switch.

The ESP32 controls the relay, while the relay controls the water pump.

This allows the ESP32 to control the 12V DC pump.

---

## 5. Water Pump

A 12V DC water pump is used to supply water to the irrigation area.

The pump is controlled through the relay module.

### Pump Operation

```text
Low Soil Moisture
       ↓
    Relay ON
       ↓
    Pump ON
       ↓
 Water Irrigation
