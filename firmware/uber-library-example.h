#ifndef _UBER_LIBRARY_EXAMPLE
#define _UBER_LIBRARY_EXAMPLE

#if SPARK_WIRING_H
#include "application.h"
#endif

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
