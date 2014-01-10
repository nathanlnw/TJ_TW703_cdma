#ifndef    _VDR   
#define  _VDR  

#include "App_moduleConfig.h" 







typedef  struct 
{
  u16  V_07H_Write;   // 07 H  位置  
  u16  V_08H_Write;	  // 08 H  位置
  u16  V_09H_Write;	  // 09H  位置
  u16  V_10H_Write;	  // 10 H  位置
  u16  V_11H_Write;   // 11 H  位置  
  u16  V_12H_Write;   // 12 H	位置
  u16  V_13H_Write;   // 13H  位置
  u16  V_14H_Write;   // 14 H	位置
  u16  V_15H_Write;	  // 15 H 位置     

  u16  V_07H_Read;   // 07 H  位置  
  u16  V_08H_Read;	  // 08 H  位置
  u16  V_09H_Read;	  // 09H  位置
  u16  V_10H_Read;	  // 10 H  位置
  u16  V_11H_Read;   // 11 H  位置  
  u16  V_12H_Read;   // 12 H	位置
  u16  V_13H_Read;   // 13H  位置
  u16  V_14H_Read;   // 14 H	位置
  u16  V_15H_Read;	  // 15 H 位置      
  
}VDR_INDEX;

extern VDR_INDEX      Vdr_Wr_Rd_Offset;    



typedef struct
{
        //-----------------------------------
        u8  Lati[4];  //    纬度
		u8  Longi[4]; //    经度

		//-----------------------------------
		u8  H_08[126]; //   08H buf
		u8  H_08_BAK[126]; //   08H buf 
		u8  H_08_saveFlag; //   存储标志位
		u8  H_09[666];//   09H  buf
		u8  H_09_saveFlag; //
		u8  H_10[234]; //   10H buf
		u8  H_10_saveFlag; 
		u8  H_11[50];//   11H  buf
		u8  H_11_saveFlag;
		u8	H_12[25]; //	12H buf
		u8  H_12_saveFlag;
		u8  H_13[7];//  13H  buf
		u8  H_13_saveFlag;
		u8  H_14[7]; //   14H buf
		u8  H_14_saveFlag;
		u8  H_15[133];//	 15H  buf
		u8  H_15_Set_StartDateTime[6];  // 中心设置的采集时间
		u8  H_15_Set_EndDateTime[6];  //  中心设置的采集结束时间 
		u8  H_15_saveFlag;  
} VDR_DATA;

extern VDR_DATA   VdrData;  //  行驶记录仪的databuf



typedef struct
{
  u16  Running_state_enable;   //工作状态   
  u16  Run_baseon_spd_10s_couter;  //   基于有速度行驶 10s
  





}VDR_TRIG_STATUS;
extern  VDR_TRIG_STATUS  VDR_TrigStatus;

//==================================================================================================
// 第五部分 :   以下是行车记录仪相关协议 即 附录A   
//==================================================================================================

extern void total_ergotic(void);    
extern void  vdr_erase(void);     

extern u16   stuff_drvData(u8 type,u16 Start_recNum,u16 REC_nums,u8 *dest);


extern void  VDR_product_08H_09H_10H(void);
extern void  VDR_product_11H_Start(void);
extern void  VDR_product_11H_End(void);
extern void  VDR_product_12H(u8  value); 
extern void  VDR_product_13H(u8  value); 
extern void  VDR_product_14H(u8 cmdID);
extern void  VDR_product_15H(u8  value);   
extern void  VDR_get_15H_StartEnd_Time(u8  *Start, u8 *End);  




extern u16   get_00h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_01h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_02h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_03h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_04h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_05h(u8  *p_in ,u16 inLen, u8 *p_out);  
extern u16   get_06h(u8  *p_in ,u16 inLen, u8 *p_out);    
extern u16   get_07h(u8  *p_in ,u16 inLen, u8 *p_out);       


extern u16 get_08h( u16 indexnum,u8 *p);
extern u16 get_09h( u16 indexnum,u8 *p);  
extern u16 get_10h( u16 indexnum,u8 *p);  
extern u16 get_11h( u16 indexnum,u8 *p);  
extern u16 get_12h( u16 indexnum,u8 *p);  
extern u16 get_13h( u16 indexnum,u8 *p);  
extern u16 get_14h( u16 indexnum,u8 *p); 
extern u16 get_15h( u16 indexnum,u8 *p);   





extern u16  vdr_creat_08h( u16 indexnum,u8 *p, u16 inLen); 
extern u16  vdr_creat_09h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_10h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_11h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_12h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_13h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_14h( u16 indexnum,u8 *p, u16 inLen) ;
extern u16  vdr_creat_15h( u16 indexnum,u8 *p, u16 inLen) ; 









#endif 
