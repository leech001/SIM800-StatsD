# STM32 HAL library for SIM800 (GPRS) release send metric StatsD  over AT command

###Simple C library (STM32 HAL) for working with the StatsD protocol through AT commands (GPRS) of the SIM800 module

Configure STM32CubeMX by setting "General peripheral Initalizion as a pair of '.c / .h' file per peripheral" in the project settings.
Remember to enable global interrupts for your UART.
Copy the library header and source file to the appropriate project directories (Inc, Src).
Configure the UART port where your module is connected in the Sim800_StatsD.h file.
```
#define UART_SIM800 & huart1
#define FREERTOS 0
#define CMD_DELAY 2000
```
In the main file of your project (main.c), include the header file
```
/ * USER CODE BEGIN Includes * /
#include "Sim800_StatsD.h"
/ * USER CODE END Includes * /
```
add function call Sim800_RxCallBack () to interrupt UART
```
/ * USER CODE BEGIN 0 * /
void HAL_UART_RxCpltCallback (UART_HandleTypeDef * huart) {
    if (huart == & huart1) {
        Sim800_RxCallBack ();
    }
}
/ * USER CODE END 0 * /
```
add the module initialization code and parameters for connecting to the StatsD server in the main (void) function section
```
/ * USER CODE BEGIN 2 * /

  SIM800_Init ();
  StatsD_Connect("APN", "APN NAME", "APN PASS", "HOST", PORT);

 / * USER CODE END 2 * /
```
Send metric to the server in an infinite while (1) loop, for example every 10 seconds.
```
/ * Infinite loop * /
  / * USER CODE BEGIN WHILE * /
  while (1)
  {
    StatsD_SendInt("test_metric", 12345, "g");
    StatsD_SendDouble("test_metric", 123.45, "g");
    HAL_Delay (10000);
    / * USER CODE END WHILE * /

    / * USER CODE BEGIN 3 * /
  }
  / * USER CODE END 3 * /
```
This completes the setup.
