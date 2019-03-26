//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
   //----------------------����8·���봥����ʹ�ܲ���-------------------------
   Form4->CheckBox1->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_1",  "0" )) ;
   Form4->CheckBox2->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_2",  "0" )) ;
   Form4->CheckBox3->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_3",  "0" )) ;
   Form4->CheckBox4->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_4",  "0" )) ;
   Form4->CheckBox5->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_5",  "0" )) ;
   Form4->CheckBox6->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_6",  "0" )) ;
   Form4->CheckBox7->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_7",  "0" )) ;
   Form4->CheckBox8->Checked  = StrToBool(ini->ReadString( "Trigger_Config", "Trigger_EN_8",  "0" )) ;

   //----------------------�����1·���봥��ʱ����·�����������-------------

   Form4->ComboBox1->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_1",  "����" ) ;
   Form4->ComboBox2->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_2",  "����" ) ;
   Form4->ComboBox3->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_3",  "����" ) ;
   Form4->ComboBox4->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_4",  "����" ) ;
   Form4->ComboBox5->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_5",  "����" ) ;
   Form4->ComboBox6->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_6",  "����" ) ;
   Form4->ComboBox7->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_7",  "����" ) ;
   Form4->ComboBox8->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_1_8",  "����" ) ;

   //----------------------�����2·���봥��ʱ����·�����������-------------

   Form4->ComboBox9->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_1",  "����" ) ;
   Form4->ComboBox10->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_2",  "����" ) ;
   Form4->ComboBox11->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_3",  "����" ) ;
   Form4->ComboBox12->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_4",  "����" ) ;
   Form4->ComboBox13->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_5",  "����" ) ;
   Form4->ComboBox14->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_6",  "����" ) ;
   Form4->ComboBox15->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_7",  "����" ) ;
   Form4->ComboBox16->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_2_8",  "����" ) ;

   //----------------------�����3·���봥��ʱ����·�����������-------------

   Form4->ComboBox17->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_1",  "����" ) ;
   Form4->ComboBox18->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_2",  "����" ) ;
   Form4->ComboBox19->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_3",  "����" ) ;
   Form4->ComboBox20->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_4",  "����" ) ;
   Form4->ComboBox21->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_5",  "����" ) ;
   Form4->ComboBox22->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_6",  "����" ) ;
   Form4->ComboBox23->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_7",  "����" ) ;
   Form4->ComboBox24->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_3_8",  "����" ) ;

   //----------------------�����4·���봥��ʱ����·�����������-------------

   Form4->ComboBox25->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_1",  "����" ) ;
   Form4->ComboBox26->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_2",  "����" ) ;
   Form4->ComboBox27->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_3",  "����" ) ;
   Form4->ComboBox28->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_4",  "����" ) ;
   Form4->ComboBox29->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_5",  "����" ) ;
   Form4->ComboBox30->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_6",  "����" ) ;
   Form4->ComboBox31->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_7",  "����" ) ;
   Form4->ComboBox32->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_4_8",  "����" ) ;

   //----------------------�����5·���봥��ʱ����·�����������-------------

   Form4->ComboBox33->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_1",  "����" ) ;
   Form4->ComboBox34->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_2",  "����" ) ;
   Form4->ComboBox35->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_3",  "����" ) ;
   Form4->ComboBox36->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_4",  "����" ) ;
   Form4->ComboBox37->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_5",  "����" ) ;
   Form4->ComboBox38->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_6",  "����" ) ;
   Form4->ComboBox39->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_7",  "����" ) ;
   Form4->ComboBox40->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_5_8",  "����" ) ;

   //----------------------�����6·���봥��ʱ����·�����������-------------

   Form4->ComboBox41->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_1",  "����" ) ;
   Form4->ComboBox42->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_2",  "����" ) ;
   Form4->ComboBox43->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_3",  "����" ) ;
   Form4->ComboBox44->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_4",  "����" ) ;
   Form4->ComboBox45->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_5",  "����" ) ;
   Form4->ComboBox46->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_6",  "����" ) ;
   Form4->ComboBox47->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_7",  "����" ) ;
   Form4->ComboBox48->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_6_8",  "����" ) ;

   //----------------------�����7·���봥��ʱ����·�����������-------------

   Form4->ComboBox49->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_1",  "����" ) ;
   Form4->ComboBox50->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_2",  "����" ) ;
   Form4->ComboBox51->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_3",  "����" ) ;
   Form4->ComboBox52->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_4",  "����" ) ;
   Form4->ComboBox53->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_5",  "����" ) ;
   Form4->ComboBox54->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_6",  "����" ) ;
   Form4->ComboBox55->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_7",  "����" ) ;
   Form4->ComboBox56->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_7_8",  "����" ) ;

   //----------------------�����8·���봥��ʱ����·�����������-------------

   Form4->ComboBox57->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_1",  "����" ) ;
   Form4->ComboBox58->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_2",  "����" ) ;
   Form4->ComboBox59->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_3",  "����" ) ;
   Form4->ComboBox60->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_4",  "����" ) ;
   Form4->ComboBox61->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_5",  "����" ) ;
   Form4->ComboBox62->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_6",  "����" ) ;
   Form4->ComboBox63->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_7",  "����" ) ;
   Form4->ComboBox64->Text  = ini->ReadString( "Trigger_Config_Run", "Trigger_8_8",  "����" ) ;

   //------------------------------------------------------------------------
	delete ini;

}
//---------------------------------------------------------------------------



