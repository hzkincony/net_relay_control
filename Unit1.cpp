//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString light_img_1_ON,light_img_2_ON,light_img_3_ON,light_img_4_ON,light_img_5_ON,light_img_6_ON,light_img_7_ON,light_img_8_ON;
AnsiString light_img_1_OFF,light_img_2_OFF,light_img_3_OFF,light_img_4_OFF,light_img_5_OFF,light_img_6_OFF,light_img_7_OFF,light_img_8_OFF;

int time_i=1;  //�������������������255���Զ����ص�1

void __fastcall TForm1::WndProc(Winapi::Messages::TMessage &Message)
{
 switch(Message.Msg)
  {
    case WM_SYSCOMMAND:
     {
       switch(Message.WParam)
        {
		  case SC_CLOSE    : break; // �ر�
          case SC_MAXIMIZE : break; // ���
		  case SC_MINIMIZE : {Form1->Hide();break;} // ��С��
		  case SC_RESTORE  : break; // ��ԭ
        }
     } break;
  }
 TForm::WndProc(Message);
}

////INDY HTTP CLIENT Get���� ����
String  GetData(String url,String data)
{
	 TIdHTTP *IdHttp1;
	 try{
			 IdHttp1=new TIdHTTP(Application);
			IdHttp1->Request->ContentType="application/x-www-form-urlencoded";
			if(IdHttp1==NULL)
			 {
				return "";
			 }

			AnsiString Url=url+"?"+data;
			String str =IdHttp1->Get(Url);
			delete   IdHttp1;
			return  str;
	 }
	 catch(Exception &e)
		{
		 if(IdHttp1!=NULL)
			delete IdHttp1;
			return "";
		 }

}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "c:\Net_Relay_Control.INI" );

