/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F18875
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set INDICATOR1 aliases
#define INDICATOR1_TRIS               TRISAbits.TRISA4
#define INDICATOR1_LAT                LATAbits.LATA4
#define INDICATOR1_PORT               PORTAbits.RA4
#define INDICATOR1_WPU                WPUAbits.WPUA4
#define INDICATOR1_OD                ODCONAbits.ODCA4
#define INDICATOR1_ANS                ANSELAbits.ANSA4
#define INDICATOR1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define INDICATOR1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define INDICATOR1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define INDICATOR1_GetValue()           PORTAbits.RA4
#define INDICATOR1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define INDICATOR1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define INDICATOR1_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define INDICATOR1_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define INDICATOR1_SetPushPull()    do { ODCONAbits.ODCA4 = 1; } while(0)
#define INDICATOR1_SetOpenDrain()   do { ODCONAbits.ODCA4 = 0; } while(0)
#define INDICATOR1_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define INDICATOR1_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set INDICATOR2 aliases
#define INDICATOR2_TRIS               TRISAbits.TRISA5
#define INDICATOR2_LAT                LATAbits.LATA5
#define INDICATOR2_PORT               PORTAbits.RA5
#define INDICATOR2_WPU                WPUAbits.WPUA5
#define INDICATOR2_OD                ODCONAbits.ODCA5
#define INDICATOR2_ANS                ANSELAbits.ANSA5
#define INDICATOR2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define INDICATOR2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define INDICATOR2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define INDICATOR2_GetValue()           PORTAbits.RA5
#define INDICATOR2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define INDICATOR2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define INDICATOR2_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define INDICATOR2_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)
#define INDICATOR2_SetPushPull()    do { ODCONAbits.ODCA5 = 1; } while(0)
#define INDICATOR2_SetOpenDrain()   do { ODCONAbits.ODCA5 = 0; } while(0)
#define INDICATOR2_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define INDICATOR2_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set INDICATOR3 aliases
#define INDICATOR3_TRIS               TRISAbits.TRISA6
#define INDICATOR3_LAT                LATAbits.LATA6
#define INDICATOR3_PORT               PORTAbits.RA6
#define INDICATOR3_WPU                WPUAbits.WPUA6
#define INDICATOR3_OD                ODCONAbits.ODCA6
#define INDICATOR3_ANS                ANSELAbits.ANSA6
#define INDICATOR3_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define INDICATOR3_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define INDICATOR3_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define INDICATOR3_GetValue()           PORTAbits.RA6
#define INDICATOR3_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define INDICATOR3_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define INDICATOR3_SetPullup()      do { WPUAbits.WPUA6 = 1; } while(0)
#define INDICATOR3_ResetPullup()    do { WPUAbits.WPUA6 = 0; } while(0)
#define INDICATOR3_SetPushPull()    do { ODCONAbits.ODCA6 = 1; } while(0)
#define INDICATOR3_SetOpenDrain()   do { ODCONAbits.ODCA6 = 0; } while(0)
#define INDICATOR3_SetAnalogMode()  do { ANSELAbits.ANSA6 = 1; } while(0)
#define INDICATOR3_SetDigitalMode() do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set INDICATOR4 aliases
#define INDICATOR4_TRIS               TRISAbits.TRISA7
#define INDICATOR4_LAT                LATAbits.LATA7
#define INDICATOR4_PORT               PORTAbits.RA7
#define INDICATOR4_WPU                WPUAbits.WPUA7
#define INDICATOR4_OD                ODCONAbits.ODCA7
#define INDICATOR4_ANS                ANSELAbits.ANSA7
#define INDICATOR4_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define INDICATOR4_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define INDICATOR4_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define INDICATOR4_GetValue()           PORTAbits.RA7
#define INDICATOR4_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define INDICATOR4_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define INDICATOR4_SetPullup()      do { WPUAbits.WPUA7 = 1; } while(0)
#define INDICATOR4_ResetPullup()    do { WPUAbits.WPUA7 = 0; } while(0)
#define INDICATOR4_SetPushPull()    do { ODCONAbits.ODCA7 = 1; } while(0)
#define INDICATOR4_SetOpenDrain()   do { ODCONAbits.ODCA7 = 0; } while(0)
#define INDICATOR4_SetAnalogMode()  do { ANSELAbits.ANSA7 = 1; } while(0)
#define INDICATOR4_SetDigitalMode() do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set DOORBELL aliases
#define DOORBELL_TRIS               TRISBbits.TRISB4
#define DOORBELL_LAT                LATBbits.LATB4
#define DOORBELL_PORT               PORTBbits.RB4
#define DOORBELL_WPU                WPUBbits.WPUB4
#define DOORBELL_OD                ODCONBbits.ODCB4
#define DOORBELL_ANS                ANSELBbits.ANSB4
#define DOORBELL_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define DOORBELL_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define DOORBELL_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define DOORBELL_GetValue()           PORTBbits.RB4
#define DOORBELL_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define DOORBELL_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define DOORBELL_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define DOORBELL_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define DOORBELL_SetPushPull()    do { ODCONBbits.ODCB4 = 1; } while(0)
#define DOORBELL_SetOpenDrain()   do { ODCONBbits.ODCB4 = 0; } while(0)
#define DOORBELL_SetAnalogMode()  do { ANSELBbits.ANSB4 = 1; } while(0)
#define DOORBELL_SetDigitalMode() do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()     do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()   do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode() do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()    do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()   do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()   do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()         PORTCbits.RC1
#define RC1_SetDigitalInput()   do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()  do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()     do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()   do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode() do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set Relay_RL1 aliases
#define Relay_RL1_TRIS               TRISCbits.TRISC2
#define Relay_RL1_LAT                LATCbits.LATC2
#define Relay_RL1_PORT               PORTCbits.RC2
#define Relay_RL1_WPU                WPUCbits.WPUC2
#define Relay_RL1_OD                ODCONCbits.ODCC2
#define Relay_RL1_ANS                ANSELCbits.ANSC2
#define Relay_RL1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Relay_RL1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Relay_RL1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Relay_RL1_GetValue()           PORTCbits.RC2
#define Relay_RL1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Relay_RL1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Relay_RL1_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define Relay_RL1_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define Relay_RL1_SetPushPull()    do { ODCONCbits.ODCC2 = 1; } while(0)
#define Relay_RL1_SetOpenDrain()   do { ODCONCbits.ODCC2 = 0; } while(0)
#define Relay_RL1_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define Relay_RL1_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set PAIR aliases
#define PAIR_TRIS               TRISCbits.TRISC5
#define PAIR_LAT                LATCbits.LATC5
#define PAIR_PORT               PORTCbits.RC5
#define PAIR_WPU                WPUCbits.WPUC5
#define PAIR_OD                ODCONCbits.ODCC5
#define PAIR_ANS                ANSELCbits.ANSC5
#define PAIR_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PAIR_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PAIR_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PAIR_GetValue()           PORTCbits.RC5
#define PAIR_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PAIR_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PAIR_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define PAIR_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define PAIR_SetPushPull()    do { ODCONCbits.ODCC5 = 1; } while(0)
#define PAIR_SetOpenDrain()   do { ODCONCbits.ODCC5 = 0; } while(0)
#define PAIR_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define PAIR_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set WiFly_HwReset aliases
#define WiFly_HwReset_TRIS               TRISDbits.TRISD2
#define WiFly_HwReset_LAT                LATDbits.LATD2
#define WiFly_HwReset_PORT               PORTDbits.RD2
#define WiFly_HwReset_WPU                WPUDbits.WPUD2
#define WiFly_HwReset_OD                ODCONDbits.ODCD2
#define WiFly_HwReset_ANS                ANSELDbits.ANSD2
#define WiFly_HwReset_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define WiFly_HwReset_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define WiFly_HwReset_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define WiFly_HwReset_GetValue()           PORTDbits.RD2
#define WiFly_HwReset_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define WiFly_HwReset_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define WiFly_HwReset_SetPullup()      do { WPUDbits.WPUD2 = 1; } while(0)
#define WiFly_HwReset_ResetPullup()    do { WPUDbits.WPUD2 = 0; } while(0)
#define WiFly_HwReset_SetPushPull()    do { ODCONDbits.ODCD2 = 1; } while(0)
#define WiFly_HwReset_SetOpenDrain()   do { ODCONDbits.ODCD2 = 0; } while(0)
#define WiFly_HwReset_SetAnalogMode()  do { ANSELDbits.ANSD2 = 1; } while(0)
#define WiFly_HwReset_SetDigitalMode() do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set WiFly_Wake aliases
#define WiFly_Wake_TRIS               TRISDbits.TRISD3
#define WiFly_Wake_LAT                LATDbits.LATD3
#define WiFly_Wake_PORT               PORTDbits.RD3
#define WiFly_Wake_WPU                WPUDbits.WPUD3
#define WiFly_Wake_OD                ODCONDbits.ODCD3
#define WiFly_Wake_ANS                ANSELDbits.ANSD3
#define WiFly_Wake_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define WiFly_Wake_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define WiFly_Wake_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define WiFly_Wake_GetValue()           PORTDbits.RD3
#define WiFly_Wake_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define WiFly_Wake_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define WiFly_Wake_SetPullup()      do { WPUDbits.WPUD3 = 1; } while(0)
#define WiFly_Wake_ResetPullup()    do { WPUDbits.WPUD3 = 0; } while(0)
#define WiFly_Wake_SetPushPull()    do { ODCONDbits.ODCD3 = 1; } while(0)
#define WiFly_Wake_SetOpenDrain()   do { ODCONDbits.ODCD3 = 0; } while(0)
#define WiFly_Wake_SetAnalogMode()  do { ANSELDbits.ANSD3 = 1; } while(0)
#define WiFly_Wake_SetDigitalMode() do { ANSELDbits.ANSD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/