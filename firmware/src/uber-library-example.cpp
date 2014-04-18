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
      // Constructor
      Pin(int _number)
      {
        number = _number;
        state = LOW;
      }
      // Getters
      int getNumber()
      {
        return number;
      }
      bool getState() {
        return state;
      }
      bool getMode() {
        return mode;
      }
      bool isHigh()
      {
        return state == HIGH ? true : false;
      }

      // Setters
      void setHigh()
      {
        state = HIGH;
      }
      void setLow()
      {
        state = LOW;
      }
      void beginInPinMode(int _pinMode)
      {
        // TODO: What type is _pinMode
      }
  };
}

