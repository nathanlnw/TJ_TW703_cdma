#include <stdio.h>

#include "Menu_Include.h"
#include <string.h>

#include "stm32f4xx.h"
unsigned char XinhaoStatus[20]={"�ź���״̬:00000000"};
unsigned char XinhaoStatusBAK[20]={"�ź���״̬:00000000"};


unsigned int  tzxs_value=6000;
unsigned char send_data[10];
MB_SendDataType mb_senddata;

unsigned int CounterBack=0;
unsigned char UpAndDown=1;//�����������˵�ѡ�����

unsigned char Dis_date[22]={"2000/00/00  00:00:00"};//20
unsigned char Dis_speDer[20]={"000 km/h    000 ��"};

unsigned char GPS_Flag=0,Gprs_Online_Flag=0;//��¼gps gprs״̬�ı�־


unsigned char speed_time_rec[15][6];//��  ��  ��  ʱ  ��  �ٶ�
unsigned char DriverName[22],DriverCardNUM[20];//��IC��������ļ�ʻԱ�����ͼ�ʻ֤����
unsigned char ServiceNum[13];//�豸��Ψһ�Ա���,IMSI����ĺ�12λ

unsigned char KeyValue=0;
unsigned char KeyCheck_Flag[4]={0,0,0,0};             

unsigned char ErrorRecord=0;//ƣ�ͳ��ټ�¼   ƣ��ʱ�����Ϊ1����ʱ�����Ϊ2,���������0
PilaoRecord PilaoJilu[12];
ChaosuRecord ChaosuJilu[20];

unsigned char StartDisTiredExpspeed=0;//��ʼ��ʾƣ�ͻ��߳��ټ�ʻ�ļ�¼,���ж���ʾʱ����Ϣ����ʱ��
unsigned char tire_Flag=0,expsp_Flag=0;//ƣ�ͼ�ʻ/���ټ�ʻ  �м�¼Ϊ1(��ʾ�м�����¼)���޼�¼Ϊ2���鿴��¼��Ϊ3(��ʾ��down�����鿴)
unsigned char pilaoCounter=0,chaosuCounter=0;//��¼����ƣ�ͼ�ʻ�ͳ��ټ�ʻ������
unsigned char pilaoCouAscii[2],chaosuCouAscii[2];
DispMailBoxInfor LCD_Post,GPStoLCD,OtherToLCD,PiLaoLCD,ChaoSuLCD;

unsigned char SetVIN_NUM=1;// :���ó��ƺ���  2:����VIN
unsigned char OK_Counter=0;//��¼�ڿ�ݲ˵���ok�����µĴ���
unsigned char Screen_In=0,Screen_in0Z=0; //��¼��ѡ����ѡ�еĺ���

unsigned char OKorCancel=1,OKorCancel2=1,OKorCancelFlag=1;
unsigned char SetTZXSFlag=0,SetTZXSCounter=0;//SetTZXSFlag  1:У׼��������ϵ����ʼ  2:У׼��������ϵ������
                                                 //    1���ݵ���(... .../���)  2:usb�豸�γ�
unsigned char OUT_DataCounter=0;//ָ��������������  1��2��3
unsigned char DataOutStartFlag=0;//���ݵ�����־
unsigned char DataOutOK=0;

unsigned char Rx_TZXS_Flag=0;

unsigned char battery_flag=0,tz_flag=0;
unsigned char USB_insertFlag=1;


unsigned char BuzzerFlag=0;//=1��1��  ��11��2��

unsigned char DaYin=0;//�������´�ӡ��Ϊ101��2s��Ϊ1����ʼ��ӡ(�ж��Ƿ�ȡ�����ݣ�û����ʾ�����������ݴ�ӡ)
unsigned char DaYinDelay=0;

unsigned char FileName_zk[11];

//==============12*12========���ֿ��к��ֵĵ���==========
unsigned char test_00[24],Read_ZK[24];
unsigned char DisComFlag=0;
unsigned char ICcard_flag=0;



unsigned char DisInfor_Menu[8][20];
unsigned char DisInfor_Affair[8][20];

unsigned char UpAndDown_nm[4]={0xA1,0xFC,0xA1,0xFD};//�� ��

