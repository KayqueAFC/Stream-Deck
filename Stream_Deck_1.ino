
#include <Keyboard.h>

const uint8_t buttons[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
const uint8_t keys[] = {
  KEY_F13, KEY_F14, KEY_F15,
  KEY_F16, KEY_F17, KEY_F18,
  KEY_F19, KEY_F20, KEY_F21
};

const int NUM_BUTTONS = 9;

void setup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      Keyboard.press(keys[i]);
    } else {
      Keyboard.release(keys[i]);
    }
  }
}

