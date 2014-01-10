#ifndef H_DATAFLASH
#define H_DATAFLASH


//-------------------------------------------------------------


//flash 信息结构体
#pragma pack(1)
typedef struct
{
 u8 All_Picture_num;           //当前数据存储总的图片数(最大为30 范围为0~30)
 u8 first_index_num;           //第一次存储的索引的位置 范围为 1~30
 u8 last_index_num;            //最后一次存储的索引的位置 范围为 1~30
 u16  page_start;              //当前已经存储图像的起始页
 u16  page_end;                //当前已经存储图像的末尾页
 u8   current_photoNum;             //当前拍照图片的序号
} DF_picture_Status;

typedef struct
{
 u8		Picture_num;       //图片序号
 u8		last_package; 	 //最后一个package的标记，最后一个package时为1
 u8		block_num;		    //当前存储的内容在图片中的块的序号
 u16	data_long;         //图片当前存储的页的字节数
}DF_Picture_block;

typedef struct 
{
 u16    page_start;      //起始页
 u16    page_end;        //结束页
 u8	    block_total;       //图片占用的页的数量
 u8     User_information[17]; 
 }DF_index;

typedef struct
{
 u16    page_start;     //起始页
 u16    page_end; 		  //结束页
 u8	   block_total;	  //图片占用的页的数量
 u8	   Have_picture;	  // 1:有图片 。0:无图片
} DF_temp_picture_Status;
#pragma pack()


extern void Write_IPandPort_Setting(void);
extern void  Read_IPandPort_Setting(void); 


//====================================================
extern u8  DF_Write_RecordAdd(u32 Wr_Address,u32 Rd_Address, u8 Type);
extern u8  DF_Read_RecordAdd(u32 Wr_Address,u32 Rd_Address, u8 Type); 



#endif
