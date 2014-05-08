// NOTE: This is janky; someone with a solid idea of how this should work should rock it!
//
//
// gnu c string lib
#include <iostream>


// Stubs from Spark land
#define HIGH 0x1
#define LOW 0x0
#define D7 7
#define OUTPUT 1
#define INPUT 0

// TODO This should instead include the library here instead of copy and pasting it
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
        mode = _pinMode;
      }
  };
}


// TODO: This main file should run tests and spit out strings in the tap format
// http://en.wikipedia.org/wiki/Test_Anything_Protocol
//
// A better approach would be to define functions for each test and then call them inside main
int main(){
  UberLibraryExample::Pin pin(D7);
  std::cout << "# STARTING STATE"<< std::endl;
  std::cout << "# pin.number=" << pin.getNumber() << std::endl;
  std::cout << "# pin.state=" << pin.getState() << std::endl;
  std::cout << "# pin.mode=" << pin.getMode() << std::endl;
  if (pin.isHigh()) {
    std::cout << "ok: led is high" << std::endl;
  } else {
    std::cout << "ok: led is low" << std::endl;
  }

  std::cout << "# AFTER CHANGING STATE"<< std::endl;
  pin.setHigh();
  std::cout << "# pin.state=" << pin.getState() << std::endl;
  if (pin.isHigh()) {
    std::cout << "ok: led is high" << std::endl;
  } else {
    std::cout << "ok: led is low" << std::endl;
  }

  return 0;
}
