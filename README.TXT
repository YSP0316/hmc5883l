规定： 80~FF为指令段，00~7f为数据段 . 波特率115200 
要求：从设备在接受到正确指令后5m内发送返回信号

使用说明:
master micro control：	F0 	B	CMD_READ 	F7
local micro control：	F0 	B	CMD_WRITE 	DATA1 	F7

CMD_READ : A0|ADDR	(ADDR:1.2...14.15)		example：	A1 --> 对地址为1的设备读,		
CMD_WRITE : B0|ADDR	(ADDR:1.2...14.15)		example：	B2 --> 对地址为2的设备写,或地址为2的设备对主控器写

LiquidLevel_VAL = DATA1 ;  (0/1)

Example：
	-->:		F0	 B 	a1 	F7
	<--:		F0	 B 	b1 	1 	F7
	LiquidLevel_VAL = 1 ;