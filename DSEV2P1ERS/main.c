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
    This source file initialize the clock system and the GPIO peripheral using TivaWare.
    We will then use the GPIO output to blink an LED on the evaluation board.
    SW1 turns on THE led until SW2 turns it off.

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

//#define SYSCTL_PERIPH_GPION     0xf000080c  // GPIO N

/*------------------------------------------------------------------------------------------------------------------
 *
 * Macros definition
 *
------------------------------------------------------------------------------------------------------------------*/

#define GPIO_PORTN_BASE32   0x40064000
#define OSC_CLK_120MHZ       120000000

#define LED_OFF             0x00
#define LED_ON              0x01

#define DELAY_VALUE         50000000


/*------------------------------------------------------------------------------------------------------------------
 * int main
 *
 * Initialize program
 *
------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), OSC_CLK_120MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1, LED_OFF);
    while(1)
    {
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, LED_ON);
        SysCtlDelay(DELAY_VALUE);
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, LED_OFF);
        SysCtlDelay(DELAY_VALUE);
    }

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------
 *
 * Version Control
 *
 *  USER    | VERSION   |       COMMENT
 * eruiz3       0.1         Initial Template
 *
------------------------------------------------------------------------------------------------------------------*/
