#ifndef __STC8H_GPIO_H
#define __STC8H_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stc8h.h"

#define uint8_t unsigned char
#define uint16_t unsigned short
#define enable 1
#define disable 0

#define bool uint8_t
	

typedef enum{
	GPIO0=0,GPIO1,GPIO2,GPIO3,GPIO4,GPIO5,GPIO6,GPIO7
}GPIO_TypeDef;

typedef enum{
	GPIO_Pin_0    =            ((uint8_t)0x01),
	GPIO_Pin_1    =            ((uint8_t)0x02),
	GPIO_Pin_2    =            ((uint8_t)0x04),
	GPIO_Pin_3    =            ((uint8_t)0x08),
	GPIO_Pin_4    =            ((uint8_t)0x10),
	GPIO_Pin_5    =            ((uint8_t)0x20),
	GPIO_Pin_6    =            ((uint8_t)0x40),
	GPIO_Pin_7    =            ((uint8_t)0x80),
	GPIO_Pin_All  =            ((uint8_t)0xFF)
}GPIO_Pin_TypeDef;

typedef enum{
	GPIO_Mode_Bidirection = 0x00,            //准双向口
	GPIO_Mode_Out_PP = 0x01,                 //推挽输出
	GPIO_Mode_IN_FLOATING = 0x02,            //高阻输入
	GPIO_Mode_Out_OD = 0x03,                 //集电极开漏输出
	GPIO_Mode_AF_PP = 0x11,                  //模拟推挽输出
	GPIO_Mode_AIN = 0x12,                    //模拟输入
	GPIO_Mode_AF_OD = 0x13                   //集电极开漏模拟输出
}GPIOMode_TypeDef;

typedef struct
{
	GPIO_Pin_TypeDef GPIO_Pin;
	
	GPIOMode_TypeDef GPIO_Mode;
		
	bool GPIO_Rpu;//4.1kohm上拉电阻
	bool GPIO_NCS;//施密特触发
	bool GPIO_HighSpeed;//端口电平转换速度
	bool GPIO_EnhanceDrv;//增强电流驱动

}GPIO_InitTypeDef;


void GPIO_DeInit(GPIO_TypeDef GPIOx);
void GPIO_Init(GPIO_TypeDef GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);

#ifdef __cplusplus
}
#endif

#endif
