/*
 * Sim800_StatsD.h
 *
 *  Created on: Jan 4, 2020
 *      Author: Bulanov Konstantin
 *
 *  Contact information
 *  -------------------
 *
 * e-mail   :  leech001@gmail.com
 *
 *
 */

#include <main.h>

// === CONFIG ===
#define UART_SIM800 &huart1
#define FREERTOS    1
#define CMD_DELAY   1500
// ==============

void Sim800_RxCallBack(void);

int SIM800_SendCommand(char *command, char *reply, uint16_t delay);

int SIM800_Init(void);

int StatsD_Connect(char *apn, char *apn_user, char *apn_pass, char *host, uint16_t port);

int StatsD_SendInt(char *metric, uint32_t value, char *type);

int StatsD_SendDouble(char *metric, double value, char *type);
