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

#include <xc.h>
#include <string.h>
#include "WiFly.h"
#include "pin_manager.h"
#include <stdint.h>

void WiFly_CheckResponse(const char* chkString) {
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

void WiFly_Example_InitializeAsClient(const char* ssid, const char* password){
    WiFly_Wake_SetHigh();
    WiFly_FactoryReset();
    
    WiFly_SendCMD("set ip dhcp 1\r\n");
    WiFly_SendCMD_SingleArg("set wlan passphrase %s\r\n", password);
    WiFly_SendCMD_SingleArg("set wlan ssid %s\r\n", ssid);
    WiFly_SendCMD("set wlan join 1\r\n");
    WiFly_SendString("set ip protocol 08\r\n");
    WiFly_SaveConfig();
    WiFly_CheckRecv("IF=UP");
}

void WiFly_Example_Connect(const char* addr, const char* port){
    WiFly_SendCMD_DoubleArg("open %s %s\r\n", addr, port);
    WiFly_CheckRecv(openStr);
}

void WiFly_Example_SendMessages(void){
    WiFly_CheckResponse("Proceed");
    WiFly_SendString("Knock Knock\r\n");
    WiFly_CheckResponse("there?");
    WiFly_SendString("Doctor\r\n");
    WiFly_CheckResponse("who?");
    WiFly_SendString("\n\
           | |\n\
           | |\n\
   -------------------\n\
   -------------------\n\
    |  ___  |  ___  |\n\
    | | | | | | | | |\n\
    | |-+-| | |-+-| |\n\
    | |_|_| | |_|_| |\n\
    |  ___  |  ___  |\n\
    | |   | | |   | |\n\
    | |   | | |   | |\n\
    | |___| | |___| |\n\
    |  ___  |  ___  |\n\
    | |   | | |   | |\n\
    | |   | | |   | |\n\
    | |___| | |___| |\n\
    |       |       |\n\
   ===================\n");
}