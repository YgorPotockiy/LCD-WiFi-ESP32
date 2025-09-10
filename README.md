# ESP32 I2C LCD1602 WebServer Control

## 📖 Description
This project demonstrates how to control an **I2C LCD1602 display** using an **ESP32** through a built-in **web server**.  
It allows you to send text directly from your browser and display it on the LCD over Wi-Fi.

## ⚡ Features
- Control LCD1602 via Wi-Fi web interface  
- Display custom text entered from the browser  
- Easy-to-use and extendable codebase  
- Compatible with PlatformIO and Arduino IDE  

## 🛠️ Requirements
- **ESP32 development board**  
- **LCD1602 with I2C adapter**  
- Arduino libraries:
  - `Wire.h`  
  - `LiquidCrystal_I2C.h`  
  - `WiFi.h`  
  - `WebServer.h`  

## 🔌 Wiring
| LCD1602 (I2C) | ESP32 Pin |
|---------------|-----------|
| SDA           | GPIO21    |
| SCL           | GPIO22    |
| VCC           | 3.3V / 5V |
| GND           | GND       |

