// NOTE: This is janky, work in progressss.
//
#include <iostream>
#define HIGH 0x1
#define LOW 0x0
#define D7 7
#define OUTPUT 1
#define INPUT 0
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

int main(){
  UberLibraryExample::Pin pin(D7);
  std::cout << "STARTING STATE"<< std::endl;
  std::cout << "pin.number=" << pin.getNumber() << std::endl;
  std::cout << "pin.state=" << pin.getState() << std::endl;
  std::cout << "pin.mode=" << pin.getMode() << std::endl;
  if (pin.isHigh()) {
    std::cout << "led is high" << std::endl;
  } else {
    std::cout << "led is low" << std::endl;
  }

  std::cout << "AFTER CHANGING STATE"<< std::endl;
  pin.setHigh();
  std::cout << "pin.state=" << pin.getState() << std::endl;
  if (pin.isHigh()) {
    std::cout << "led is high" << std::endl;
  } else {
    std::cout << "led is low" << std::endl;
  }

  return 0;
}


