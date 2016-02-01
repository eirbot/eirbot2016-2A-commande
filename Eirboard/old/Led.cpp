
#include <hal/stm32cubef4/gpio.hpp>


using namespace HAL::STM32CubeF4;


int main(void){
  GPIO::Settings settings;
  settings.mode = GPIO::Mode::OUTPUT;
  //TIMER::Settings timer_settings;
  //timer_settings.period = 10000;
  //TIMER::init(TIMER2,timer_settings);
  GPIO::init(D12,settings);
  GPIO::setValue(D12,true);
  //  TIMER::start(TIMER2);
  
  // TIMER::setOverflowHandler(TIMER2,[](){

  //	   GPIO::toggle(D6);

  //   });
  
  while(1);
  return 0;
}
