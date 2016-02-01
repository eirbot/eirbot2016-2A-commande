#include <hal/gpio.hpp>
#include <hal/timer.hpp>
#include <hal/pwm.hpp>
#include <hal/uart.hpp>

#include <stream/hal/uart_stream.hpp>


using namespace HAL;
using namespace Stream;

struct MySettings : public DefaultUARTStreamSettings {
    static constexpr auto& uart = SERIAL_USART3;
    static constexpr auto& tx = B10;
    static constexpr auto& rx = B11;

    static constexpr auto baudrate = 9600;
    static constexpr auto parity = UART::Parity::NONE;
    static constexpr auto stop_bit = UART::StopBit::ONE_BIT;
    static constexpr auto word_size = 8;
};

Stream::FormattedUARTStream<MySettings> io;

int main(int, char**) {
//    auto& myuart1 = SERIAL_USART3;

//    UART::Settings settings;
//      settings.baudrate=9600;
//      settings.parity=UART::Parity::NONE;
//      settings.stop_bit=UART::StopBit::ONE_BIT;
//      settings.word_size=8;


//      UART::init(myuart1,B10,B11,settings);


     TIMER::Settings timer9_settings;
     timer9_settings.period = 10000; //us
     TIMER::init(TIMER9, timer9_settings);
//    //  TIMER::init(TIMER12, timer9_settings);

//      PWM::Settings pwm1_settings;
//      pwm1_settings.polarity = PWM::Polarity::HIGH;
//      PWM::init(TIMER9_CH2, E6, pwm1_settings);

    //  PWM::Settings pwm2_settings;
    //  pwm2_settings.polarity = PWM::Polarity::LOW;
    //  PWM::init(TIMER12_CH2, B15, pwm2_settings);


  GPIO::Settings settings;
  settings.mode = GPIO::Mode::OUTPUT;
  settings.output_mode = GPIO::OutputMode::PUSH_PULL;
  settings.pull = GPIO::Pull::DOWN;


  // TIMER::Settings timer_settings;
  // timer_settings.period = 5000;
  // TIMER::init(TIMER2,timer_settings);
  // TIMER::start(TIMER2);



   GPIO::init(D7,settings);
  //  GPIO::init(B15,settings);

  //TIMER::start(TIMER12);
  //PWM::setPulseWidth(TIMER12_CH2, 10);
  


  TIMER::start(TIMER9);
//  PWM::setPulseWidth(TIMER9_CH2, 1000);
  

   // TIMER::setOverflowHandler(TIMER2,[](){
   //  GPIO::toggle(D7);



   // });

   while(1) {
       GPIO::toggle(D7);
       auto& timer_handle = Private::get_timer_cube_handle<9>();
       u32 var = __HAL_TIM_GetCounter(&timer_handle);
       io << var << "\n\r";
   }
    //   UART::write(myuart1, (u8*)"Hello\n\r", 7);

  return 0;
 
}
