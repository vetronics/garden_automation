# 🌿 Automatic Plant Irrigation System with Ultrasonic and Temperature Sensors

This Arduino-based system automates plant irrigation by monitoring the **water level** in a tank and the **soil temperature**. When sufficient water is available and soil conditions are suitable, the system activates relays to control irrigation pumps or valves. A buzzer and LED signal alert if the water tank is empty.

## 🔧 Components Used

- Arduino Uno (or compatible)
- HC-SR04 Ultrasonic Distance Sensor
- 3 Analog Temperature Sensors (e.g., LM35)
- Yellow LED
- Buzzer
- 3 Relays
- Jumper wires and optional resistors

## 🖥️ Pin Configuration

| Component              | Arduino Pin |
|------------------------|-------------|
| Ultrasonic Sensor      | Trigger: 2, Echo: 3 |
| Temperature Sensor 1   | A1          |
| Temperature Sensor 2   | A5          |
| Temperature Sensor 3   | A3          |
| Yellow LED             | 8           |
| Buzzer                 | 12          |
| Relay 1                | 6           |
| Relay 2                | 7           |
| Relay 3                | 4           |

## 🧠 System Logic

- The **ultrasonic sensor** checks the distance to the water surface.
- If water level is **sufficient** (distance < 12 cm and time of flight > 0.3 ms):
  - Temperature values from the 3 sensors are read and processed.
  - Relays are toggled to activate irrigation devices based on temperature.
- If the tank is **empty**, the system alerts the user via blinking LED and buzzer.
- An **emergency interrupt** disables all relays.


