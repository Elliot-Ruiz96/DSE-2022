/* Project Documentation
  @Company
    DSE Visteon 2022

  @Project Name
  DSEV2P1ERS

  @File Name
    main.c

  @Version 0.1

  @Author Ruiz Sanchez Elliot

  @Summary
    This is the generated main.c using TM4C129E MCU.

  @Description
    This source file description to use the PWMO on the Tiva C Series device to control LED4 (PF0).
    SW1 SW2

    Generation Information :
        Product Revision  :  TM4C129EXL - 1.168.0
        Device            :  TM4C129ENCPDTI
    The generated drivers are tested against the following:
        Languaje          :  C ANSI C 89 Mode
        Compiler          :  TIv18.12.4LTS
        CCS               :  CCS 9.3.0.00012

    (c) 2022 Ruiz Sanchez Elliot. You may use this
    software and any derivatives exclusively with Texas Instruments products.

    THIS SOFTWARE IS SUPPLIED BY Ruiz Sanchez Elliot "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH TEXAS INSTRUMENTS PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    Ruiz Sanchez Elliot PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/*------------------------------------------------------------------------------------------------------------------
 *
 * Libraries included
 *
------------------------------------------------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"      //  Definitions and macros of PWM
#include "driverlib/pin_map.h"  //
#include "inc/hw_gpio.h"        //

/*------------------------------------------------------------------------------------------------------------------
 *
 * Macros definition
 *
------------------------------------------------------------------------------------------------------------------*/

//#define SYSCTL_PERIPH_GPION     0xf000080c  // GPIO N

#define PWM_FREQUENCY   1000
#define OSC_CLK_120MHZ  120000000
#define PRESSED         0x00
#define MIN             10
#define MAX             1820

/*------------------------------------------------------------------------------------------------------------------
 * int main
 *
 * Initialize program
 *
------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    volatile uint32_t ui32Load;
    volatile uint32_t ui32PWMClock;
    volatile uint16_t ui16Adjust;
    ui16Adjust = MIN;
    //
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), OSC_CLK_120MHZ);

    // Configuracion de perifericos
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);            // Establecer el reloj del PWM
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);     //  Habilitar periferico PWM0

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);    // Enable Port F
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);    // Configure PF0 as PWM
    GPIOPinConfigure(GPIO_PF0_M0PWM0);              //  Comfigurar PF0 como salida del M0PWM0

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);    // Enable Port J

    GPIODirModeSet(GPIO_PORTJ_BASE, GPIO_PIN_1|GPIO_PIN_0, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_1|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    ui32PWMClock = OSC_CLK_120MHZ / 64;           //  Frecuencia del reloj del Modulo PWM0 SysCtlClockGet()
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;  //  Establecer el numero maximo del contador para una frecuencia de 1kHz
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);   //  Configurar el generador del PWM0, Gen0, conteo descendente
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ui32Load);            //  Establecer el valor inicial de conteo en PWM0 Gen0

    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ui16Adjust);     // Establecer el ancho del pulso
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);         //  Configurar la polaridad de la salida del PWM0
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);                     //  Habilitar PWM0Gen0  (inicio de trabajo)

    while(1)
    {
        if(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_0) == PRESSED)
        {
            ui16Adjust = ui16Adjust - MIN;
            if (ui16Adjust < MIN)
            {
                ui16Adjust = MIN;
            }

            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ui16Adjust);// * ui32Load / 1000);
        }
        if(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_1) == PRESSED)
        {
            ui16Adjust = ui16Adjust + MIN;
            if (ui16Adjust > MAX)
            {
                ui16Adjust = MAX;
            }

            PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, ui16Adjust);// * ui32Load / 1000);
        }

        //ui16Adjust=ui16Adjust+10;
        SysCtlDelay(4000000);

        }

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------
 *
 * Version Control
 *
 *  USER    | VERSION   |       COMMENT
 * eruiz3       0.1         Initial Template
------------------------------------------------------------------------------------------------------------------*/
