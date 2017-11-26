//***************************************
// HMC5883 51串口测试程序
// 使用单片机STC15W404AS
//****************************************
#ifndef _hmc5883l_H
#define _hmc5883l_H

#include  <delay.H>	
#include  <math.h>    //Keil library  	
#include  <INTRINS.H>
#define   uchar unsigned char
#define   uint  unsigned int	
//使用的端口，请按照以下接线

sbit	SCL=P1^1;      //IIC时钟引脚定义
sbit	SDA=P1^0;      //IIC数据引脚定义


#define	SlaveAddress   0x3C	  //定义器件5883在IIC总线中的从地址
typedef unsigned char BYTE;
typedef unsigned short WORD;

extern BYTE BUF[8];                         //接收数据缓存区
      	
extern signed int u16_x;
extern signed int u16_y;
extern signed int u16_z;

extern int  dis_data;                       //变量
//************

//************
void Init_HMC5883(void);            //初始化5883
void conversion(uint temp_data);

void  Single_Write_HMC5883(uchar REG_Address,uchar REG_data);   //单个写入数据
//uchar Single_Read_HMC5883(uchar REG_Address);                   //单个读取内部寄存器数据
void  Multiple_Read_HMC5883();                                  //连续的读取内部寄存器数据
//以下是模拟iic使用函数-------------
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