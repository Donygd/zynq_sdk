/*
 * main.c
 *
 *  Created on: 2021年8月19日
 *      Author: DON
 */
#include "xparameters.h"   //器件参数信息
#include "xstatus.h"       //包含XST_FAILURE和XST_SUCCESS得宏定义
#include "xil_printf.h"    //包含print()函数
#include "xgpiops.h"       //包含PS GPIO得函数声明
#include "sleep.h"         //包含sleep()函数

//宏定义GPIO_DEVICE_ID
#define GPIO_DEVICE_ID XPAR_XGPIOPS_0_DEVICE_ID
//连接到MIO的LED

#define MIOLED0 7
#define MIOLED1 8
#define MIOLED2 0

XGpioPs Gpio;
int main()
{
	int Status;
	XGpioPs_Config *ConfigPtr;
	print("MIO Test!\r\n");
	ConfigPtr=XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	Status=XGpioPs_CfgInitialize(&Gpio,ConfigPtr,ConfigPtr->BaseAddr);
	if(Status!=XST_SUCCESS){
		return XST_FAILURE;
	}
//设置指定引脚的方向：0输入，1输出
XGpioPs_SetDirectionPin(&Gpio,MIOLED0,1);
XGpioPs_SetDirectionPin(&Gpio,MIOLED1,1);
XGpioPs_SetDirectionPin(&Gpio,MIOLED2,1);
//使能指定引脚输出：0禁止输出使能，1使能输出
XGpioPs_SetOutputEnablePin(&Gpio,MIOLED0,1);
XGpioPs_SetOutputEnablePin(&Gpio,MIOLED1,1);
XGpioPs_SetOutputEnablePin(&Gpio,MIOLED2,1);

while(1){
	XGpioPs_WritePin(&Gpio,MIOLED0,0x0);
	XGpioPs_WritePin(&Gpio,MIOLED1,0x0);
	XGpioPs_WritePin(&Gpio,MIOLED2,0x0);
	sleep(1);
	XGpioPs_WritePin(&Gpio,MIOLED0,0x1);
	XGpioPs_WritePin(&Gpio,MIOLED1,0x1);
	XGpioPs_WritePin(&Gpio,MIOLED2,0x1);
	sleep(1);
}
return XST_SUCCESS;
}