void __fastcall TForm4::Button1Click(TObject *Sender)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );

 //---------------------------------8·��������ʹ�ܲ���--------------
   ini->WriteString ( "Trigger_Config", "Trigger_EN_1", BoolToStr(CheckBox1->Checked) );   //�������ڲ���
   ini->WriteString ( "Trigger_Config", "Trigger_EN_2", BoolToStr(CheckBox2->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_3", BoolToStr(CheckBox3->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_4", BoolToStr(CheckBox4->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_5", BoolToStr(CheckBox5->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_6", BoolToStr(CheckBox6->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_7", BoolToStr(CheckBox7->Checked) );
   ini->WriteString ( "Trigger_Config", "Trigger_EN_8", BoolToStr(CheckBox8->Checked) );

 //---------------------------------��1·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_1", ComboBox1->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_2", ComboBox2->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_3", ComboBox3->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_4", ComboBox4->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_5", ComboBox5->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_6", ComboBox6->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_7", ComboBox7->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_1_8", ComboBox8->Text );

 //---------------------------------��2·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_1", ComboBox9->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_2", ComboBox10->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_3", ComboBox11->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_4", ComboBox12->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_5", ComboBox13->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_6", ComboBox14->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_7", ComboBox15->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_2_8", ComboBox16->Text );

 //---------------------------------��3·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_1", ComboBox17->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_2", ComboBox18->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_3", ComboBox19->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_4", ComboBox20->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_5", ComboBox21->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_6", ComboBox22->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_7", ComboBox23->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_3_8", ComboBox24->Text );

 //---------------------------------��4·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_1", ComboBox25->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_2", ComboBox26->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_3", ComboBox27->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_4", ComboBox28->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_5", ComboBox29->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_6", ComboBox30->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_7", ComboBox31->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_4_8", ComboBox32->Text );

 //---------------------------------��5·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_1", ComboBox33->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_2", ComboBox34->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_3", ComboBox35->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_4", ComboBox36->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_5", ComboBox37->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_6", ComboBox38->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_7", ComboBox39->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_5_8", ComboBox40->Text );

  //---------------------------------��6·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_1", ComboBox41->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_2", ComboBox42->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_3", ComboBox43->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_4", ComboBox44->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_5", ComboBox45->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_6", ComboBox46->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_7", ComboBox47->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_6_8", ComboBox48->Text );

  //---------------------------------��7·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_1", ComboBox49->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_2", ComboBox50->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_3", ComboBox51->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_4", ComboBox52->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_5", ComboBox53->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_6", ComboBox54->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_7", ComboBox55->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_7_8", ComboBox56->Text );

 //---------------------------------��8·���봥����ĸ�·�������------------

	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_1", ComboBox57->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_2", ComboBox58->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_3", ComboBox59->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_4", ComboBox60->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_5", ComboBox61->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_6", ComboBox62->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_7", ComboBox63->Text );
	ini->WriteString ( "Trigger_Config_Run", "Trigger_8_8", ComboBox64->Text );

 //---------------------------------------------------------------------------

   delete ini;
   Close();


}
//---------------------------------------------------------------------------
