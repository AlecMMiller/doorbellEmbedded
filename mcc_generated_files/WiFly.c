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

#include "mcc.h"
#include "WiFly.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool inCMD;

// Local function prototypes
void initWaitingFunction(void);
void WiFly_EnterCMDDelay(void);
void WiFly_EnterCMDMode(void);
void WiFly_ExitCMDMode(void);
void WiFly_SendCMD(const uint8_t* cmd);
void WiFly_RebootCMD(void);

void initWaitingFunction(void) {

}

/**
 * Waits for the @chkString to be received before continuing
 * 
 * Calls the waitingFN callback while waiting for @chkString
 * @param chkString
 */

void WiFly_Send(char* command) {
    while (*command != '\0')
        uart[WiFly].Write(*command++);
}

void Clear_RX_Buffer(void) {
    while (EUSART_is_rx_ready()) {
        uart[WiFly].Read();
    }
}

void WiFly_CheckInCMD(void) {
    if (!inCMD) {
        WiFly_EnterCMDMode();
    }
}

void WiFly_SendString(const uint8_t* sendString) {
    Clear_RX_Buffer();
    WiFly_Send(sendString);
}

char WiFly_ReadChar(void) {
    while (!EUSART_is_rx_ready()) {
        NOP();
    }
    return uart[WiFly].Read();
}

void WiFly_CheckRecv(const char* chkString) {
    size_t length = strlen(chkString);
    size_t i = 0;

    while (i < length) {
        while (EUSART_is_rx_ready()) {
            if (uart[WiFly].Read() == chkString[i]) {
                i++;
            } else {
                i = 0;
            }
        }
    }

}

// Public Functions

void WiFly_EnterCMDMode(void) {
    Clear_RX_Buffer();
    __delay_ms(275);
    WiFly_Send("$$$");
    WiFly_CheckRecv(cmdStr);
    __delay_ms(275);
    inCMD = true;
}

void WiFly_ExitCMDMode(void) {
    if (!inCMD) {
        return;
    }
    WiFly_SendString("exit\r\n");
    WiFly_CheckRecv(endStr);
    inCMD = false;
}

void WiFly_SendCMD_SingleArg(const char* cmdFormat, const char* arg) {
    WiFly_CheckInCMD();
    Clear_RX_Buffer();
    char txBuffer[40];
    sprintf(txBuffer, cmdFormat, arg);
    WiFly_Send(txBuffer);
    WiFly_CheckRecv(aokStr);
}

void WiFly_SendCMD_DoubleArg(const char* cmdFormat, const char* arg1, const char* arg2) {

    WiFly_CheckInCMD();
    Clear_RX_Buffer();
    char txBuffer[40];
    sprintf(txBuffer, cmdFormat, arg1, arg2);
    WiFly_Send(txBuffer);
}

void WiFly_SendCMD(const uint8_t* cmd) {

    WiFly_CheckInCMD();
    WiFly_SendString(cmd);
    WiFly_CheckRecv(aokStr);
}

void WiFly_RebootCMD(void) {

    WiFly_CheckInCMD();
    WiFly_SendString("reboot\r\n");
    WiFly_CheckRecv(softRebootStr);
    WiFly_CheckRecv(hardRebootStr);
    inCMD = false;
}

void WiFly_SaveConfig(void) {

    WiFly_SendString("save\r\n");
    WiFly_RebootCMD();
}

void WiFly_FactoryReset(void) {

    WiFly_HwReset_SetLow(); //Reset RN41
    inCMD = false;
    __delay_ms(50);
    WiFly_HwReset_SetHigh();
    WiFly_CheckRecv(hardRebootStr);

    WiFly_SendString("factory RESET\r\n");
    WiFly_RebootCMD();
    WiFly_SendCMD("set uart mode 0x11\r\n");
    WiFly_SaveConfig();
}