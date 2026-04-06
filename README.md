# 🚗 Arduino Speed Detector using Ultrasonic Sensors

This project measures the speed of a moving object using two ultrasonic sensors and an Arduino. If the object exceeds a predefined speed limit, a buzzer is triggered.

---

## 📌 Features
- Measures speed using time difference between two sensors
- Real-time output via Serial Monitor
- Buzzer alert when speed exceeds threshold
- Simple and cost-effective setup

---

## 🧠 How It Works
1. The object passes **Sensor 1** → Timer starts  
2. The object passes **Sensor 2** → Timer stops  
3. Speed is calculated using: Speed = Distance / Time
4. If speed > limit → buzzer activates  

---

## ⚙️ Components Required
- Arduino Uno
- 2 × Ultrasonic Sensors (HC-SR04)
- Buzzer
- Jumper wires
- Breadboard

---

## 🔌 Circuit Connections

| Component | Arduino Pin |
|----------|------------|
| Trig 1   | 2          |
| Echo 1   | 3          |
| Trig 2   | 4          |
| Echo 2   | 5          |
| Buzzer   | 6          |

---

## 📏 Configuration
- Distance between sensors: **0.20 meters (20 cm)**
- Speed limit: **2.0 m/s**
