
//#include <includes.h>
#ifndef __SST25V_H
#define __SST25V_H
#include <stm32f4xx.h>

//  1.   Total  Define 
#define   DF_SPI           SPI2
//------------------------------------------------------------------
#define Read_Data                     0x03       //¶ÁÈ¡´æ´¢Æ÷Êý¾Ý
#define HighSpeedReadData             0x0B       //¿ìËÙ¶ÁÈ¡´æ´¢Æ÷Êý¾Ý
#define SectorErace_4KB               0x20       //ÉÈÇø²Á³ý
#define BlockErace_32KB               0x52       //32KB¿é²Á³ý
#define BlockErace_64KB               0xD8       //64KB¿é²Á³ý
#define ChipErace                     0xC7       //Æ¬²Á³ý
 
#define Byte_Program                  0x02       //Ò³Ãæ±à³Ì--Ð´Êý¾Ý  
#define AAI_WordProgram               0xAD
#define ReadStatusRegister            0x05       //¶Á×´Ì¬¼Ä´æÆ÷
#define EnableWriteStatusRegister     0x50
#define WriteStatusRegister           0x01       //Ð´×´Ì¬¼Ä´æÆ÷

#define WriteEnable                   0x06       //Ð´Ê¹ÄÜ£¬ÉèÖÃ×´Ì¬¼Ä´æÆ÷
#define WriteDisable                  0x04       //Ð´½ûÖ¹
#define ReadDeviceID                  0xAB       //»ñÈ¡Éè±¸IDÐÅÏ¢

#define ReadJedec_ID                  0x9F       //JEDECµÄIDÐÅÏ¢

#define EBSY                          0X70
#define DBSY                          0X80

#define Dummy_Byte                    0xFF

//  3.   PIN   
#define SST25V_CS_LOW()      GPIO_ResetBits(GPIOD,GPIO_Pin_14)  
#define SST25V_CS_HIGH()     GPIO_SetBits(GPIOD,GPIO_Pin_14)

#define SST25V_WP_HIGH()   GPIO_SetBits(GPIOD,GPIO_Pin_15)
#define SST25V_WP_LOW()    GPIO_SetBits(GPIOD,GPIO_Pin_15) 







extern void SST25V_Init(void);
extern u8   SST25V_ByteRead(u32 ReadAddr);
extern void SST25V_strWrite(u8 *p, u32 WriteAddr,u16 length);    
extern u8  SST25V_OneSector_Write(u8 *p,  u32  addr,  u32 len);

void SST25V_BufferRead(u8* pBuffer, u32 ReadAddr, u16 NumByteToRead);

//extern u8 SPI_Flash_SendByte(u8 byte);
//extern u8 SPI_Flash_ReceiveByte(void);
extern void SST25V_ByteWrite(u8 Byte, u32 WriteAddr);
extern void SST25V_BufferWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToRead); 

extern void SST25V_SectorErase_4KByte(u32 Addr);
void SST25V_BlockErase_32KByte(u32 Addr);
void SST25V_BlockErase_64KByte(u32 Addr);

u8 SST25V_ReadStatusRegister(void);
void SST25V_WriteEnable(void);
void SST25V_WriteDisable(void);

void SST25V_EnableWriteStatusRegister(void);
void SST25V_WriteStatusRegister(u8 Byte);
void SST25V_WaitForWriteEnd(void);


u16 SST25V_ReadManuID_DeviceID(u32 ReadManu_DeviceID_Addr);

extern u8 SPI_Flash_SendByte(u8 data);
extern u8 SPI_Flash_ReceiveByte(void);   



#endif 

