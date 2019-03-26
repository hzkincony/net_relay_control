//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
  // ini = new TIniFile( "C:\Net_Relay_Control.INI" );
   //------------------------------��һ·��ʱ������������Ϣ------------------------

   Form3->CheckBox1->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week1",  "0" )) ;   //��ȡ����ѡ��
   Form3->CheckBox2->Checked  = StrToBool(ini->ReadString( "Week_Config", "One_Week2",  "0" )) ;
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

   Form3->ComboBox1->Text  = ini->ReadString( "Time_Config", "One_Time1_A",  "00" ) ;     //��һ·�ĵ�1����ʱ������ֹʱ���
   Form3->ComboBox2->Text  = ini->ReadString( "Time_Config", "One_Time1_B",  "00" ) ;
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

   //------------------------------�ڶ�·��ʱ������������Ϣ------------------------

   Form3->CheckBox13->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week1",  "0" )) ;   //��ȡ����ѡ��
   Form3->CheckBox14->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week2",  "0" )) ;
   Form3->CheckBox15->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week3",  "0" )) ;
   Form3->CheckBox16->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week4",  "0" )) ;
   Form3->CheckBox17->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week5",  "0" )) ;
   Form3->CheckBox18->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week6",  "0" )) ;
   Form3->CheckBox19->Checked  = StrToBool(ini->ReadString( "Week_Config", "Two_Week7",  "0" )) ;

   Form3->CheckBox20->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Two_EN_1",  "0" )) ;  //��ȡ������ʱʱ���ʹ�ܲ���
   Form3->CheckBox21->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Two_EN_2",  "0" )) ;
   Form3->CheckBox22->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Two_EN_3",  "0" )) ;
   Form3->CheckBox23->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Two_EN_4",  "0" )) ;
   Form3->CheckBox24->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Two_EN_5",  "0" )) ;

   Form3->ComboBox21->Text  = ini->ReadString( "Time_Config", "Two_Time1_A",  "00" ) ;     //�ڶ�·�ĵ�1����ʱ������ֹʱ���
   Form3->ComboBox22->Text  = ini->ReadString( "Time_Config", "Two_Time1_B",  "00" ) ;
   Form3->ComboBox23->Text  = ini->ReadString( "Time_Config", "Two_Time1_C",  "00" ) ;
   Form3->ComboBox24->Text  = ini->ReadString( "Time_Config", "Two_Time1_D",  "00" ) ;

   Form3->ComboBox25->Text  = ini->ReadString( "Time_Config", "Two_Time2_A",  "00" ) ;     //�ڶ�·�ĵ�2����ʱ������ֹʱ���
   Form3->ComboBox26->Text  = ini->ReadString( "Time_Config", "Two_Time2_B",  "00" ) ;
   Form3->ComboBox27->Text  = ini->ReadString( "Time_Config", "Two_Time2_C",  "00" ) ;
   Form3->ComboBox28->Text  = ini->ReadString( "Time_Config", "Two_Time2_D",  "00" ) ;

   Form3->ComboBox29->Text  = ini->ReadString( "Time_Config", "Two_Time3_A",  "00" ) ;     //�ڶ�·�ĵ�3����ʱ������ֹʱ���
   Form3->ComboBox30->Text  = ini->ReadString( "Time_Config", "Two_Time3_B",  "00" ) ;
   Form3->ComboBox31->Text  = ini->ReadString( "Time_Config", "Two_Time3_C",  "00" ) ;
   Form3->ComboBox32->Text  = ini->ReadString( "Time_Config", "Two_Time3_D",  "00" ) ;

   Form3->ComboBox33->Text  = ini->ReadString( "Time_Config", "Two_Time4_A",  "00" ) ;     //�ڶ�·�ĵ�4����ʱ������ֹʱ���
   Form3->ComboBox34->Text  = ini->ReadString( "Time_Config", "Two_Time4_B",  "00" ) ;
   Form3->ComboBox35->Text  = ini->ReadString( "Time_Config", "Two_Time4_C",  "00" ) ;
   Form3->ComboBox36->Text  = ini->ReadString( "Time_Config", "Two_Time4_D",  "00" ) ;

   Form3->ComboBox37->Text  = ini->ReadString( "Time_Config", "Two_Time5_A",  "00" ) ;     //�ڶ�·�ĵ�5����ʱ������ֹʱ���
   Form3->ComboBox38->Text  = ini->ReadString( "Time_Config", "Two_Time5_B",  "00" ) ;
   Form3->ComboBox39->Text  = ini->ReadString( "Time_Config", "Two_Time5_C",  "00" ) ;
   Form3->ComboBox40->Text  = ini->ReadString( "Time_Config", "Two_Time5_D",  "00" ) ;

   //------------------------------����·��ʱ������������Ϣ------------------------

   Form3->CheckBox25->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week1",  "0" )) ;   //��ȡ����ѡ��
   Form3->CheckBox26->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week2",  "0" )) ;
   Form3->CheckBox27->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week3",  "0" )) ;
   Form3->CheckBox28->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week4",  "0" )) ;
   Form3->CheckBox29->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week5",  "0" )) ;
   Form3->CheckBox30->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week6",  "0" )) ;
   Form3->CheckBox31->Checked  = StrToBool(ini->ReadString( "Week_Config", "Three_Week7",  "0" )) ;

   Form3->CheckBox32->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Three_EN_1",  "0" )) ;  //��ȡ������ʱʱ���ʹ�ܲ���
   Form3->CheckBox33->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Three_EN_2",  "0" )) ;
   Form3->CheckBox34->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Three_EN_3",  "0" )) ;
   Form3->CheckBox35->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Three_EN_4",  "0" )) ;
   Form3->CheckBox36->Checked  = StrToBool(ini->ReadString( "Enable_Config", "Three_EN_5",  "0" )) ;

   Form3->ComboBox41->Text  = ini->ReadString( "Time_Config", "Three_Time1_A",  "00" ) ;     //����·�ĵ�1����ʱ������ֹʱ���
   Form3->ComboBox42->Text  = ini->ReadString( "Time_Config", "Three_Time1_B",  "00" ) ;
   Form3->ComboBox43->Text  = ini->ReadString( "Time_Config", "Three_Time1_C",  "00" ) ;
   Form3->ComboBox44->Text  = ini->ReadString( "Time_Config", "Three_Time1_D",  "00" ) ;

   Form3->ComboBox45->Text  = ini->ReadString( "Time_Config", "Three_Time2_A",  "00" ) ;     //����·�ĵ�2����ʱ������ֹʱ���
   Form3->ComboBox46->Text  = ini->ReadString( "Time_Config", "Three_Time2_B",  "00" ) ;
   Form3->ComboBox47->Text  = ini->ReadString( "Time_Config", "Three_Time2_C",  "00" ) ;
   Form3->ComboBox48->Text  = ini->ReadString( "Time_Config", "Three_Time2_D",  "00" ) ;

   Form3->ComboBox49->Text  = ini->ReadString( "Time_Config", "Three_Time3_A",  "00" ) ;     //����·�ĵ�3����ʱ������ֹʱ���
   Form3->ComboBox50->Text  = ini->ReadString( "Time_Config", "Three_Time3_B",  "00" ) ;
   Form3->ComboBox51->Text  = ini->ReadString( "Time_Config", "Three_Time3_C",  "00" ) ;
   Form3->ComboBox52->Text  = ini->ReadString( "Time_Config", "Three_Time3_D",  "00" ) ;

   Form3->ComboBox53->Text  = ini->ReadString( "Time_Config", "Three_Time4_A",  "00" ) ;     //����·�ĵ�4����ʱ������ֹʱ���
   Form3->ComboBox54->Text  = ini->ReadString( "Time_Config", "Three_Time4_B",  "00" ) ;
   Form3->ComboBox55->Text  = ini->ReadString( "Time_Config", "Three_Time4_C",  "00" ) ;
   Form3->ComboBox56->Text  = ini->ReadString( "Time_Config", "Three_Time4_D",  "00" ) ;

   Form3->ComboBox57->Text  = ini->ReadString( "Time_Config", "Three_Time5_A",  "00" ) ;     //����·�ĵ�5����ʱ������ֹʱ���
   Form3->ComboBox58->Text  = ini->ReadString( "Time_Config", "Three_Time5_B",  "00" ) ;
   Form3->ComboBox59->Text  = ini->ReadString( "Time_Config", "Three_Time5_C",  "00" ) ;
   Form3->ComboBox60->Text  = ini->ReadString( "Time_Config", "Three_Time5_D",  "00" ) ;

	delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
  Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button3Click(TObject *Sender)
{
   TIniFile *ini;
 ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "C:\Net_Relay_Control.INI" );

 //---------------------------------��һ·�̵���������صĶ�ʱ����--------------
   ini->WriteString ( "Week_Config", "One_Week1", BoolToStr(CheckBox1->Checked) );   //�������ڲ���
   ini->WriteString ( "Week_Config", "One_Week2", BoolToStr(CheckBox2->Checked) );
   ini->WriteString ( "Week_Config", "One_Week3", BoolToStr(CheckBox3->Checked) );
   ini->WriteString ( "Week_Config", "One_Week4", BoolToStr(CheckBox4->Checked) );
   ini->WriteString ( "Week_Config", "One_Week5", BoolToStr(CheckBox5->Checked) );
   ini->WriteString ( "Week_Config", "One_Week6", BoolToStr(CheckBox6->Checked) );
   ini->WriteString ( "Week_Config", "One_Week7", BoolToStr(CheckBox7->Checked) );

   ini->WriteString ( "Enable_Config", "One_EN_1", BoolToStr(CheckBox8->Checked) );   //���涨ʱ����������
   ini->WriteString ( "Enable_Config", "One_EN_2", BoolToStr(CheckBox9->Checked) );
   ini->WriteString ( "Enable_Config", "One_EN_3", BoolToStr(CheckBox10->Checked) );
   ini->WriteString ( "Enable_Config", "One_EN_4", BoolToStr(CheckBox11->Checked) );
   ini->WriteString ( "Enable_Config", "One_EN_5", BoolToStr(CheckBox12->Checked) );


   ini->WriteString ( "Time_Config", "One_Time1_A", ComboBox1->Text );        //�����һ��ʱ�����ֹ����
   ini->WriteString ( "Time_Config", "One_Time1_B", ComboBox2->Text );
   ini->WriteString ( "Time_Config", "One_Time1_C", ComboBox3->Text );
   ini->WriteString ( "Time_Config", "One_Time1_D", ComboBox4->Text );

   ini->WriteString ( "Time_Config", "One_Time2_A", ComboBox5->Text );
   ini->WriteString ( "Time_Config", "One_Time2_B", ComboBox6->Text );
   ini->WriteString ( "Time_Config", "One_Time2_C", ComboBox7->Text );
   ini->WriteString ( "Time_Config", "One_Time2_D", ComboBox8->Text );

   ini->WriteString ( "Time_Config", "One_Time3_A", ComboBox9->Text );
   ini->WriteString ( "Time_Config", "One_Time3_B", ComboBox10->Text );
   ini->WriteString ( "Time_Config", "One_Time3_C", ComboBox11->Text );
   ini->WriteString ( "Time_Config", "One_Time3_D", ComboBox12->Text );

   ini->WriteString ( "Time_Config", "One_Time4_A", ComboBox13->Text );
   ini->WriteString ( "Time_Config", "One_Time4_B", ComboBox14->Text );
   ini->WriteString ( "Time_Config", "One_Time4_C", ComboBox15->Text );
   ini->WriteString ( "Time_Config", "One_Time4_D", ComboBox16->Text );

   ini->WriteString ( "Time_Config", "One_Time5_A", ComboBox17->Text );
   ini->WriteString ( "Time_Config", "One_Time5_B", ComboBox18->Text );
   ini->WriteString ( "Time_Config", "One_Time5_C", ComboBox19->Text );
   ini->WriteString ( "Time_Config", "One_Time5_D", ComboBox20->Text );

 //---------------------------------�ڶ�·�̵���������صĶ�ʱ����--------------
   ini->WriteString ( "Week_Config", "Two_Week1", BoolToStr(CheckBox13->Checked) );   //�������ڲ���
   ini->WriteString ( "Week_Config", "Two_Week2", BoolToStr(CheckBox14->Checked) );
   ini->WriteString ( "Week_Config", "Two_Week3", BoolToStr(CheckBox15->Checked) );
   ini->WriteString ( "Week_Config", "Two_Week4", BoolToStr(CheckBox16->Checked) );
   ini->WriteString ( "Week_Config", "Two_Week5", BoolToStr(CheckBox17->Checked) );
   ini->WriteString ( "Week_Config", "Two_Week6", BoolToStr(CheckBox18->Checked) );
   ini->WriteString ( "Week_Config", "Two_Week7", BoolToStr(CheckBox19->Checked) );

   ini->WriteString ( "Enable_Config", "Two_EN_1", BoolToStr(CheckBox20->Checked) );   //���涨ʱ����������
   ini->WriteString ( "Enable_Config", "Two_EN_2", BoolToStr(CheckBox21->Checked) );
   ini->WriteString ( "Enable_Config", "Two_EN_3", BoolToStr(CheckBox22->Checked) );
   ini->WriteString ( "Enable_Config", "Two_EN_4", BoolToStr(CheckBox23->Checked) );
   ini->WriteString ( "Enable_Config", "Two_EN_5", BoolToStr(CheckBox24->Checked) );


   ini->WriteString ( "Time_Config", "Two_Time1_A", ComboBox21->Text );        //�����һ��ʱ�����ֹ����
   ini->WriteString ( "Time_Config", "Two_Time1_B", ComboBox22->Text );
   ini->WriteString ( "Time_Config", "Two_Time1_C", ComboBox23->Text );
   ini->WriteString ( "Time_Config", "Two_Time1_D", ComboBox24->Text );

   ini->WriteString ( "Time_Config", "Two_Time2_A", ComboBox25->Text );
   ini->WriteString ( "Time_Config", "Two_Time2_B", ComboBox26->Text );
   ini->WriteString ( "Time_Config", "Two_Time2_C", ComboBox27->Text );
   ini->WriteString ( "Time_Config", "Two_Time2_D", ComboBox28->Text );

   ini->WriteString ( "Time_Config", "Two_Time3_A", ComboBox29->Text );
   ini->WriteString ( "Time_Config", "Two_Time3_B", ComboBox30->Text );
   ini->WriteString ( "Time_Config", "Two_Time3_C", ComboBox31->Text );
   ini->WriteString ( "Time_Config", "Two_Time3_D", ComboBox32->Text );

   ini->WriteString ( "Time_Config", "Two_Time4_A", ComboBox33->Text );
   ini->WriteString ( "Time_Config", "Two_Time4_B", ComboBox34->Text );
   ini->WriteString ( "Time_Config", "Two_Time4_C", ComboBox35->Text );
   ini->WriteString ( "Time_Config", "Two_Time4_D", ComboBox36->Text );

   ini->WriteString ( "Time_Config", "Two_Time5_A", ComboBox37->Text );
   ini->WriteString ( "Time_Config", "Two_Time5_B", ComboBox38->Text );
   ini->WriteString ( "Time_Config", "Two_Time5_C", ComboBox39->Text );
   ini->WriteString ( "Time_Config", "Two_Time5_D", ComboBox40->Text );

 //---------------------------------����·�̵���������صĶ�ʱ����--------------
   ini->WriteString ( "Week_Config", "Three_Week1", BoolToStr(CheckBox25->Checked) );   //�������ڲ���
   ini->WriteString ( "Week_Config", "Three_Week2", BoolToStr(CheckBox26->Checked) );
   ini->WriteString ( "Week_Config", "Three_Week3", BoolToStr(CheckBox27->Checked) );
   ini->WriteString ( "Week_Config", "Three_Week4", BoolToStr(CheckBox28->Checked) );
   ini->WriteString ( "Week_Config", "Three_Week5", BoolToStr(CheckBox29->Checked) );
   ini->WriteString ( "Week_Config", "Three_Week6", BoolToStr(CheckBox30->Checked) );
   ini->WriteString ( "Week_Config", "Three_Week7", BoolToStr(CheckBox31->Checked) );

   ini->WriteString ( "Enable_Config", "Three_EN_1", BoolToStr(CheckBox32->Checked) );   //���涨ʱ����������
   ini->WriteString ( "Enable_Config", "Three_EN_2", BoolToStr(CheckBox33->Checked) );
   ini->WriteString ( "Enable_Config", "Three_EN_3", BoolToStr(CheckBox34->Checked) );
   ini->WriteString ( "Enable_Config", "Three_EN_4", BoolToStr(CheckBox35->Checked) );
   ini->WriteString ( "Enable_Config", "Three_EN_5", BoolToStr(CheckBox36->Checked) );


   ini->WriteString ( "Time_Config", "Three_Time1_A", ComboBox41->Text );        //�����һ��ʱ�����ֹ����
   ini->WriteString ( "Time_Config", "Three_Time1_B", ComboBox42->Text );
   ini->WriteString ( "Time_Config", "Three_Time1_C", ComboBox43->Text );
   ini->WriteString ( "Time_Config", "Three_Time1_D", ComboBox44->Text );

   ini->WriteString ( "Time_Config", "Three_Time2_A", ComboBox45->Text );
   ini->WriteString ( "Time_Config", "Three_Time2_B", ComboBox46->Text );
   ini->WriteString ( "Time_Config", "Three_Time2_C", ComboBox47->Text );
   ini->WriteString ( "Time_Config", "Three_Time2_D", ComboBox48->Text );

   ini->WriteString ( "Time_Config", "Three_Time3_A", ComboBox49->Text );
   ini->WriteString ( "Time_Config", "Three_Time3_B", ComboBox50->Text );
   ini->WriteString ( "Time_Config", "Three_Time3_C", ComboBox51->Text );
   ini->WriteString ( "Time_Config", "Three_Time3_D", ComboBox52->Text );

   ini->WriteString ( "Time_Config", "Three_Time4_A", ComboBox53->Text );
   ini->WriteString ( "Time_Config", "Three_Time4_B", ComboBox54->Text );
   ini->WriteString ( "Time_Config", "Three_Time4_C", ComboBox55->Text );
   ini->WriteString ( "Time_Config", "Three_Time4_D", ComboBox56->Text );

   ini->WriteString ( "Time_Config", "Three_Time5_A", ComboBox57->Text );
   ini->WriteString ( "Time_Config", "Three_Time5_B", ComboBox58->Text );
   ini->WriteString ( "Time_Config", "Three_Time5_C", ComboBox59->Text );
   ini->WriteString ( "Time_Config", "Three_Time5_D", ComboBox60->Text );


   delete ini;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
  int week1,week2,week3,week4,week5,week6,week7,now_week,week_flag;
  int control_flag1,control_flag2,control_flag3;
  week_flag=0; //�������������־λ
  week1=0;
  week2=0;
  week3=0;
  week4=0;
  week5=0;
  week6=0;
  week7=0;
  control_flag1=control_flag2=control_flag3=0;  //���ռ̵������ƿ��ر�־λ
  AnsiString time1_A,time1_B;    //A:��ʼʱ�� B:����ʱ��
  TTime d1,d2,now_time;
  now_week=Now().DayOfWeek(); //���������ڼ�,������Ϊ1,.....������Ϊ7
  //ShowMessage(IntToStr(now_week));

 //-------------------------��һ·��ʱ����--------------------------------------

  week1=week2=week3=week4=week5=week6=week7=0;
  if (CheckBox1->Checked==true) {    //����һ��־λ
  week1=1;
	}

  if (CheckBox2->Checked==true) {    //���ڶ���־λ
  week2=2;
	}

  if (CheckBox3->Checked==true) {    //��������־λ
  week3=3;
	}

  if (CheckBox4->Checked==true) {   //�����ı�־λ
  week4=4;
	}

  if (CheckBox5->Checked==true) {   //�������־λ
  week5=5;
	}

  if (CheckBox6->Checked==true) {   //��������־λ
  week6=6;
	}

  if (CheckBox7->Checked==true) {   //�����ձ�־λ
  week7=7;
	}


  if ((week1==now_week)||(week2==now_week)||(week3==now_week)||(week4==now_week)||(week5==now_week)||(week6==now_week)||(week7==now_week)) {
	week_flag=1;
  //	ShowMessage("������������");
  }

  //---------------------------------------------------------------------------

	if ((CheckBox8->Checked ==true)&&(week_flag==1)) {        //��һʱ�������
	  time1_A=ComboBox1->Text+":"+ ComboBox2->Text+":00" ;
	  time1_B=ComboBox3->Text+":"+ ComboBox4->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("1_1��ǰ��ʱ�䷶Χ��");
		control_flag1=1;
	  }

  }


	if ((CheckBox9->Checked ==true)&&(week_flag==1)) {        //�ڶ�ʱ�������
	  time1_A=ComboBox5->Text+":"+ ComboBox6->Text+":00" ;
	  time1_B=ComboBox7->Text+":"+ ComboBox8->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("1_2��ǰ��ʱ�䷶Χ��");
		control_flag1=1;
	  }

  }

	if ((CheckBox10->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox9->Text+":"+ ComboBox10->Text+":00" ;
	  time1_B=ComboBox11->Text+":"+ ComboBox12->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("1_3��ǰ��ʱ�䷶Χ��");
		control_flag1=1;
	  }

  }

	if ((CheckBox11->Checked ==true)&&(week_flag==1)) {        //����ʱ�������
	  time1_A=ComboBox13->Text+":"+ ComboBox14->Text+":00" ;
	  time1_B=ComboBox15->Text+":"+ ComboBox16->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("1_4��ǰ��ʱ�䷶Χ��");
		control_flag1=1;
	  }

  }

	if ((CheckBox12->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox17->Text+":"+ ComboBox18->Text+":00" ;
	  time1_B=ComboBox19->Text+":"+ ComboBox20->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("1_5��ǰ��ʱ�䷶Χ��");
		control_flag1=1;
	  }

  }

  if (control_flag1==1)
	{
	  Form1->Button1->Click();  //�򿪵�һ·����
	}
  else
	{
	  Form1->Button2->Click();  //�رյ�һ·����
	}


 //-------------------------�ڶ�·��ʱ����--------------------------------------

  week1=week2=week3=week4=week5=week6=week7=0;
  if (CheckBox13->Checked==true) {    //����һ��־λ
  week1=1;
	}

  if (CheckBox14->Checked==true) {    //���ڶ���־λ
  week2=2;
	}

  if (CheckBox15->Checked==true) {    //��������־λ
  week3=3;
	}

  if (CheckBox16->Checked==true) {   //�����ı�־λ
  week4=4;
	}

  if (CheckBox17->Checked==true) {   //�������־λ
  week5=5;
	}

  if (CheckBox18->Checked==true) {   //��������־λ
  week6=6;
	}

  if (CheckBox19->Checked==true) {   //�����ձ�־λ
  week7=7;
	}


  if ((week1==now_week)||(week2==now_week)||(week3==now_week)||(week4==now_week)||(week5==now_week)||(week6==now_week)||(week7==now_week)) {
	week_flag=1;
	//ShowMessage("������������");
  }

  //---------------------------------------------------------------------------

	if ((CheckBox20->Checked ==true)&&(week_flag==1)) {        //��һʱ�������
	  time1_A=ComboBox21->Text+":"+ ComboBox22->Text+":00" ;
	  time1_B=ComboBox23->Text+":"+ ComboBox24->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("2_1��ǰ��ʱ�䷶Χ��");
		 control_flag2=1;
	  }

  }


	if ((CheckBox21->Checked ==true)&&(week_flag==1)) {        //�ڶ�ʱ�������
	  time1_A=ComboBox25->Text+":"+ ComboBox26->Text+":00" ;
	  time1_B=ComboBox27->Text+":"+ ComboBox28->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("2_2��ǰ��ʱ�䷶Χ��");
		control_flag2=1;
	  }

  }

	if ((CheckBox22->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox29->Text+":"+ ComboBox30->Text+":00" ;
	  time1_B=ComboBox31->Text+":"+ ComboBox32->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("2_3��ǰ��ʱ�䷶Χ��");
		control_flag2=1;
	  }

  }

	if ((CheckBox23->Checked ==true)&&(week_flag==1)) {        //����ʱ�������
	  time1_A=ComboBox33->Text+":"+ ComboBox34->Text+":00" ;
	  time1_B=ComboBox35->Text+":"+ ComboBox36->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("2_4��ǰ��ʱ�䷶Χ��");
		control_flag2=1;
	  }

  }

	if ((CheckBox24->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox37->Text+":"+ ComboBox38->Text+":00" ;
	  time1_B=ComboBox39->Text+":"+ ComboBox40->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("2_5��ǰ��ʱ�䷶Χ��");
		control_flag2=1;
	  }

  }

   if (control_flag2==1)
	{
	  Form1->Button3->Click();  //�򿪵�һ·����
	}
  else
	{
	  Form1->Button4->Click();  //�رյ�һ·����
	}


 //-------------------------����·��ʱ����--------------------------------------

  week1=week2=week3=week4=week5=week6=week7=0;
  if (CheckBox25->Checked==true) {    //����һ��־λ
  week1=1;
	}

  if (CheckBox26->Checked==true) {    //���ڶ���־λ
  week2=2;
	}

  if (CheckBox27->Checked==true) {    //��������־λ
  week3=3;
	}

  if (CheckBox28->Checked==true) {   //�����ı�־λ
  week4=4;
	}

  if (CheckBox29->Checked==true) {   //�������־λ
  week5=5;
	}

  if (CheckBox30->Checked==true) {   //��������־λ
  week6=6;
	}

  if (CheckBox31->Checked==true) {   //�����ձ�־λ
  week7=7;
	}


  if ((week1==now_week)||(week2==now_week)||(week3==now_week)||(week4==now_week)||(week5==now_week)||(week6==now_week)||(week7==now_week)) {
	week_flag=1;
  //	ShowMessage("������������");
  }

  //---------------------------------------------------------------------------

	if ((CheckBox32->Checked ==true)&&(week_flag==1)) {        //��һʱ�������
	  time1_A=ComboBox41->Text+":"+ ComboBox42->Text+":00" ;
	  time1_B=ComboBox43->Text+":"+ ComboBox44->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("3_1��ǰ��ʱ�䷶Χ��");
		control_flag3=1;
	  }

  }


	if ((CheckBox33->Checked ==true)&&(week_flag==1)) {        //�ڶ�ʱ�������
	  time1_A=ComboBox45->Text+":"+ ComboBox46->Text+":00" ;
	  time1_B=ComboBox47->Text+":"+ ComboBox48->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("3_2��ǰ��ʱ�䷶Χ��");
		control_flag3=1;
	  }

  }

	if ((CheckBox34->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox49->Text+":"+ ComboBox50->Text+":00" ;
	  time1_B=ComboBox51->Text+":"+ ComboBox52->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("3_3��ǰ��ʱ�䷶Χ��");
		control_flag3=1;
	  }

  }

	if ((CheckBox35->Checked ==true)&&(week_flag==1)) {        //����ʱ�������
	  time1_A=ComboBox53->Text+":"+ ComboBox54->Text+":00" ;
	  time1_B=ComboBox55->Text+":"+ ComboBox56->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	  //	ShowMessage("3_4��ǰ��ʱ�䷶Χ��");
		control_flag3=1;
	  }

  }

	if ((CheckBox36->Checked ==true)&&(week_flag==1)) {       //����ʱ�������
	  time1_A=ComboBox57->Text+":"+ ComboBox58->Text+":00" ;
	  time1_B=ComboBox59->Text+":"+ ComboBox60->Text+":00" ;

	  now_time= TimeToStr(Now());

	  if ((now_time>time1_A)&&(now_time<time1_B)) {
	 //	ShowMessage("3_5��ǰ��ʱ�䷶Χ��");
		control_flag3=1;
	  }

  }

   if (control_flag3==1)
	{
	  Form1->Button5->Click();  //�򿪵�һ·����
	}
  else
	{
	  Form1->Button6->Click();  //�رյ�һ·����
	}


  }
//---------------------------------------------------------------------------

