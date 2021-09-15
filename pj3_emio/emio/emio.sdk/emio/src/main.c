/*
 * main.c
 *
 *  Created on: 2021��8��20��
 *      Author: DON
 */
#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"

#define GPIOPS_ID XPAR_XGPIOPS_0_DEVICE_ID  //PS�� GPIO���� ID

#define EMIO_KEY 54  //PL_KEY0 ���ӵ�EMIO0

int main()
{
	printf("EMIO TEST!\n");
	XGpioPs gpiops_inst;             //PS��GPIO����ʵ��
	XGpioPs_Config *gpiops_cfg_ptr; //PS��GPIO������Ϣ
	//��������ID����������Ϣ
	gpiops_cfg_ptr=XGpioPs_LookupConfig(GPIOPS_ID);
	//��ʼ����������
	XGpioPs_CfgInitialize(&gpiops_inst,gpiops_cfg_ptr,gpiops_cfg_ptr->BaseAddr);
	//����KEYΪ����
	XGpioPs_SetDirectionPin(&gpiops_inst,EMIO_KEY,0);

	//��ȡ����״̬�����ڿ���LED����
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

