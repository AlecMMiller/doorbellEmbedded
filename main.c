/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F18855
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/WiFly.h"
#include "mcc_generated_files/EXAMPLE_WiFly.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define UID_ADDR 1

char failedStr[] = "FAILED";
char errStr[] = "ERR";

enum connection_modes {
    STARTING, PAIRED, UNPAIRED, PAIRING, DISCONNECTED
};

enum returns {
    SUCCESS, FAILED, TX_ERROR
};

uint8_t UID = 0;
uint8_t mode = STARTING;
uint8_t pingTime = 0;

bool indStatus = false;

void ClearIndicators(){
    indStatus = 0;
    INDICATOR1_LAT = 0;
    INDICATOR2_LAT = 0;
    INDICATOR3_LAT = 0;
    INDICATOR4_LAT = 0;
}

void SetIndication(bool set) {
    indStatus = set;
    
    if (UID & 1) {
        INDICATOR1_LAT = set;
    }
    if (UID & 1 << 1) {
        INDICATOR2_LAT = set;
    }
    if (UID & 1 << 2) {
        INDICATOR3_LAT = set;
    }
    if (UID & 1 << 3) {
        INDICATOR4_LAT = set;
    }
}

void goto_mode(uint8_t target) {
    mode = target;
    switch (mode) {
        case PAIRED:
            TMR2_StopTimer();
            SetIndication(1);
            TMR4_StartTimer();
            break;
        case DISCONNECTED:
            T2PR = 40;
            TMR2_StartTimer();
            break;
        case PAIRING:
            T2PR = 10;
            TMR2_StartTimer();
            break;
        case UNPAIRED:
            TMR2_StopTimer();
            TMR4_StopTimer();
            ClearIndicators();
            break;
    }
}

uint8_t CheckResponse(const char * chkString1, const char * chkString2, const char * chkString3) {
    size_t length1 = strlen(chkString1);
    size_t i1 = 0;
    size_t length2 = strlen(chkString2);
    size_t i2 = 0;
    size_t length3 = strlen(chkString3);
    size_t i3 = 0;

    while (i1 < length1 && i2 < length2 && i3 < length3) {
        char input = WiFly_ReadChar();
        if (input == chkString1[i1]) {
            i1++;
        } else {
            i1 = 0;
        }

        if (input == chkString2[i2]) {
            i2++;
        } else {
            i2 = 0;
        }

        if (input == chkString3[i3]) {
            i3++;
        } else {
            i3 = 0;
        }
    }

    if (i1 == length1) {
        return 1;
    } else if (i2 == length2) {
        return 2;
    } else {
        return 3;
    }

}

void connect_socket(const char* addr, const char* port) {
    do {
        WiFly_SendCMD_DoubleArg("open %s %s\r\n", addr, port);
    } while (CheckResponse(openStr, failedStr, errStr) != 1);

    inCMD = 0;
}

void WaitResponse(const char* chkString) {
    size_t length = strlen(chkString);
    size_t i = 0;

    while (i < length) {
        if (WiFly_ReadChar() == chkString[i]) {
            i++;
        } else {
            i = 0;
        }
    }

}

uint8_t get_response() {
    while (1) {
        WaitResponse("Stat: ");
        uint8_t status = WiFly_ReadChar();
        if (status == 'Y') {
            goto_mode(PAIRED);
            return SUCCESS;
        } else if (status == 'N') {
            return FAILED;
        } else if (status == 'E') {
            return TX_ERROR;
        }
    }
    return 0; // SHOULD NEVER GET HERE
}

void send_message(const char * message) {
    goto_mode(DISCONNECTED);
    connect_socket("192.168.1.7", "1335");
    Clear_RX_Buffer();
    WaitResponse("Proceed");
    CLRWDT();
    WiFly_SendString(message);
}

uint8_t Pair(void) {
    uint8_t returnVal;
    char pairString[] = "pair 123";
    sprintf(pairString, "pair %03d", UID);
    send_message(pairString);
    goto_mode(PAIRING);
    returnVal = get_response();
    if (returnVal == SUCCESS) {
        UID = WiFly_ReadChar();
        eeprom_write(UID_ADDR, UID);
        goto_mode(PAIRED);
    } else {
        goto_mode(UNPAIRED);
    }
    return returnVal;
}

uint8_t Validate() {
    uint8_t returnVal;
    pingTime = 0;
    char valString[] = "validate 123";
    sprintf(valString, "validate %03d", UID);
    do {
        send_message(valString);
        returnVal = get_response();
        if (returnVal == SUCCESS) {
            goto_mode(PAIRED);
        } else if (returnVal == FAILED) {
            goto_mode(UNPAIRED);
        }
    } while (returnVal == TX_ERROR);
    TMR4_StartTimer();
    return returnVal;
}

uint8_t Knock() {
    RELAY_RL1_Engage();
    uint8_t returnVal;
    TMR4_StopTimer();
    char knockString[] = "knock 123";
    sprintf(knockString, "knock %03d", UID);
    do {
        send_message(knockString);
        returnVal = get_response();
        if (returnVal == SUCCESS) {
            goto_mode(PAIRED);
        } else {
            goto_mode(UNPAIRED);
        }
    } while ((returnVal == TX_ERROR));
    WDTCON0bits.SWDTEN = 0;
    __delay_ms(1000);
    RELAY_RL1_Disengage();
    WDTCON0bits.SWDTEN = 1;
    return returnVal;
}

void connect_network(const char * ssid, const char * passwd) {

    WiFly_Example_InitializeAsClient(ssid, passwd);
}

void blink() {
    SetIndication(!indStatus);
}

void setFlag() {
    TMR4_StopTimer();
    pingTime = 1;
}

void main(void) {
    WDTCON0bits.SWDTEN = 0;
    // initialize the device
    SYSTEM_Initialize();

    TMR2_SetInterruptHandler(blink);
    TMR4_SetInterruptHandler(setFlag);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    T2PR = 10;
    
    TMR2_StartTimer();
    TMR4_StopTimer();

    UID = eeprom_read(UID_ADDR);

    WiFly_FactoryReset();
    
    connect_network("C4-2-543_WLAN", "H@cker101");

    if (UID == 0xFF) {
        mode = UNPAIRED;
        Pair();
    } else {
        Validate();
    }
    
    WDTCON0bits.SWDTEN = 1;

    while (1) {
        CLRWDT();
        switch (mode) {
            case UNPAIRED:
                if (PAIR_PORT == 0) {
                    Pair();
                }
                break;
            case PAIRED:
                if (pingTime) {
                    Validate();
                }
                if (DOORBELL_PORT == 0) {
                    Knock();
                }
                break;
        }
    }
}
/**
 End of File
 */