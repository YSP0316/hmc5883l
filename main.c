
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
/*****************����22.1184Mhz**********************************/

#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
#include	"hmc5883l.h"

/*************	����˵��	**************

���ܣ�����ҳ��λ��
�汾�ţ�V3.0
˵����
	1.�޸Ĳ�����Ϊ115200��
	2.�޸�ͨѶ��Ϊuart1������P30,P31��
	3.����ͨѶЭ���Ӧ����

******************************************/

/*************	���س�������	**************/


/*************	���ر�������	**************/





/*************	���غ�������	**************/



/*************  �ⲿ�����ͱ������� *****************/


/*************  ����1��ʼ������ *****************/
void UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//�ṹ����
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//ģʽ,       UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer2;			//ʹ�ò�����,   BRT_Timer1, BRT_Timer2 (ע��: ����2�̶�ʹ��BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//������, һ�� 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//��������,   ENABLE��DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//�����ʼӱ�, ENABLE��DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//�ж�����,   ENABLE��DISABLE
	COMx_InitStructure.UART_Polity    = PolityLow;			//�ж����ȼ�, PolityLow,PolityHigh
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//�л��˿�,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17(����ʹ���ڲ�ʱ��)
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;		//�ڲ���·RXD��TXD, ���м�, ENABLE,DISABLE
	USART_Configuration(USART1, &COMx_InitStructure);		//��ʼ������1 USART1,USART2

//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1����һ���ַ���

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
		if(GetRequest==1)	 //�յ���ȡ����
		{
			GetRequest=0; //��λ�����źţ�

			/*********��������**************/
			TX1_write2buff(0xF0);
			TX1_write2buff(AVA_Compass);
			TX1_write2buff(myaddr);//
			TX1_write2buff( ( (unsigned int)angle >>7 ) & 0x007f );//
			TX1_write2buff( ( (unsigned int)angle ) & 0x007f);  //Һ��״̬ 0��δ��⵽ҳ�� 1����⵽Һ��
			TX1_write2buff(0xF7);

		//	TX1_write2buff('\n');
		
		}
		delay_ms(5);
	}
}			