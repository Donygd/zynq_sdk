/*
 * main.c
 *
 *  Created on: 2021年9月5日
 *      Author: DON
 */
#include "stdio.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "breath_led_ip.h"
#include "xil_io.h"
#include "sleep.h"

#define LED_IP_BASEADDR XPAR_BREATH_LED_IP_0_S0_AXI_BASEADDR  //LED IP 基地址
#define LED_IP_REG0     BREATH_LED_IP_S0_AXI_SLV_REG0_OFFSET
#define LED_IP_REG1     BREATH_LED_IP_S0_AXI_SLV_REG1_OFFSET

int main()
{
	int freq_flag;
	int led_state;
	xil_printf("LED User IP Test!\n");
	while(1)
	{
		if(freq_flag == 0)
		{
			BREATH_LED_IP_mWriteReg(LED_IP_BASEADDR,LED_IP_REG1,0x800000ef);
			freq_flag=1;
		}
		else{
			BREATH_LED_IP_mWriteReg(LED_IP_BASEADDR,LED_IP_REG1,0x8000002f);
			freq_flag=0;
		}
		led_state = BREATH_LED_IP_mReadReg(LED_IP_BASEADDR,LED_IP_REG0);
		if(led_state == 0)
		{
			BREATH_LED_IP_mWriteReg(LED_IP_BASEADDR,LED_IP_REG0,1);
			xil_printf("Breath LED ON\n");
		}
		sleep(5);
		led_state = BREATH_LED_IP_mReadReg(LED_IP_BASEADDR,LED_IP_REG0);
		if(led_state == 1)
		{
			BREATH_LED_IP_mWriteReg(LED_IP_BASEADDR,LED_IP_REG0,0);
			xil_printf("Breath LED OFF\n");

		}
		sleep(1);
	}}