//------------------------------�����������������Ϣ---------------------------
   Label1->Caption = ini->ReadString( "Device_Config", "Light1",  "Light1" ) ;
   Label2->Caption = ini->ReadString( "Device_Config", "Light2",  "Light2" ) ;
   Label3->Caption = ini->ReadString( "Device_Config", "Light3",  "Light3" ) ;
   Label4->Caption = ini->ReadString( "Device_Config", "Light4",  "Light4" ) ;
   Label5->Caption = ini->ReadString( "Device_Config", "Light5",  "Light5" ) ;
   Label6->Caption = ini->ReadString( "Device_Config", "Light6",  "Light6" ) ;
   Label7->Caption = ini->ReadString( "Device_Config", "Light7",  "Light7" ) ;
   Label8->Caption = ini->ReadString( "Device_Config", "Light8",  "Light8" ) ;

   Form1->Caption =  ini->ReadString( "Title_Config", "Software_title",  "Smart Home Control System" ) ;
   StatusBar1->Panels->Items[0]->Text = ini->ReadString( "Title_Config", "CopyRight",  "KinCony" ) ;
   /*
   Form2->Edit1->Text= ini->ReadString( "NetWork_Config", "IP",  "Default Caption" ) ;
   Form2->Edit2->Text= ini->ReadString( "NetWork_Config", "Port",  "Default Caption" ) ;

   Form2->Edit3->Text= ini->ReadString( "Device_Config", "Light1",  "Default Caption" ) ;
   Form2->Edit4->Text= ini->ReadString( "Device_Config", "Light2",  "Default Caption" ) ;
   Form2->Edit5->Text= ini->ReadString( "Device_Config", "Light3",  "Default Caption" ) ;
   Form2->Edit6->Text= ini->ReadString( "Device_Config", "Light4",  "Default Caption" ) ;
   Form2->Edit7->Text= ini->ReadString( "Device_Config", "Light5",  "Default Caption" ) ;
   Form2->Edit8->Text= ini->ReadString( "Device_Config", "Light6",  "Default Caption" ) ;
   Form2->Edit9->Text= ini->ReadString( "Device_Config", "Light7",  "Default Caption" ) ;
   Form2->Edit10->Text= ini->ReadString( "Device_Config", "Light8",  "Default Caption" ) ;

   Form2->Edit11->Text= ini->ReadString( "Title_Config", "Software_title",  "Default Caption" ) ;
   Form2->Edit12->Text= ini->ReadString( "Title_Config", "CopyRight",  "Default Caption" ) ;
   */

   ClientSocket1->Host=ini->ReadString( "NetWork_Config", "IP",  "192.168.1.200" ) ;
   ClientSocket1->Port=StrToInt(ini->ReadString( "NetWork_Config", "Port",  "4196" )) ;

   light_img_1_ON= ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) ;
   light_img_2_ON= ini->ReadString( "Device_ICO", "Light2_ON",  "Default Caption" ) ;
   light_img_3_ON= ini->ReadString( "Device_ICO", "Light3_ON",  "Default Caption" ) ;
   light_img_4_ON= ini->ReadString( "Device_ICO", "Light4_ON",  "Default Caption" ) ;
   light_img_5_ON= ini->ReadString( "Device_ICO", "Light5_ON",  "Default Caption" ) ;
   light_img_6_ON= ini->ReadString( "Device_ICO", "Light6_ON",  "Default Caption" ) ;
   light_img_7_ON= ini->ReadString( "Device_ICO", "Light7_ON",  "Default Caption" ) ;
   light_img_8_ON= ini->ReadString( "Device_ICO", "Light8_ON",  "Default Caption" ) ;

   light_img_1_OFF= ini->ReadString( "Device_ICO", "Light1_OFF",  "Default Caption" ) ;
   light_img_2_OFF= ini->ReadString( "Device_ICO", "Light2_OFF",  "Default Caption" ) ;
   light_img_3_OFF= ini->ReadString( "Device_ICO", "Light3_OFF",  "Default Caption" ) ;
   light_img_4_OFF= ini->ReadString( "Device_ICO", "Light4_OFF",  "Default Caption" ) ;
   light_img_5_OFF= ini->ReadString( "Device_ICO", "Light5_OFF",  "Default Caption" ) ;
   light_img_6_OFF= ini->ReadString( "Device_ICO", "Light6_OFF",  "Default Caption" ) ;
   light_img_7_OFF= ini->ReadString( "Device_ICO", "Light7_OFF",  "Default Caption" ) ;
   light_img_8_OFF= ini->ReadString( "Device_ICO", "Light8_OFF",  "Default Caption" ) ;

   Image1->Picture ->LoadFromFile(light_img_1_OFF);
   Image2->Picture ->LoadFromFile(light_img_2_OFF);
   Image3->Picture ->LoadFromFile(light_img_3_OFF);
   Image4->Picture ->LoadFromFile(light_img_4_OFF);
   Image5->Picture ->LoadFromFile(light_img_5_OFF);
   Image6->Picture ->LoadFromFile(light_img_6_OFF);
   Image7->Picture ->LoadFromFile(light_img_7_OFF);
   Image8->Picture ->LoadFromFile(light_img_8_OFF);


   //------------------------------��һ·��ʱ������������Ϣ------------------------
  // ShowMessage(ini->ReadString( "Week_Config", "One_Week1",  "0" ));
  //	if (ini->ReadString( "Week_Config", "One_Week1",  "0" )=="-1") Form3->CheckBox1->Checked=true; else Form3->CheckBox1->Checked=false;   //��ȡ����ѡ��
 /*  Form3->CheckBox2->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week2",  "0" )) ;
   Form3->CheckBox3->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week3",  "0" )) ;
   Form3->CheckBox4->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week4",  "0" )) ;
   Form3->CheckBox5->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week5",  "0" )) ;
   Form3->CheckBox6->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week6",  "0" )) ;
   Form3->CheckBox7->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week7",  "0" )) ;

   Form3->CheckBox8->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_1",  "0" )) ;  //��ȡ������ʱʱ���ʹ�ܲ���
   Form3->CheckBox9->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_2",  "0" )) ;
   Form3->CheckBox10->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_3",  "0" )) ;
   Form3->CheckBox11->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_4",  "0" )) ;
   Form3->CheckBox12->Checked  = StrToBool(ini->ReadString( "Enable_Config", "One_EN_5",  "0" )) ;
	 */
  // Form3->ComboBox1->Text  = ini->ReadString( "Time_Config", "One_Time1_A",  "Default Caption" ) ;     //��һ·�ĵ�1����ʱ������ֹʱ���
  /* Form3->ComboBox2->Text  = ini->ReadString( "Time_Config", "One_Time1_B",  "00" ) ;
   Form3->ComboBox3->Text  = ini->ReadString( "Time_Config", "One_Time1_C",  "00" ) ;
   Form3->ComboBox4->Text  = ini->ReadString( "Time_Config", "One_Time1_D",  "00" ) ;

   Form3->ComboBox5->Text  = ini->ReadString( "Time_Config", "One_Time2_A",  "00" ) ;     //��һ·�ĵ�2����ʱ������ֹʱ���
   Form3->ComboBox6->Text  = ini->ReadString( "Time_Config", "One_Time2_B",  "00" ) ;
   Form3->ComboBox7->Text  = ini->ReadString( "Time_Config", "One_Time2_C",  "00" ) ;
   Form3->ComboBox8->Text  = ini->ReadString( "Time_Config", "One_Time2_D",  "00" ) ;

   Form3->ComboBox9->Text  = ini->ReadString( "Time_Config", "One_Time3_A",  "00" ) ;     //��һ·�ĵ�3����ʱ������ֹʱ���
   Form3->ComboBox10->Text  = ini->ReadString( "Time_Config", "One_Time3_B",  "00" ) ;
   Form3->ComboBox11->Text  = ini->ReadString( "Time_Config", "One_Time3_C",  "00" ) ;
   Form3->ComboBox12->Text  = ini->ReadString( "Time_Config", "One_Time3_D",  "00" ) ;

   Form3->ComboBox13->Text  = ini->ReadString( "Time_Config", "One_Time4_A",  "00" ) ;     //��һ·�ĵ�4����ʱ������ֹʱ���
   Form3->ComboBox14->Text  = ini->ReadString( "Time_Config", "One_Time4_B",  "00" ) ;
   Form3->ComboBox15->Text  = ini->ReadString( "Time_Config", "One_Time4_C",  "00" ) ;
   Form3->ComboBox16->Text  = ini->ReadString( "Time_Config", "One_Time4_D",  "00" ) ;

   Form3->ComboBox17->Text  = ini->ReadString( "Time_Config", "One_Time5_A",  "00" ) ;     //��һ·�ĵ�5����ʱ������ֹʱ���
   Form3->ComboBox18->Text  = ini->ReadString( "Time_Config", "One_Time5_B",  "00" ) ;
   Form3->ComboBox19->Text  = ini->ReadString( "Time_Config", "One_Time5_C",  "00" ) ;
   Form3->ComboBox20->Text  = ini->ReadString( "Time_Config", "One_Time5_D",  "00" ) ;


	   */








   delete ini;





}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

  StatusBar1->Panels->Items[1]->Text="";


