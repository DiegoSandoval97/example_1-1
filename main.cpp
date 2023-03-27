#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    /**
    * @brief Declarar las variables correspondientes a un pin digital de entrada (gasDetector)
    *       y a un pin digital de salida (alarmLed).
    * @param D2 
    **/
    //DigitalIn gasDetector(D3);
    gpio_t gasDetector;
    gpio_init_in(&gasDetector, D2);

    //DigitalOut alarmLed(LED1);
    //gasDetector.mode(PullDown);
    gpio_t alarmLed;
    gpio_init_out_ex(&alarmLed, LED1, PullDown);

    //alarmLed = OFF;
    gpio_write(&alarmLed, OFF);

    printf("%s\n", "Hello World");

    while (true) {
        //if ( gasDetector == ON )
        if ( gpio_read(&gasDetector) == ON ) {
            //alarmLed = ON;
            gpio_write(&alarmLed, ON);
        }
        
        //if ( gasDetector == OFF )
        if ( gpio_read(&gasDetector) == OFF ) {
            //alarmLed = OFF;
            gpio_write(&alarmLed, OFF);
        }
    }
}