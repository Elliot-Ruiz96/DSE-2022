/* Project Documentation
  @Company
    DSE Visteon 2022

  @Project Name
  DSEV2Lab01ERS

  @File Name
    main.c

  @Version 0.1

  @Author Ruiz Sanchez Elliot

  @Summary
    This is the generated main.c using TM4C129E MCU.

  @Description
    This source file initialize the clock system and the GPIO peripheral using TivaWare.
    We�ll then use the GPIO output to blink an LED on the evaluation board.
    2 initializes for 10 seconds, then D1 for 10 seconds, finally Off again for 10 secons also.

    Generation Information :
        Product Revision  :  TM4C129EXL - 1.168.0
        Device            :  TM4C129ENCPDTI
    The generated drivers are tested against the following:
        Languaje          :  C ANSI C 89 Mode
        Compiler          :  TIv18.12.4LTS
        CCS               :  CCS 9.3.0.00012
*/

/*
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
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

//#define SYSCTL_PERIPH_GPION     0xf000080c  // GPIO N
uint8_t ui8PinData = 1;

int main(void)
{
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1);
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1, 0x00);
    while(1)
    {
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, ui8PinData);
        SysCtlDelay(200000000);
        if(4 == ui8PinData)
        {
            ui8PinData = 1;
        }
        else
        {
            ui8PinData = ui8PinData * 2;
        }
        SysCtlDelay(200000000);
    }
}
