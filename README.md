<img width="603" height="336" alt="image" src="https://github.com/user-attachments/assets/2c04f1cb-6b10-42bb-8c0a-9b61ac2afdc3" /># EDGE-TO-CLOUD-HEAT-MONITORING-FOR-INDUSTRIAL-ENVIRONMENTS
Here is a **340-character** GitHub description:  IoT-based industrial monitoring system using LPC2148 to track temperature and gas/smoke levels in real time. Uses LM35, MQ-2, LCD, buzzer, and ESP-01 Wi-Fi for alerts and cloud logging via ThingSpeak, enabling remote monitoring, safety alerts, and efficient industrial automation.

# Edge-to-Cloud Heat Monitoring for Industrial Environments

## Overview
This project is an IoT-based industrial monitoring system that continuously monitors temperature and gas/smoke levels in industrial environments. It helps improve safety by detecting abnormal conditions and sending alerts in real time.

The system uses an LPC2148 microcontroller to collect sensor data, process it, and upload it to the cloud for remote monitoring.

---

## Features
- Real-time temperature monitoring
- Gas/Smoke detection
- LCD display for live sensor values
- Buzzer alert during hazardous conditions
- Cloud data logging using ThingSpeak
- Remote monitoring through mobile/PC
- Periodic updates using RTC

---

## Hardware Requirements
- LPC2148 Microcontroller
- LM35 Temperature Sensor
- MQ-2 Gas/Smoke Sensor
- 16x2 LCD
- Buzzer
- ESP-01 Wi-Fi Module
- USB-UART / DB9 Cable

---

## Software Requirements
- Keil uVision
- Embedded C
- Flash Magic

---

## Working
1. LM35 reads surrounding temperature.
2. MQ-2 detects gas/smoke.
3. LPC2148 processes sensor data using ADC.
4. Sensor values are displayed on LCD.
5. If gas/smoke is detected, buzzer turns ON.
6. ESP-01 sends data to ThingSpeak cloud using UART.
7. Data can be monitored remotely from mobile or PC.

---

## Block Diagram
                 +----------------+
                 |      LM35      |
                 | Temp Sensor    |
                 +--------+-------+
                          |
                          v
                 +----------------+
                 |      ADC       |
                 +--------+-------+
                          |
                          |
+---------------+         v          +----------------+
| MQ-2 Gas/Smoke|------->+-----------|    LPC2148     |
|    Sensor     |        |           | ARM7 Controller|
+---------------+        |           +---+--------+---+
                         |               |        |
                         |               |        |
                         v               v        v
                 +-------------+   +---------+ +---------+
                 |   RTC       |   |  LCD    | | Buzzer  |
                 | Time Control|   | Display | | / LED   |
                 +-------------+   +---------+ +---------+
                                             |
                                             v
                                      +-------------+
                                      |   ESP-01    |
                                      | Wi-Fi Module|
                                      +------+------+
                                             |
                                             v
                                      +-------------+
                                      | ThingSpeak  |
                                      |    Cloud    |
                                      +------+------+
                                             |
                                             v
                                      +-------------+
                                      | Mobile / PC |
                                      | Monitoring  |
                                      +-------------+


---

## Applications
- Industrial safety monitoring
- Fire prevention systems
- Factory automation
- Smart environment monitoring

---

## Technologies Used
- Embedded C
- ARM7 (LPC2148)
- ADC
- UART Communication
- IoT
- Cloud Integration

---

## Author
**Mallela Vishnu Teja**  
Embedded Systems Developer