/*StatusBar1->Panels->Items[1]->Text = DateTimeToStr(Now());    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
		ClientSocket1->Active = false;
        try
          {
            ClientSocket1->Active=true;
          }
        catch(Exception &E)
          {
            ShowMessage("����ʧ�ܣ�"+E.Message);
        return;
		  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,1,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image1->Picture ->LoadFromFile(light_img_1_ON);  //���ONͼ��

	if (Form6->CheckBox1->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox1->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button2->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��1·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,1";
   String strResponse = GetData(send_buf, data);
   Image1->Picture ->LoadFromFile(light_img_1_ON);  //���ONͼ��

	if (Form6->CheckBox1->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox1->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button2->Click();      //ִ�йرհ�ť
	  }

   //Memo1->Text = strResponse;

  }



 // Image1->Picture ->LoadFromFile(light_img_1_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Close() ;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-TEST-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,1,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��1·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,0";
   String strResponse = GetData(send_buf, data);
  }

  Image1->Picture ->LoadFromFile(light_img_1_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,2,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image2->Picture ->LoadFromFile(light_img_2_ON);

		if (Form6->CheckBox2->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox2->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button4->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��2·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,1";
   String strResponse = GetData(send_buf, data);
   Image2->Picture ->LoadFromFile(light_img_2_ON);

	if (Form6->CheckBox2->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox2->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button4->Click();      //ִ�йرհ�ť
	  }
  }

  //Image2->Picture ->LoadFromFile(light_img_2_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,2,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��2·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,0";
   String strResponse = GetData(send_buf, data);
  }

  Image2->Picture ->LoadFromFile(light_img_2_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,3,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image3->Picture ->LoadFromFile(light_img_3_ON);

	if (Form6->CheckBox3->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox3->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button6->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��3·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,1";
   String strResponse = GetData(send_buf, data);
   Image3->Picture ->LoadFromFile(light_img_3_ON);

	if (Form6->CheckBox3->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox3->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button6->Click();      //ִ�йرհ�ť
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,4,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image4->Picture ->LoadFromFile(light_img_4_ON);

	  if (Form6->CheckBox4->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox4->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button8->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��4·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,1";
   String strResponse = GetData(send_buf, data);
   Image4->Picture ->LoadFromFile(light_img_4_ON);

	if (Form6->CheckBox4->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox4->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button8->Click();      //ִ�йرհ�ť
	  }

  }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,3,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��3·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,0";
   String strResponse = GetData(send_buf, data);
  }

  Image3->Picture ->LoadFromFile(light_img_3_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,4,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��4·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,0";
   String strResponse = GetData(send_buf, data);
  }

  Image4->Picture ->LoadFromFile(light_img_4_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,5,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image5->Picture ->LoadFromFile(light_img_5_ON);

		if (Form6->CheckBox5->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox5->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button16->Click();      //ִ�йرհ�ť
	  }

  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��5·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,1";
   String strResponse = GetData(send_buf, data);
   Image5->Picture ->LoadFromFile(light_img_5_ON);

	if (Form6->CheckBox5->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox5->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button16->Click();      //ִ�йرհ�ť
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,5,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��5·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,0";
   String strResponse = GetData(send_buf, data);
  }

  Image5->Picture ->LoadFromFile(light_img_5_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,6,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image6->Picture ->LoadFromFile(light_img_6_ON);

		if (Form6->CheckBox6->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox6->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button18->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��6·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,1";
   String strResponse = GetData(send_buf, data);
   Image6->Picture ->LoadFromFile(light_img_6_ON);

	if (Form6->CheckBox6->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox6->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button18->Click();      //ִ�йرհ�ť
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,7,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image7->Picture ->LoadFromFile(light_img_7_ON);

		if (Form6->CheckBox7->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox7->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button20->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��7·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,1";
   String strResponse = GetData(send_buf, data);
   Image7->Picture ->LoadFromFile(light_img_7_ON);

	if (Form6->CheckBox7->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox7->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button20->Click();      //ִ�йرհ�ť
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,7,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��7·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,0";
   String strResponse = GetData(send_buf, data);
  }

  Image7->Picture ->LoadFromFile(light_img_7_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,6,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��6·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,0";
   String strResponse = GetData(send_buf, data);
  }

  Image6->Picture ->LoadFromFile(light_img_6_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;
  DWORD dwTick = ::GetTickCount();    //��ʱ������

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,8,1";
	ClientSocket1->Socket->SendText(send_buf);
	Image8->Picture ->LoadFromFile(light_img_8_ON);

		if (Form6->CheckBox8->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox8->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button14->Click();      //ִ�йرհ�ť
	  }
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��8·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,1";
   String strResponse = GetData(send_buf, data);
   Image8->Picture ->LoadFromFile(light_img_8_ON);

	if (Form6->CheckBox8->Checked)    //����ǵ㶯ģʽ�Ļ�����Ҫ��ʱ���Զ��رռ̵���
	  {
		while (::GetTickCount() - dwTick < StrToInt(Form6->ComboBox8->Text )*1000)  //��ʱ
		Application->ProcessMessages();
		Button14->Click();      //ִ�йرհ�ť
	  }
  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET-1,8,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��8·�̵����ر�
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,0";
   String strResponse = GetData(send_buf, data);
  }

  Image8->Picture ->LoadFromFile(light_img_8_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Config1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
/*   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );

   ini->WriteString ( "Name_Config","Light1", Label1->Caption );
   ini->WriteString ( "Name_Config","Light2", Label2->Caption );
   ini->WriteString ( "Name_Config","Light3", Label3->Caption );
   ini->WriteString ( "Name_Config","Light4", Label4->Caption );
   ini->WriteString ( "Name_Config","Light5", Label5->Caption );
   ini->WriteString ( "Name_Config","Light6", Label6->Caption );
   ini->WriteString ( "Name_Config","Light7", Label7->Caption );
   ini->WriteString ( "Name_Config","Light8", Label8->Caption );

   delete ini;      */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Connect1Click(TObject *Sender)
{
		ClientSocket1->Active = false;
		try
          {
			ClientSocket1->Active=true;
			DisConnect1->Enabled=true;  //�Ͽ����Ӱ�ťʧЧ
			Connect1->Enabled =false;   //���Ӱ�ťʧЧ
		  }
		catch(Exception &E)
          {
            ShowMessage("����ʧ�ܣ�"+E.Message);
        return;
		  }


//Sleep(1000);
//ClientSocket1->Socket->SendText("RELAY-STATE-1");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DisConnect1Click(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Close() ;

  DisConnect1->Enabled=false;  //�Ͽ����Ӱ�ťʧЧ
  Connect1->Enabled =true;   //���Ӱ�ťʧЧ

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connect OK! ";

  StatusBar1->Panels->Items[2]->Text = "�豸������";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connecting... ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
   StatusBar1->Panels->Items[1]->Text = "DisConnected!" ;
   StatusBar1->Panels->Items[2]->Text = "�豸δ����";
   ShowMessage("�豸�ѶϿ�����");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
  StatusBar1->Panels->Items[1]->Text = "Connect to Server failed!" ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
	AnsiString temp,Substr,Substr1,str,str1;
	int input_state;
    int pos; //�����ַ���λ��
    temp=ClientSocket1->Socket->ReceiveText();
	int real_state=0;
	int Trigger_Run=0; //�����������ʱ���ͳ���һ���Կ���8���̵������ֽڲ���

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,1,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-1 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,1,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-1 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,2,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-2 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,2,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-2 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,3,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-3 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,3,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-3 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,4,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-4 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,4,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-4 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,5,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-5 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,5,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-5 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,6,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-6 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,6,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-6 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,7,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-7 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,7,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-7 OFF OK!";
	  }
