# Servo-Motors


# USB-Powered Servo Control with Arduino

This project demonstrates how to safely power and control *4 servo motors* using an *Arduino Uno* and a *cut USB cable* as an external 5V power source. It includes breadboard wiring, servo control code, and important safety precautions.

## 🧰 Components Used

- Arduino Uno (or compatible board)
- 4x Servo motors (e.g., SG90)
- Breadboard
- Jumper wires
- Cut USB cable (for 5V power)
- 5V USB phone charger (minimum 2A output)
- Optional: LED + resistor (for wire testing)

## ⚠️ Important Safety Notes

- *Never connect the USB's +5V line directly to the Arduino 5V pin* — only use it to power the servos via the breadboard.
- Always *connect Arduino GND to the external power GND* to ensure proper signal reference.
- If you're testing USB wires with an LED, *you must use a resistor* to avoid damaging the LED.

## 🔌 USB Cable Color Identification

> USB cable colors vary by manufacturer, but the most common are:

| Color       | Function       |
|-------------|----------------|
| Red or Pink | +5V (Vcc)      |
| Black or White | Ground (GND)  |
| Green       | Data+ (ignore) |
| White or Gray | Data– (ignore) |

If in doubt, use a *multimeter* to verify which pair gives ~5V.

## 🧪 Wiring Overview

USB Charger → Cut USB Cable → Breadboard:
	•	Pink (or red)  → Breadboard + rail
	•	Black (or white) → Breadboard – rail

Servo Motors:
	•	Red wire → Breadboard + rail (power)
	•	Brown/black wire → Breadboard – rail (GND)
	•	Orange/yellow wire → Arduino digital pins (e.g., D3, D5, D6, D9)

Arduino:
	•	GND pin → Breadboard – rail (shared ground)

## 🧠 Arduino Code

```cpp
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  int angles[] = {0, 90, 180};
  for (int i = 0; i < 3; i++) {
    int pos = angles[i];
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    delay(1000);
  }
}

🖼️ Visual Diagram

A labeled breadboard diagram is available in the /images folder.

📁 Folder Structure

.
├── README.md
├── images/
│   └── wiring_diagram.png
├── usb_servo_control.ino

✅ Tested On
	•	Arduino Uno
	•	SG90 servos
	•	5V 2A phone charger
	•	Generic USB cable (pink = 5V, black = GND)

📚 License

MIT License — feel free to use, modify, and share.
