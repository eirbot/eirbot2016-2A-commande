
#include <hal/stm32cubef4/gpio.hpp>
#include <hal/stm32cubef4/timer.hpp>

using namespace HAL::STM32CubeF4;


int main(void){
  GPIO::Settings settings;
  settings.mode = GPIO::Mode::OUTPUT;
  // TIMER::Settings timer_settings;
  // timer_settings.period = 1000000;
  // TIMER::init(TIMER1,timer_settings);
  GPIO::init(D6,settings);
  GPIO::init(D7,settings);
  GPIO::init(G9,settings);
  GPIO::init(G10,settings);
  GPIO::init(G11,settings);
  GPIO::init(G12,settings);
  GPIO::init(G13,settings);
  GPIO::init(G14,settings);
  
  
  // TIMER::setOverflowHandler(TIMER1,[]()
  while(1){
       static int i = 0;
       i++;
       if (i==1)
	   GPIO::toggle(D6);
       if (i==2)
	 {
	   GPIO::toggle(D6);
	   GPIO::toggle(D7);
	 }
       if (i==3)
	 {
	   GPIO::toggle(D7);
	   GPIO::toggle(G9);
	 }
       if (i==4)
	 {
	   GPIO::toggle(G9);
	   GPIO::toggle(G10);
	 }
       if (i==5)
	 {
	   GPIO::toggle(G10);
	   GPIO::toggle(G11);
	 }
       if (i==6)
	 {
	   GPIO::toggle(G11);
	   GPIO::toggle(G12);
	 }
       if (i==7)
	 {
	   GPIO::toggle(G12);
	   GPIO::toggle(G13);
	 }
       if (i==8)
	 {
	   GPIO::toggle(G13);
	   GPIO::toggle(G14);
	 }
       if (i==10)
	 {
	   GPIO::toggle(G14);
	   GPIO::toggle(G13);
	 }
       if (i==11)
	 {
	   GPIO::toggle(G13);
	   GPIO::toggle(G12);
	 }
       if (i==12)
	 {
	   GPIO::toggle(G12);
	   GPIO::toggle(G11);
	 }
       if (i==13)
	 {
	   GPIO::toggle(G11);
	   GPIO::toggle(G10);
	 }
       if (i==14)
	 {
	   GPIO::toggle(G10);
	   GPIO::toggle(G9);
	 }
       if (i==15)
	 {
	   GPIO::toggle(G9);
	   GPIO::toggle(D7);
	 }
       if (i==16)
	 {
	   GPIO::toggle(D7);
	   GPIO::toggle(D6);
	 }
       if (i==17)
	 {
	   GPIO::toggle(D6);
	   i=0;
	 }

       for (int h=0; h<10000000; h++)
	 ;
    };
  
  while(1);
  return 0;
}
