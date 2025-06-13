# 🌿 Automatic Plant Irrigation System with Ultrasonic and Temperature Sensors

This Arduino-based system automates plant irrigation by monitoring the **water level** in a tank and the **soil temperature** using analog and ultrasonic sensors. The system intelligently activates relays to control irrigation devices. If water is insufficient, it alerts the user via buzzer and blinking LED. An **IR sensor interrupt** provides emergency shutdown functionality.

---

## 🔧 Components Used

- Arduino Uno (or compatible)
- HC-SR04 Ultrasonic Distance Sensor
- 3 Analog Temperature Sensors (e.g., LM35)
- Yellow LED
- Buzzer
- 3 Relays
- IR Sensor (for emergency interrupt)
- Jumper wires and optional resistors

---

## 🖥️ Pin Configuration

| Component               | Arduino Pin |
|-------------------------|-------------|
| IR Emergency Sensor     | D3          |
| Water Level Sensor      | A0          |
| Temperature Sensor 1    | A1          |
| Temperature Sensor 2    | A5          |
| Temperature Sensor 3    | A3          |
| Yellow LED              | D8          |
| Buzzer                  | D12         |
| Relay 1                 | D4          |
| Relay 2                 | D6          |
| Relay 3                 | D7          |
| Ultrasonic Sensor       | Trigger: D11, Echo: D10 |

---

## 🧠 System Logic

- The **ultrasonic sensor** measures distance to check tank fill level.
- If **distance < 12 cm** and **ToF > 0.3 ms**, the system:
  - Reads 3 temperature sensors.
  - Activates irrigation relays based on temperature thresholds and time logic.
- If the **tank is empty**:
  - Disables all relays
  - Triggers alerts via buzzer and LED
- An **IR sensor** provides emergency shutdown by triggering an interrupt.
- A **debug mode** can print all sensor values via Serial Monitor.

---

## 🔄 Changelog (v5.0.0)

- 🧠 Added `rele_control` lambda function for smart relay control
- 🆕 Introduced analog water level reading via `WATER_LEVEL` (A0)
- ⏱️ Time-based logic using `millis()` for activation delays
- 🚨 Integrated IR sensor interrupt for emergency stop
- 🔔 Improved audio-visual feedback when tank is empty
- 🐞 Debug mode enabled via `#define DEBUG_LEVEL`

---

## 🐞 Debug Mode

To enable serial debug output:

```cpp
#define DEBUG_LEVEL 1
