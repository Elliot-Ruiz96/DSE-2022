/* File Documentation
  @Company
    DSE Visteon Grupo 2

  @File Name
    max7219.h

  @Version 1.0

  @Author Aguilar Pereyra José Felipe

  @Summary
    Header file for max7219, 7 segments 8 digits controller integrated circuit

  @Description
    This source file describes the operation codes for max7219 controller integrated circuit

*/

/*
    (c) 2020 Aguilar Pereyra José Felipe. You may use this
    software and any derivatives exclusively with Texas Instruments products.

    THIS SOFTWARE IS SUPPLIED BY Aguilar Pereyra José Felipe "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH TEXAS INSTRUMENTS PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    Aguilar Pereyra José Felipe PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
#ifndef MAX7219_MAX7219_H_
#define MAX7219_MAX7219_H_ "MAX7219_MAX7219_H_"

// Table 2. Register Address Map

#define No_Op           0x00    // No Operation
#define Digit_0         0x01    // Write in Digit 0 of Exhibitor
#define Digit_1         0x02    // Write in Digit 1 of Exhibitor
#define Digit_2         0x03    // Write in Digit 2 of Exhibitor
#define Digit_3         0x04    // Write in Digit 3 of Exhibitor
#define Digit_4         0x05    // Write in Digit 4 of Exhibitor
#define Digit_5         0x06    // Write in Digit 5 of Exhibitor
#define Digit_6         0x07    // Write in Digit 6 of Exhibitor
#define Digit_7         0x08    // Write in Digit 7 of Exhibitor
#define Decode_Mode     0x09    // Decodes info to CI
#define Intensity       0x0A    // Set brightness of displays
#define Scan_Limit      0x0B    // How many digits are displayed
#define Shutdown        0x0C    // Power Off
#define Display_Test    0x0F    // Turn On all LEDs

#endif

//the opcodes for the MAX7221 and MAX7219
