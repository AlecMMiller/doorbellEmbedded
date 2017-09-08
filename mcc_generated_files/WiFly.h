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

#ifndef WIFLY_H
#define	WIFLY_H

#include <stdint.h>
#include "drivers/uart.h"

// Types

const char hardRebootStr[] = "READY";
const char softRebootStr[] = "Reboot";
const char cmdStr[] = "CMD";
const char endStr[] = "EXIT";
const char aokStr[] = "AOK";
const char openStr[] = "OPEN";
    
//Functions

void Clear_RX_Buffer(void);
char WiFly_ReadChar(void);
void WiFly_SendCMD_SingleArg(const char* cmdFormat, const char* arg);
void WiFly_SendCMD_DoubleArg(const char* cmdFormat, const char* arg1, const char* arg2);
void WiFly_SendCMD(const uint8_t* cmd);
void WiFly_SendString(const uint8_t* sendString);
void WiFly_CheckRecv(const char* chkString);
void WiFly_CheckInCMD(void);
void WiFly_FactoryReset(void);
void WiFly_SaveConfig(void);

bool inCMD; // Set this to false after connection initiated

#endif

