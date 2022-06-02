#include "stc8h.h"
#include "stc8h_gpio.h"

#define LED     P55
#define KEY     P54

void main()
{
	unsigned short i;

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Rpu=enable;//4.1kohm上拉电阻
	GPIO_InitStructure.GPIO_NCS=enable;//施密特触发
	GPIO_InitStructure.GPIO_HighSpeed=disable;//端口电平转换速度
	GPIO_InitStructure.GPIO_EnhanceDrv=disable;//增强电流驱动
	GPIO_Init(GPIO5,&GPIO_InitStructure);
	
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Bidirection;
	GPIO_Init(GPIO5,&GPIO_InitStructure);
	
	
	i=0;
	while(1){while(--i);LED=(!LED)&KEY;}
		
}


