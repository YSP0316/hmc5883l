//***************************************
// HMC5883 51���ڲ��Գ���
// ʹ�õ�Ƭ��STC15W404AS
//****************************************
#ifndef _hmc5883l_H
#define _hmc5883l_H

#include  <delay.H>	
#include  <math.h>    //Keil library  	
#include  <INTRINS.H>
#define   uchar unsigned char
#define   uint  unsigned int	
//ʹ�õĶ˿ڣ��밴�����½���

sbit	SCL=P1^1;      //IICʱ�����Ŷ���
sbit	SDA=P1^0;      //IIC�������Ŷ���


#define	SlaveAddress   0x3C	  //��������5883��IIC�����еĴӵ�ַ
typedef unsigned char BYTE;
typedef unsigned short WORD;

extern BYTE BUF[8];                         //�������ݻ�����
      	
extern signed int u16_x;
extern signed int u16_y;
extern signed int u16_z;

extern int  dis_data;                       //����
//************

//************
void Init_HMC5883(void);            //��ʼ��5883
void conversion(uint temp_data);

void  Single_Write_HMC5883(uchar REG_Address,uchar REG_data);   //����д������
//uchar Single_Read_HMC5883(uchar REG_Address);                   //������ȡ�ڲ��Ĵ�������
void  Multiple_Read_HMC5883();                                  //�����Ķ�ȡ�ڲ��Ĵ�������
//������ģ��iicʹ�ú���-------------
//void Delay5us();
//void Delay5ms();
void HMC5883_Start();
void HMC5883_Stop();
void HMC5883_SendACK(bit ack);
bit  HMC5883_RecvACK();
void HMC5883_SendByte(BYTE dat);
BYTE HMC5883_RecvByte();
void HMC5883_ReadPage();
void HMC5883_WritePage();
//-----------------------------------

#endif