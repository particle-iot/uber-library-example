// IMPORTANT: When including a library in a firmware app, brackets are needed.
#include <uber-library-example.h>

UberLibraryExample::Pin outputPin(D7);
void setup() {
  outputPin.beginInPinMode(OUTPUT);
}

void loop() {
  outputPin.modulateAtFrequency(3000);
}
