# Smart Parking Slot Monitoring System (IoT)

This project implements an IoT-based smart parking slot monitoring system using an ESP8266 microcontroller, an ultrasonic sensor, and the Blynk IoT platform. The system detects whether a parking slot is occupied or free and displays the status on the Blynk mobile application in real time.

---

## Features
- Real-time parking slot status monitoring
- Ultrasonic sensor-based distance measurement
- Wi-Fi connectivity using ESP8266
- Live status updates on Blynk IoT app
- Serial monitor debugging support

---

## Components Used
- ESP8266 (NodeMCU)
- Ultrasonic Sensor (HC-SR04)
- Jumper wires
- Wi-Fi network
- Blynk IoT mobile application

---

## Hardware Connections

| Ultrasonic Sensor Pin | ESP8266 Pin |
|----------------------|-------------|
| TRIG                 | D4          |
| ECHO                 | D6          |
| VCC                  | 3.3V / 5V   |
| GND                  | GND         |

---

## Software & Tools
- Arduino IDE
- ESP8266 Board Package
- Blynk IoT Platform
- Git & GitHub

---

## Working Principle
The ultrasonic sensor measures the distance between the sensor and an object (vehicle).  
If the measured distance is less than a predefined threshold, the parking slot is considered **occupied**; otherwise, it is marked as **free**.  
The slot status is sent to the Blynk IoT platform via Wi-Fi and displayed on the mobile application.

---

## Code Overview
- Wi-Fi connection is established using ESP8266WiFi library
- Blynk library is used to communicate with the Blynk cloud
- Distance is calculated using ultrasonic sensor pulse timing
- Slot status is sent to Blynk using a virtual pin

---

## Output
- Serial Monitor displays slot status
- Blynk app shows:
  - "Slot 3: occupied"  
  - "Slot 3: free"

---

## Future Improvements
- Add multiple parking slots
- Integrate cloud database
- Add mobile notifications
- Use IR sensors for higher accuracy

---

## Author
Ishaan Arora

---

## License
This project is for academic and learning purposes.
