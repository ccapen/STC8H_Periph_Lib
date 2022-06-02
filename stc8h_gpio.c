#include "stc8h_gpio.h"

void GPIO_DeInit(GPIO_TypeDef GPIOx){
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_Init(GPIOx,&GPIO_InitStructure);
}
void GPIO_Init(GPIO_TypeDef GPIOx, GPIO_InitTypeDef* GPIO_InitStruct){
	bit PxM1,PxM0;
	PxM1=(GPIO_InitStruct->GPIO_Mode)&0x2;
	PxM0=(GPIO_InitStruct->GPIO_Mode)&0x1;
	switch(GPIOx){
		case 0:{
			if(PxM1) P0M1 |= GPIO_InitStruct->GPIO_Pin;
			else P0M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P0M0 |= GPIO_InitStruct->GPIO_Pin;
			else P0M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 1:{
			if(PxM1) P1M1 |= GPIO_InitStruct->GPIO_Pin;
			else P1M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P1M0 |= GPIO_InitStruct->GPIO_Pin;
			else P1M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 2:{
			if(PxM1) P2M1 |= GPIO_InitStruct->GPIO_Pin;
			else P2M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P2M0 |= GPIO_InitStruct->GPIO_Pin;
			else P2M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 3:{
			if(PxM1) P3M1 |= GPIO_InitStruct->GPIO_Pin;
			else P3M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P3M0 |= GPIO_InitStruct->GPIO_Pin;
			else P3M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 4:{
			if(PxM1) P4M1 |= GPIO_InitStruct->GPIO_Pin;
			else P4M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P4M0 |= GPIO_InitStruct->GPIO_Pin;
			else P4M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 5:{
			if(PxM1) P5M1 |= GPIO_InitStruct->GPIO_Pin;
			else P5M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P5M0 |= GPIO_InitStruct->GPIO_Pin;
			else P5M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 6:{
			if(PxM1) P6M1 |= GPIO_InitStruct->GPIO_Pin;
			else P6M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P6M0 |= GPIO_InitStruct->GPIO_Pin;
			else P6M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		case 7:{
			if(PxM1) P7M1 |= GPIO_InitStruct->GPIO_Pin;
			else P7M1 &= (~GPIO_InitStruct->GPIO_Pin);
			if(PxM0) P7M0 |= GPIO_InitStruct->GPIO_Pin;
			else P7M0 &= (~GPIO_InitStruct->GPIO_Pin);
			break;
		}
		default:break;
	}
	if((GPIO_InitStruct->GPIO_Mode)&0x10) *(uint8_t xdata*)(((uint16_t)0xfe38)+GPIOx) &= (~GPIO_InitStruct->GPIO_Pin);
	else *(uint8_t xdata*)(((uint16_t)0xfe30)+GPIOx) |= (GPIO_InitStruct->GPIO_Pin);//数字信号通道开关

	if(GPIO_InitStruct->GPIO_Rpu) *(uint8_t xdata*)(((uint16_t)0xfe10)+GPIOx) |= GPIO_InitStruct->GPIO_Pin;
	else *(uint8_t xdata*)(((uint16_t)0xfe10)+GPIOx) &= (~GPIO_InitStruct->GPIO_Pin);//4.1kohm上拉电阻

	if(GPIO_InitStruct->GPIO_NCS) *(uint8_t xdata*)(((uint16_t)0xfe18)+GPIOx) &= (~GPIO_InitStruct->GPIO_Pin);
	else *(uint8_t xdata*)(((uint16_t)0xfe10)+GPIOx) |= (GPIO_InitStruct->GPIO_Pin);//施密特触发

	if(GPIO_InitStruct->GPIO_HighSpeed) *(uint8_t xdata*)(((uint16_t)0xfe18)+GPIOx) &= (~GPIO_InitStruct->GPIO_Pin);
	else *(uint8_t xdata*)(((uint16_t)0xfe10)+GPIOx) |= (GPIO_InitStruct->GPIO_Pin);//端口电平转换速度

	if(GPIO_InitStruct->GPIO_EnhanceDrv) *(uint8_t xdata*)(((uint16_t)0xfe18)+GPIOx) &= (~GPIO_InitStruct->GPIO_Pin);
	else *(uint8_t xdata*)(((uint16_t)0xfe10)+GPIOx) |= (GPIO_InitStruct->GPIO_Pin);//增强电流驱动
}
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct){
	GPIO_InitStruct->GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStruct->GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct->GPIO_Rpu=disable;//0;
	GPIO_InitStruct->GPIO_NCS=enable;//0;
	GPIO_InitStruct->GPIO_HighSpeed=disable;//1;
	GPIO_InitStruct->GPIO_EnhanceDrv=disable;//1;
}
