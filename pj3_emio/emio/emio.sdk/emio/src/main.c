/*
 * main.c
 *
 *  Created on: 2021年8月20日
 *      Author: DON
 */
#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"

#define GPIOPS_ID XPAR_XGPIOPS_0_DEVICE_ID  //PS端 GPIO器件 ID

#define EMIO_KEY 54  //PL_KEY0 连接到EMIO0

int main()
{
	printf("EMIO TEST!\n");
	XGpioPs gpiops_inst;             //PS端GPIO驱动实例
	XGpioPs_Config *gpiops_cfg_ptr; //PS端GPIO配置信息
	//根据器件ID查找配置信息
	gpiops_cfg_ptr=XGpioPs_LookupConfig(GPIOPS_ID);
	//初始化器件驱动
	XGpioPs_CfgInitialize(&gpiops_inst,gpiops_cfg_ptr,gpiops_cfg_ptr->BaseAddr);
	//设置KEY为输入
	XGpioPs_SetDirectionPin(&gpiops_inst,EMIO_KEY,0);

	//读取按键状态，用于控制LED亮灭
	while(1)
	{
		if(XGpioPs_ReadPin(&gpiops_inst,EMIO_KEY))
		{
			printf("KEY=1\r\n");
		}
		else
			printf("KEY=0\r\n");
	}
	return 0;
}

