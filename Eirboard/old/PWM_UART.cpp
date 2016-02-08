/*****************************************************/
/*                Nucleo Architecture                */
/*                    STM32F429ZI                    */
/*                                                   */
/*****************************************************/

#include <hal/gpio.hpp>
#include <hal/timer.hpp>
#include <hal/pwm.hpp>
#include <hal/uart.hpp>

#define LED_1 B0
#define LED_2 B7
#define LED_3 B14

#define PWM_1 TIMER4_CH2

using namespace HAL;

// Gestion De l'objet UART/USART
#include <stream/hal/uart_stream.hpp>

using namespace Stream;

struct MySettings : public DefaultUARTStreamSettings {
    static constexpr auto& uart = SERIAL_USART3;
    static constexpr auto& tx = D8;
    static constexpr auto& rx = D9;

    static constexpr auto baudrate = 9600;
    static constexpr auto parity = UART::Parity::NONE;
    static constexpr auto stop_bit = UART::StopBit::ONE_BIT;
    static constexpr auto word_size = 8;
};

// Nom du format Stream de l'UART
Stream::FormattedUARTStream<MySettings> UART_1;

// Début du programme
int main(int, char**)
{

  // Initialisation des parammètres des GPIOs
  GPIO::Settings settings;
  settings.mode = GPIO::Mode::OUTPUT;
  settings.output_mode = GPIO::OutputMode::PUSH_PULL;
  settings.pull = GPIO::Pull::DOWN;

  // Initialisation des parammètres des TIMERs
  TIMER::Settings timer_settings;  
  timer_settings.period = 10; //us

  // Initialisation des parammètres des PWMs 
  PWM::Settings pwm_settings;
  pwm_settings.polarity = PWM::Polarity::HIGH;

  // Initialisation des GPIOs à l'aide des parammètres
  GPIO::init(LED_1,settings);
  // GPIO::init(LED_2,settings);
  GPIO::init(LED_3,settings);

  // Initialisation des TIMERs à l'aide des parammètres
  TIMER::init(TIMER4, timer_settings);

  // Initialisation des PWMs à l'aide des parammètres
  PWM::init(PWM_1, B7, pwm_settings);
  
  // Utilisation des GPIOs: changement d'états
  GPIO::toggle(LED_1);
  // GPIO::toggle(LED_2);
  GPIO::toggle(LED_3);  

  // Utilisation des TIMERs: lancement
  TIMER::start(TIMER4);
  // Utilisation des TIMERs: interruption par l'Overflow
  TIMER::setOverflowHandler(TIMER4,[](){
  // Routine de l'interruption
    static int i = 0;
    if (i == 65540)
      i = 0;
    else
      i++;
    PWM::setPulseWidth(PWM_1, i); // entre 0 et 65545
  });

  // Utilisation des PWMs: affectation du rapport ----- ATTENTION il faut avoir démarré le TIMER
  // PWM::setPulseWidth(PWM_1, 20000); // entre 0 et 65545

  while(1)
  {
    UART_1 << (u32)TIM4->CNT << " "; // compteur
    UART_1 << (u32)TIM4->ARR << " "; // valeur d'overflow du compteur (période)
    UART_1 << (u32)TIM4->PSC << " "; // prescaler (pour info)
    UART_1 << (u32)TIM4->CCR2 << "\n\r"; // valeur du comparateur Channel 4
    // auto& timer_handle = Private::get_timer_cube_handle<2>();
    // u32 var = __HAL_TIM_GetCounter(&timer_handle);
    // UART_1 << var << "\n\r";
  }

  return 0;
 
}
