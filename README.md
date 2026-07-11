# IoT-Based Earthquake Monitoring System

## Overview

This project is an IoT-based Earthquake Monitoring System developed using Arduino. It continuously monitors vibration, temperature, and humidity levels to identify abnormal conditions that may indicate seismic activity. When unusual vibrations are detected, the system sends an instant alert through Telegram, enabling quick notification and response.

## Features

- Real-time vibration monitoring
- Temperature and humidity sensing
- Instant Telegram notifications
- Arduino-based implementation
- Simple and cost-effective design

## Components Used

- Arduino Board
- Vibration Sensor
- DHT11 Temperature and Humidity Sensor
- ESP8266 Wi-Fi Module
- Breadboard
- Jumper Wires

## Software Used

- Arduino IDE
- Telegram Bot API

## Working Principle

1. The vibration sensor continuously monitors ground vibrations.
2. The DHT11 sensor measures temperature and humidity.
3. The Arduino processes sensor readings in real time.
4. If the vibration level exceeds the predefined threshold, the system triggers an alert.
5. A notification is immediately sent to the user through Telegram.

## Project Structure

```
IoT-Earthquake-monitoring-system/
│
├── EarthquakeMonitoring.ino
├── README.md
└── Images/
```

## Future Enhancements

- GPS-based location tracking
- Mobile application integration
- Cloud data storage and analytics
- Improved seismic event classification

## Author

**Thandeeswaran M**

Electronics and Communication Engineering  
Rajalakshmi Engineering College
