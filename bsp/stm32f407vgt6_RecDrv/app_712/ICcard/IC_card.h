/*
     IC  card .h
*/


#ifndef    IC_COMMON   
#define    IC_COMMON   


#include <rtthread.h> 
#include <rthw.h>
#include "stm32f4xx.h"
#include "usart.h"
#include "board.h"
#include <serial.h>

#include  <stdlib.h>//数字转换成字符串
#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <stdarg.h>
#include "App_moduleConfig.h" 



#define b_CardEdge   0x0001



extern unsigned char IC_CardInsert;//1:IC卡插入正确  2:IC卡插入错误
extern unsigned char IC_Check_Count;
extern unsigned char administrator_card; 
extern 	u8		  powerOn_first;	 //    首次上电后不判断拔卡  


extern void CheckICInsert(void);
extern void KeyBuzzer(unsigned char num); 





#endif 
