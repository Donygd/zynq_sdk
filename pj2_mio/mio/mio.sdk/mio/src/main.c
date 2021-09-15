/*
 * main.c
 *
 *  Created on: 2021��8��19��
 *      Author: DON
 */
#include "xparameters.h"   //����������Ϣ
#include "xstatus.h"       //����XST_FAILURE��XST_SUCCESS�ú궨��
#include "xil_printf.h"    //����print()����
#include "xgpiops.h"       //����PS GPIO�ú�������
#include "sleep.h"         //����sleep()����

//�궨��GPIO_DEVICE_ID
#define GPIO_DEVICE_ID XPAR_XGPIOPS_0_DEVICE_ID
//���ӵ�MIO��LED

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
//����ָ�����ŵķ���0���룬1���
XGpioPs_SetDirectionPin(&Gpio,MIOLED0,1);
XGpioPs_SetDirectionPin(&Gpio,MIOLED1,1);
XGpioPs_SetDirectionPin(&Gpio,MIOLED2,1);
//ʹ��ָ�����������0��ֹ���ʹ�ܣ�1ʹ�����
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