//------------------------------------------------------------------

//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,8,1,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-8 ON OK!";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	if (Substr=="RELAY-SET-1,8,0,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "Relay-8 OFF OK!";
	  }
//------------------------------------------------------------------

	Substr=AnsiString(temp).SubString(1,30);
	if (Substr=="RELAY-SCAN_DEVICE-CHANNEL_8,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "This is Relay-8 Controller";
		ClientSocket1->Socket->SendText("RELAY-TEST-NOW");
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,31);
	if (Substr=="RELAY-SCAN_DEVICE-CHANNEL_32,OK")
	  {
		StatusBar1->Panels->Items[1]->Text = "This is Relay-32 Controller";
	  }
//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,15);
	if (Substr=="HOST-TEST-START")
	  {
		StatusBar1->Panels->Items[1]->Text = "Initialization completion";
	  }
//----------------------����յ��������봥���ź�------�磺RELAY-ALARM-3--------

	Substr=AnsiString(temp).SubString(1,12);

	if (Substr=="RELAY-ALARM-")
	  {
	    Substr1=AnsiString(temp).SubString(13,1);  //ȡ����·��
		ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1");  //������״̬
		StatusBar1->Panels->Items[1]->Text = "����˱�����";

	/*	if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox2->Checked)     //���������2·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox2->Text +","+Form4->ComboBox10->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }

		if (Form4->CheckBox1->Checked)     //���������1·��ѡ��
		 { send_buf="RELAY-SET-1,"+Form4->ComboBox1->Text +","+Form4->ComboBox9->Text;
		   ClientSocket1->Socket->SendText(send_buf);
		 }    */

	  }


