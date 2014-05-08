#ifndef _UBER_LIBRARY_EXAMPLE
#define _UBER_LIBRARY_EXAMPLE

// NOTE/TODO: We don't want to do this; would be nice if it were conditional
#include "application.h"

namespace UberLibraryExample
{
  class Pin
  {
    private:
      int number;
      int mode;
      bool state;
    public:
      Pin(int _number);
      void beginInPinMode(PinMode _pinMode);
      void modulateAtFrequency(int _ms);
      int getNumber();
      bool getState();
      bool getMode();
      bool isHigh();
      void setHigh();
      void setLow();
      void setActualPinState();
  };
}

#endif
