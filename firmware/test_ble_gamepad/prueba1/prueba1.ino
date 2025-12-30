#include <BleGamepad.h>

BleGamepad gamepad(
  "ESP32-DOIT-TEST",
  "DOIT",
  100
);

unsigned long lastMove = 0;
bool state = false;

void setup() {
  gamepad.begin();
}

void loop() {
  if (!gamepad.isConnected()) return;

  if (millis() - lastMove > 800) {
    lastMove = millis();
    state = !state;

    if (state) {
      gamepad.setAxes(
        0,      // X
        20000,  // Y
        0,      // Z
        0,      // RX
        0,      // RY
        0,      // RZ
        0,      // Slider 1
        0       // Slider 2
      );
    } else {
      gamepad.setAxes(0, 0, 0, 0, 0, 0, 0, 0);
    }
  }
}