//========================================================================
unsigned char UpdataDisp[8]={"001/000"};//������������
unsigned char BD_updata_flag=0;//����������u���ļ��ı�־
unsigned int  FilePageBD_Sum=0;//��¼�ļ���С�����ļ���С/514
unsigned int  bd_file_exist=0;//��������Ҫ�������ļ�
unsigned char device_version[30]={"�����汾:gghypt V1.1"};  //{"�����汾:V BD 2.00"};   // ��������ƽ̨�Խ�  
unsigned char bd_version[20]={"ģ��汾:V 17.NXC.01"};
unsigned char bd_version2[20]={"ģ��汾:V 20.NXC.01"}; 



unsigned char ISP_Updata_Flag=0; //Զ�������������������ʾ��־   1:��ʼ����  2:�������

unsigned char data_tirexps[120];
unsigned char OneKeyCallFlag=0;   //  һ������
unsigned char BD_upgrad_contr=0; //  ������������
unsigned char print_rec_flag=0;  // ��ӡ��¼��־ 

u8  print_workingFlag=0;  // ��ӡ�����С���


u8 CarSet_0_counter=1;//��¼���ó�����Ϣ����������1:���ƺ�2:����3:��ɫ

//------------ ʹ��ǰ������� ------------------
unsigned char Menu_Car_license[10];//��ų��ƺ���
u8 Menu_VechileType[10];  //  ��������
u8 Menu_VecLogoColor[10]; // ������ɫ
u8 Menu_color_num=0;   // JT415    1  �� 2 �� 3 �� 4 �� 9����
u8 Menu_Vin_Code[17];
u8 Menu_sim_Code[12];//����Ҫ������11λ�ֻ�����
u8 License_Not_SetEnable=1;//   1:���ƺ�δ����
u8 menu_type_flag=0,menu_color_flag=0;

u8 CAR_SET_FLAG=0;
//�洢�������Ӧ��Ϣ
u8 Menu_MainDns[20];
u8 Menu_AuxDns[20];
u8 Menu_MainIp[20]={"   .   .   .   :    "};//000.000.000.000:0000   20λ
u8 Menu_AuxIp[20]={"   .   .   .   :    "};//000.000.000.000:0000   20λ;
u8 Menu_Apn[20];


u8 Password_correctFlag=0;  // ������ȷ
u8 Dis_deviceid_flag=0;
u8 MENU_set_carinfor_flag=0;//�˵����뵥�����ó�����Ϣ
u8 Menu_voice_value=0;//�洢TTS����ֵ
ALIGN(RT_ALIGN_SIZE)  
MENUITEM *pMenuItem;   