//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,18);
	//�����¶�ֵ    RELAY-GET_INPUT-1,6.5,OK �� RELAY-GET_INPUT-1,16.5,OK
	if (Substr=="RELAY-GET_INPUT-1,")
	  {
		//ShowMessage(temp);
		str=temp.SubString(19,temp.Length()-18 ); //ȡ��  6.5,OK �� 16.5,OK
		//ShowMessage(str);
		pos=str.Pos(",");  //�ҳ����ŵ�λ��
		str1=AnsiString(str).SubString(1,pos-1); //ȡ���¶�ֵ
		//ShowMessage(str1);
		real_state=StrToInt(str1);

	   if ((real_state&0x01)==0x01)
		 {
		   Shape1->Brush->Color=clLime;    //��1·����˱�����
		   if (Form4->CheckBox1->Checked==true) //�����1·���������ʹ����Ч
			{
			  if (Form4->ComboBox1->Text=="��") { //���ݵ�1·�̵��������ֽڲ���

			  ClientSocket1->Socket->SendText("RELAY-SET-1,1,1");

			  }
			  else if (Form4->ComboBox1->Text=="�ر�") {
			   ;
				   }
			  else if (Form4->ComboBox1->Text=="�෴") {
			   ;
				   }
			  else if (Form4->ComboBox1->Text=="����") {
               ;
				   }





			}









		 }
	   else Shape1->Brush->Color=clRed;



	   if ((real_state&0x02)==0x02) Shape2->Brush->Color=clLime;    //��2·����˱�����
		 else Shape2->Brush->Color=clRed;
	   if ((real_state&0x04)==0x04) Shape3->Brush->Color=clLime;    //��3·����˱�����
		 else Shape3->Brush->Color=clRed;
	   if ((real_state&0x08)==0x08) Shape4->Brush->Color=clLime;    //��4·����˱�����
		 else Shape4->Brush->Color=clRed;
	   if ((real_state&0x10)==0x10) Shape5->Brush->Color=clLime;    //��5·����˱�����
		 else Shape5->Brush->Color=clRed;
	   if ((real_state&0x20)==0x20) Shape6->Brush->Color=clLime;    //��6·����˱�����
		 else Shape6->Brush->Color=clRed;
	   if ((real_state&0x40)==0x40) Shape7->Brush->Color=clLime;    //��7·����˱�����
		 else Shape7->Brush->Color=clRed;
	   if ((real_state&0x80)==0x80) Shape8->Brush->Color=clLime;    //��8·����˱�����
		 else Shape8->Brush->Color=clRed;


       //������¶�ֵ������ʾ������ֵ�����̼��汾����
	   //	Label10->Caption=str1;
	   //	ProgressBar1->Position =StrToFloat(str1);
		//StatusBar1->Panels->Items[1]->Text = "Initialization completion";
	  }
