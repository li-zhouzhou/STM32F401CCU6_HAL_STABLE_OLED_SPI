#ifndef __OLED_H
#define __OLED_H
//////////////////////////////////////////////////////////////////////////////////	 
/*
���ڣ�2022.02.09
�ںˣ�����ԭ��OLED
�޸ģ���������ԭ��OLED��С�۷�OLED�ı�
���ݣ�����BMP��ʾ�ͺ�����ʾ
��վ����˵��_С�۷䣺https://www.xmf393.com/2020/02/16/2020021610/
��վ����˵��_robank��https://www.xmf393.com/2020/02/16/2020021610/
*/
////////////////////////////////////////////////////////////////////////////////// 	

//========��ֲ��ʱ�򣬸�����ѡоƬ������Ӧ��ͷ�ļ�==========
#include "stm32f4xx_hal.h"    						  
//-----------------OLED�˿ڶ���----------------  		
//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 	0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	  
  						  
//========��ֲ��ʱ�򣬸������ŷ�������޸�==========

//ʹ��4�ߴ��нӿ�ʱʹ�� 
#define OLED_CS_GPIO			GPIOA
#define OLED_CS_GPIO_PIN		GPIO_PIN_5
#define OLED_DC_GPIO			GPIOA
#define OLED_DC_GPIO_PIN		GPIO_PIN_4
#define OLED_SCLK_GPIO			GPIOA
#define OLED_SCLK_GPIO_PIN		GPIO_PIN_1
#define OLED_SDIN_GPIO			GPIOA
#define OLED_SDIN_GPIO_PIN		GPIO_PIN_2
#define OLED_RES_GPIO			GPIOA
#define OLED_RES_GPIO_PIN		GPIO_PIN_3

//CS
#define OLED_CS_Clr()  HAL_GPIO_WritePin(OLED_CS_GPIO, OLED_CS_GPIO_PIN, GPIO_PIN_RESET)
#define OLED_CS_Set()  HAL_GPIO_WritePin(OLED_CS_GPIO, OLED_CS_GPIO_PIN, GPIO_PIN_SET)

//RES
#define OLED_RST_Clr() HAL_GPIO_WritePin(OLED_RES_GPIO, OLED_RES_GPIO_PIN, GPIO_PIN_RESET)//NOT USE
#define OLED_RST_Set() HAL_GPIO_WritePin(OLED_RES_GPIO, OLED_RES_GPIO_PIN, GPIO_PIN_SET)//NOT USE

//DC
#define OLED_DC_Clr() HAL_GPIO_WritePin(OLED_DC_GPIO, OLED_DC_GPIO_PIN, GPIO_PIN_RESET)
#define OLED_DC_Set() HAL_GPIO_WritePin(OLED_DC_GPIO, OLED_DC_GPIO_PIN, GPIO_PIN_SET)

//SCLK,D0
#define OLED_SCLK_Clr() HAL_GPIO_WritePin(OLED_SCLK_GPIO, OLED_SCLK_GPIO_PIN, GPIO_PIN_RESET)
#define OLED_SCLK_Set() HAL_GPIO_WritePin(OLED_SCLK_GPIO, OLED_SCLK_GPIO_PIN, GPIO_PIN_SET)

//SDIN,D1
#define OLED_SDIN_Clr() HAL_GPIO_WritePin(OLED_SDIN_GPIO, OLED_SDIN_GPIO_PIN, GPIO_PIN_RESET)
#define OLED_SDIN_Set() HAL_GPIO_WritePin(OLED_SDIN_GPIO, OLED_SDIN_GPIO_PIN, GPIO_PIN_SET)

 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

//OLED�����ú���
void OLED_WR_Byte(unsigned char dat,unsigned char cmd);   
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t size);
void OLED_ShowCHinese(unsigned char x,unsigned char y,unsigned char no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
#endif
