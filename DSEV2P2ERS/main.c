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
    This source file description to use the ADCO on the Tiva C Series device with Temperature Sensor.
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
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"

/*------------------------------------------------------------------------------------------------------------------
 *
 * Macros definition
 *
------------------------------------------------------------------------------------------------------------------*/

//#define SYSCTL_PERIPH_GPION     0xf000080c  // GPIO N

#define OSC_CLK_120MHZ       120000000

/*------------------------------------------------------------------------------------------------------------------
 * int main
 *
 * Initialize program
 *
------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    uint32_t ui32ADC0Value[4];              //  Declaracion de la variable ui32ADC0Value que es un vector de 4 localidades de memoria

    volatile uint32_t ui32TempAvg;          //  Declaracion de la variable ui32TempAvg ui32TempValueCs cuatro lecturas
    volatile uint32_t ui32TempValueC;       //  Declaracion de la variable ui32TempValueC para guardar el valor en grados Celcius
    volatile uint32_t ui32TempValueF;       //  Declaracion de la variable ui32TempValueF para guardar el valor en grados Fahrenheit

    volatile uint32_t ui32Potenciometro;    // Declaracion de las variable para lectura de optenciometro
    //
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), OSC_CLK_120MHZ);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);                                 //  Habilitar el periferico ADC0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);                                //Habilitar puerto E

    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);               //  Configurar el secuenciador (modulo ADC0, Secuenciador SS1, Modo de disparo por sw, nivel de prioridad 0)

    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);                                //Configurar PE3 Chanel0

    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH0);                      //  Configurar el paso del secuenciador (modulo ADC0, Secuenciador SS1, numero de paso = 0, fuente senal anal. Sensor temperatura)
    ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH0);                      //  Configurar el paso del secuenciador (modulo ADC0, Secuenciador SS1, numero de paso = 1, fuente senal anal. Sensor temperatura)
    ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);                      //  Configurar el paso del secuenciador (modulo ADC0, Secuenciador SS1, numero de paso = 2, fuente senal anal. Sensor temperatura)
    ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);  //  Configurar el paso del secuenciador (modulo ADC0, Secuenciador SS1, numero de paso = 0, fuente senal anal. Sensor temperatura, ultimo paso)

    ADCSequenceEnable(ADC0_BASE, 1);        //  Habilitar la conversion del ADC0

    while(1)
    {
        ADCIntClear(ADC0_BASE, 1);     //  Limpiar la interrupcion del ADC
        ADCProcessorTrigger(ADC0_BASE, 1);     //  Inicio de conversion (TRIGGER) del ADC0

        while(!ADCIntStatus(ADC0_BASE, 1, false))  //  Rutina de espera por el fin de conversion del ADC0
        {

        }

         ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);   //  Traer los resusultados de la conversion (4 muestras) y guardar en el vector ui32ADC0Value

         ui32TempAvg = (ui32ADC0Value[2] + ui32ADC0Value[3] + 1) / 2;
         ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096) / 10;
         ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

         ui32Potenciometro = (ui32ADC0Value[0] + ui32ADC0Value[1] + 1) / 2;

    }

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------
 *
 * Version Control
 *
 *  USER    | VERSION   |       COMMENT
 * eruiz3       0.1         Initial Template
 * eruiz3       0.2         Integration for potentiometer
 *
------------------------------------------------------------------------------------------------------------------*/