//------------------------------------------------------------------







}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeviceType1Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Initialization1Click(TObject *Sender)
{
//ClientSocket1->Socket->SendText("RELAY-TEST-NOW");

  ClientSocket1->Socket->SendText("RELAY-SCAN_DEVICE-NOW");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Sky1Click(TObject *Sender)
{
//  TStyleManager::Initialize();
//  TStyleManager::LoadFromFile("Sky.vsf");
  TStyleManager::SetStyle("Sky");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Glow1Click(TObject *Sender)
{
// TStyleManager::Initialize();
// TStyleManager::LoadFromFile("Glow.vsf");
 TStyleManager::SetStyle("GLow");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Windows101Click(TObject *Sender)
{
//  TStyleManager::Initialize();
//  TStyleManager::LoadFromFile("Silver.vsf");
  TStyleManager::SetStyle("Silver");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ConFig2Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{

  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET_ALL-1,255";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //ȫ��
   data = "deviceCode=" + SN + "&command=RELAY-SET_ALL-" + IntToStr(time_i)+",255";
   String strResponse = GetData(send_buf, data);
  }


  Image1->Picture ->LoadFromFile(light_img_1_ON);
  Image2->Picture ->LoadFromFile(light_img_2_ON);
  Image3->Picture ->LoadFromFile(light_img_3_ON);
  Image4->Picture ->LoadFromFile(light_img_4_ON);
  Image5->Picture ->LoadFromFile(light_img_5_ON);
  Image6->Picture ->LoadFromFile(light_img_6_ON);
  Image7->Picture ->LoadFromFile(light_img_7_ON);
  Image8->Picture ->LoadFromFile(light_img_8_ON);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{

  AnsiString send_buf,SN,data;

  if (N10->Checked==true) {  //�����ǰ�Ǿ�����ģʽ
	send_buf="RELAY-SET_ALL-1,0";
	ClientSocket1->Socket->SendText(send_buf);
  }
  else                       //�����ǰ��������ģʽ
  {
   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

   if (N14->Checked==true) SN=Form5->Edit2->Text ;                //ѡ�е��ǵ�1̨���ƺ�
   if (N21->Checked==true) SN=Form5->Edit4->Text ;                //ѡ�е��ǵ�2̨���ƺ�
   if (N31->Checked==true) SN=Form5->Edit6->Text ;                //ѡ�е��ǵ�3̨���ƺ�
   if (N41->Checked==true) SN=Form5->Edit8->Text ;                //ѡ�е��ǵ�4̨���ƺ�

   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //ȫ��
   data = "deviceCode=" + SN + "&command=RELAY-SET_ALL-" + IntToStr(time_i)+",0";
   String strResponse = GetData(send_buf, data);
  }

  Image1->Picture ->LoadFromFile(light_img_1_OFF);
  Image2->Picture ->LoadFromFile(light_img_2_OFF);
  Image3->Picture ->LoadFromFile(light_img_3_OFF);
  Image4->Picture ->LoadFromFile(light_img_4_OFF);
  Image5->Picture ->LoadFromFile(light_img_5_OFF);
  Image6->Picture ->LoadFromFile(light_img_6_OFF);
  Image7->Picture ->LoadFromFile(light_img_7_OFF);
  Image8->Picture ->LoadFromFile(light_img_8_OFF);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
  ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1,1");  //���¶ȴ�����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
  Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
  Timer2->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-GET_INPUT-1");  //������״̬
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{

  if (N5->Checked ==true) N5->Checked =false; else { N5->Checked =true;N6->Checked =false;}

  Form3->Timer1->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{

  if (N6->Checked ==true) N6->Checked =false; else { N6->Checked =true;N5->Checked =false;}
  Form3->Timer1->Enabled =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//TStyleManager::Initialize();
TStyleManager::LoadFromFile("Sky.vsf");
TStyleManager::LoadFromFile("Glow.vsf");
TStyleManager::LoadFromFile("Silver.vsf");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
  Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
  Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
   N10->Checked=true;        //ѡ��Ϊ������ģʽ
   N11->Checked=false;      //����ģʽ/���������˵�ȡ��ѡ��
   Device1->Enabled=true;   //���ؿ��ơ��˵�������
   N13->Enabled=false;      //Զ�̿��ơ��˵�������
   imer1->Enabled=true;   //��ʱ�����˵�������

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
   N11->Checked=true;        //����ģʽ/���������˵�ѡ��
   N10->Checked=false;      //����ģʽ/���������˵�ȡ��ѡ��
   Device1->Enabled=false;   //���ؿ��ơ��˵�������
   N13->Enabled=true;      //Զ�̿��ơ��˵�������
   imer1->Enabled=false;   //��ʱ�����˵�������

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N14Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=true;   //���ƺ�1
  N21->Checked=false;  //���ƺ�2
  N31->Checked=false;  //���ƺ�3
  N41->Checked=false;  //���ƺ�4

	 if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //������Ϊ1λ��

  }else if (i<100) {i=2;     //������Ϊ2λ��

		}
		else i=3;            //������Ϊ3λ��

  SN=Form5->Edit2->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��ѯ��·���صĵ�ǰ״̬
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //SubstrΪ{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //��ȡ���˵�ǰ״̬���ַ���
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //ȡ��  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str1=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //��1·�̵���״̬ʵʱ��ʾ
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //��2·�̵���״̬ʵʱ��ʾ
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //��3·�̵���״̬ʵʱ��ʾ
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //��4·�̵���״̬ʵʱ��ʾ
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //��5·�̵���״̬ʵʱ��ʾ
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //��6·�̵���״̬ʵʱ��ʾ
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //��7·�̵���״̬ʵʱ��ʾ
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //��8·�̵���״̬ʵʱ��ʾ
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;


  N14->Checked=false;   //���ƺ�1
  N21->Checked=true;  //���ƺ�2
  N31->Checked=false;  //���ƺ�3
  N41->Checked=false;  //���ƺ�4

     if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //������Ϊ1λ��

  }else if (i<100) {i=2;     //������Ϊ2λ��

		}
		else i=3;            //������Ϊ3λ��

  SN=Form5->Edit4->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��ѯ��·���صĵ�ǰ״̬
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


//  Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //SubstrΪ{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //��ȡ���˵�ǰ״̬���ַ���
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //ȡ��  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str1=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //��1·�̵���״̬ʵʱ��ʾ
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //��2·�̵���״̬ʵʱ��ʾ
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //��3·�̵���״̬ʵʱ��ʾ
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //��4·�̵���״̬ʵʱ��ʾ
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //��5·�̵���״̬ʵʱ��ʾ
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //��6·�̵���״̬ʵʱ��ʾ
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //��7·�̵���״̬ʵʱ��ʾ
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //��8·�̵���״̬ʵʱ��ʾ
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=false;   //���ƺ�1
  N21->Checked=false;  //���ƺ�2
  N31->Checked=true;  //���ƺ�3
  N41->Checked=false;  //���ƺ�4

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //������Ϊ1λ��

  }else if (i<100) {i=2;     //������Ϊ2λ��

		}
		else i=3;            //������Ϊ3λ��

  SN=Form5->Edit6->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��ѯ��·���صĵ�ǰ״̬
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //SubstrΪ{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //��ȡ���˵�ǰ״̬���ַ���
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //ȡ��  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str1=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //��1·�̵���״̬ʵʱ��ʾ
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //��2·�̵���״̬ʵʱ��ʾ
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //��3·�̵���״̬ʵʱ��ʾ
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //��4·�̵���״̬ʵʱ��ʾ
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //��5·�̵���״̬ʵʱ��ʾ
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //��6·�̵���״̬ʵʱ��ʾ
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //��7·�̵���״̬ʵʱ��ʾ
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //��8·�̵���״̬ʵʱ��ʾ
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
  AnsiString send_buf,SN,data,Substr,temp,str,str1;
  int i=0;
  int pos,Relay_state;

  N14->Checked=false;   //���ƺ�1
  N21->Checked=false;  //���ƺ�2
  N31->Checked=false;  //���ƺ�3
  N41->Checked=true;  //���ƺ�4

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //������Ϊ1λ��

  }else if (i<100) {i=2;     //������Ϊ2λ��

		}
		else i=3;            //������Ϊ3λ��

  SN=Form5->Edit8->Text;
  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��ѯ��·���صĵ�ǰ״̬
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);


 // Memo2->Text = send_buf+"?"+data;
  String strResponse = GetData(send_buf, data);
 // Memo1->Text = strResponse;
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,OK\u0000","status":"0"}
  //SubstrΪ{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";

  if (Substr==temp) {   //��ȡ���˵�ǰ״̬���ַ���
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //ȡ��  15,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str1=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     15

	 Relay_state=StrToInt(str1);       //15

	 if ((Relay_state&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //��1·�̵���״̬ʵʱ��ʾ
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //��2·�̵���״̬ʵʱ��ʾ
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //��3·�̵���״̬ʵʱ��ʾ
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //��4·�̵���״̬ʵʱ��ʾ
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //��5·�̵���״̬ʵʱ��ʾ
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //��6·�̵���״̬ʵʱ��ʾ
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //��7·�̵���״̬ʵʱ��ʾ
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //��8·�̵���״̬ʵʱ��ʾ
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
Form6->Show();
}
//---------------------------------------------------------------------------