//�����·���Ϣ��������������ʾ��Ϣ����
void Cent_To_Disp(void)
{
	if(Dis_deviceid_flag==1)
		{
		Dis_deviceid_flag=2; 
		lcd_fill(0);
		lcd_text12(0,3,"�豸ID:",7,LCD_MODE_SET); 
		lcd_text12(42,3,(char *)SimID_12D,12,LCD_MODE_SET);
		lcd_text12(0,18,"�ն�ID:",7,LCD_MODE_SET); 
		lcd_text12(42,18,(char *)SimID_12D+5,7,LCD_MODE_SET);
		lcd_update_all();  
		}

}
void version_disp(void)
{
	lcd_fill(0);
	lcd_text12(0, 3,(char *)device_version,strlen((const char*)device_version),LCD_MODE_SET); 
	if(Module_3017A==GPS_MODULE_TYPE)
	   lcd_text12(0,19,(char *)bd_version,sizeof(bd_version),LCD_MODE_SET);
	else
	   lcd_text12(0,19,(char *)bd_version2,sizeof(bd_version2),LCD_MODE_SET); 	
	lcd_update_all();
}
//  0   1            34             67
//(3)  1 [2-33]   2 [35-66]   3 [68-99]
void ReadPiLao(unsigned char NumPilao)
{
unsigned char i=0,j=0;
unsigned char Read_PilaoData[32];

memset(Read_PilaoData,0,sizeof(Read_PilaoData));
data_tirexps[0]=NumPilao;//������
for(i=0,j=0;i<NumPilao;i++,j++)
	data_tirexps[1+j*31]=i+1;	
for(i=0;i<NumPilao;i++)
	{
	Api_DFdirectory_Read(tired_warn,Read_PilaoData,31,0,i); // ��new-->old  ��ȡ
	memcpy(&data_tirexps[i*31+2],Read_PilaoData,30);
	}
}
void ReadEXspeed(unsigned char NumExspeed)
{
unsigned char i=0,j=0;
unsigned char Read_ChaosuData[32];

memset(Read_ChaosuData,0,sizeof(Read_ChaosuData));
data_tirexps[0]=NumExspeed;//������
for(i=0,j=0;i<NumExspeed;i++,j++)
	data_tirexps[1+j*32]=i+1;	
for(i=0;i<NumExspeed;i++)
	{
	Api_DFdirectory_Read(spd_warn,Read_ChaosuData,32,0,i); // ��new-->old  ��ȡ
    memcpy(&data_tirexps[i*32+2],Read_ChaosuData,31);
	}
}
void Dis_pilao(unsigned char *p)
{
unsigned char i,j;
pilaoCounter=*p;
if(pilaoCounter==0) return;
if(pilaoCounter>12) return;


pilaoCouAscii[0]=pilaoCounter/10+0x30;
pilaoCouAscii[1]=pilaoCounter%10+0x30;
for(i=0;i<pilaoCounter;i++)
	{
	PilaoJilu[i].Num=*(p+1+i*31);
	memcpy(PilaoJilu[i].Drver_Name,p+2+i*31,18);
	memcpy(PilaoJilu[i].StartTime,p+20+i*31,6);
	memcpy(PilaoJilu[i].EndTime,p+26+i*31,6);
	for(j=0;j<6;j++)
		PilaoJilu[i].StartTime[j]=(PilaoJilu[i].StartTime[j]>>4)*10+(PilaoJilu[i].StartTime[j]&0x0f);
	for(j=0;j<6;j++)
		PilaoJilu[i].EndTime[j]=(PilaoJilu[i].EndTime[j]>>4)*10+(PilaoJilu[i].EndTime[j]&0x0f);

	if((PilaoJilu[i].StartTime[0]>99)||(PilaoJilu[i].StartTime[1]>12)||(PilaoJilu[i].StartTime[2]>31)||PilaoJilu[i].StartTime[3]>23||PilaoJilu[i].StartTime[4]>59||PilaoJilu[i].StartTime[5]>59)
		ErrorRecord=1;
	if((PilaoJilu[i].EndTime[0]>99)||(PilaoJilu[i].EndTime[1]>12)||(PilaoJilu[i].EndTime[2]>31)||PilaoJilu[i].EndTime[3]>23||PilaoJilu[i].EndTime[4]>59||PilaoJilu[i].EndTime[5]>59)
		ErrorRecord=1;
	}


}
void Dis_chaosu(unsigned char *p)
{
unsigned char i,j;
chaosuCounter=*p;
if(chaosuCounter==0) return;
if(chaosuCounter>20) return;

chaosuCouAscii[0]=chaosuCounter/10+0x30;
chaosuCouAscii[1]=chaosuCounter%10+0x30;

for(i=0;i<chaosuCounter;i++)
	{
	ChaosuJilu[i].Num=*(p+1+i*46);
	memcpy(ChaosuJilu[i].Drver_Name,p+2+i*32,18);
	memcpy(ChaosuJilu[i].StartTime,p+20+i*32,6);
	memcpy(ChaosuJilu[i].EndTime,p+26+i*32,6);

	for(j=0;j<6;j++)
		ChaosuJilu[i].StartTime[j]=(ChaosuJilu[i].StartTime[j]>>4)*10+(ChaosuJilu[i].StartTime[j]&0x0f);
	for(j=0;j<6;j++)
		ChaosuJilu[i].EndTime[j]=(ChaosuJilu[i].EndTime[j]>>4)*10+(ChaosuJilu[i].EndTime[j]&0x0f);	
	ChaosuJilu[i].Speed=*(p+32+i*32);

	if((ChaosuJilu[i].StartTime[0]>99)||(ChaosuJilu[i].StartTime[1]>12)||(ChaosuJilu[i].StartTime[2]>31)||ChaosuJilu[i].StartTime[3]>23||ChaosuJilu[i].StartTime[4]>59||ChaosuJilu[i].StartTime[5]>59)
		ErrorRecord=2;
	if((ChaosuJilu[i].EndTime[0]>99)||(ChaosuJilu[i].EndTime[1]>12)||(ChaosuJilu[i].EndTime[2]>31)||ChaosuJilu[i].EndTime[3]>23||ChaosuJilu[i].EndTime[4]>59||ChaosuJilu[i].EndTime[5]>59)
		ErrorRecord=2;
	}
}
