
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/
/*****************基于22.1184Mhz**********************************/

#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
#include	"hmc5883l.h"

/*************	功能说明	**************

功能：测量页面位置
版本号：V3.0
说明：
	1.修改波特率为115200，
	2.修改通讯口为uart1（即，P30,P31）
	3.修缮通讯协议的应答功能

******************************************/

/*************	本地常量声明	**************/


/*************	本地变量声明	**************/





/*************	本地函数声明	**************/



/*************  外部函数和变量声明 *****************/


/*************  串口1初始化函数 *****************/
void UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//结构定义
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//模式,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer2;			//使用波特率,   BRT_Timer1, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//波特率, 一般 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//波特率加倍, ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//中断优先级, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//切换端口,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(必须使用内部时钟)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//内部短路RXD与TXD, 做中继, ENABLE,DISABLE
	USART_Configuration(USART1, &COMx_InitStructure);		//初始化串口1 USART1,USART2

//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1发送一个字符串

}


void main(void)
{
	double angle;

	GetRequest=	0;
	UART_config();
 	Init_HMC5883();
	EA = 1;
	
delay_ms(20);

	while (1)
	{

	Multiple_Read_HMC5883();

	angle= atan2((double)u16_y,(double)u16_x) * (180 / 3.14159265) + 180; // angle in degrees
//	val[0]=((int)angle >> 7) && 
/*
//	if((0 < angle) && (angle < 180) )
//    {
//        angle=angle;
//    }
//    else
//    {
//        angle=360-angle;
//    }
  	TX1_write2buff('*');
	TX1_write2buff('*');	
	TX1_write2buff(((int)angle/100) +0x30);
	TX1_write2buff(((int)angle%100)/10 +0x30);
	TX1_write2buff(((int)angle%10) +0x30);
	TX1_write2buff('*');
	TX1_write2buff('*');
	TX1_write2buff('\n');
*/
		if(GetRequest==1)	 //收到读取请求
		{
			GetRequest=0; //复位请求信号；

			/*********发送数据**************/
			TX1_write2buff(0xF0);
			TX1_write2buff(AVA_Compass);
			TX1_write2buff(myaddr);//
			TX1_write2buff( ( (unsigned int)angle >>7 ) & 0x007f );//
			TX1_write2buff( ( (unsigned int)angle ) & 0x007f);  //液面状态 0：未检测到页面 1；检测到液面
			TX1_write2buff(0xF7);

		//	TX1_write2buff('\n');
		
		}
		delay_ms(5);
	}
}			