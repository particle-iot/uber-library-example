#include "uber-library-example.cpp"
UberLibraryExample::Pin outputPin(D7);

void setup() {
  outputPin.beginInPinMode(OUTPUT);
}

void loop() {
  // TODO: If mode button is pressed, set output pin high
  outputPin.setHigh();
}
