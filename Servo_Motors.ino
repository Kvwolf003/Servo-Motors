#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int pos = 0;
unsigned long startTime;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  startTime = millis();
}

void loop() {
  // Run the sweep for 2 seconds
  if (millis() - startTime <= 2000) {
    for (pos = 0; pos <= 180; pos += 5) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 5) {
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(15);
    }
  } else {
    // Hold all motors at 90 degrees
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    // Do nothing afterwards
    while (true);
  }
}