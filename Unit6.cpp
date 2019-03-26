//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>
#include "Unit6.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{

   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
   //------------------------------8路点动参数设置------------------------

   Form6->CheckBox1->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_1",  "0" )) ;   //读取使能选项
   Form6->CheckBox2->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_2",  "0" )) ;
   Form6->CheckBox3->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_3",  "0" )) ;
   Form6->CheckBox4->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_4",  "0" )) ;
   Form6->CheckBox5->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_5",  "0" )) ;
   Form6->CheckBox6->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_6",  "0" )) ;
   Form6->CheckBox7->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_7",  "0" )) ;
   Form6->CheckBox8->Checked  = StrToBool(ini->ReadString( "Auto_OFF_Config", "Auto_OFF_8",  "0" )) ;


   Form6->ComboBox1->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time1",  "10" ) ;     //读取延时值
   Form6->ComboBox2->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time2",  "10" ) ;
   Form6->ComboBox3->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time3",  "10" ) ;
   Form6->ComboBox4->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time4",  "10" ) ;
   Form6->ComboBox5->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time5",  "10" ) ;
   Form6->ComboBox6->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time6",  "10" ) ;
   Form6->ComboBox7->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time7",  "10" ) ;
   Form6->ComboBox8->Text  = ini->ReadString( "Auto_OFF_Config", "Auto_OFF_time8",  "10" ) ;

	delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );


 //---------------------------------点动参数设置--------------
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_1", BoolToStr(CheckBox1->Checked) );   //保存使能参数
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_2", BoolToStr(CheckBox2->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_3", BoolToStr(CheckBox3->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_4", BoolToStr(CheckBox4->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_5", BoolToStr(CheckBox5->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_6", BoolToStr(CheckBox6->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_7", BoolToStr(CheckBox7->Checked) );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_8", BoolToStr(CheckBox8->Checked) );

   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time1", ComboBox1->Text );        //保存每个延时值的参数
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time2", ComboBox2->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time3", ComboBox3->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time4", ComboBox4->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time5", ComboBox5->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time6", ComboBox6->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time7", ComboBox7->Text );
   ini->WriteString ( "Auto_OFF_Config", "Auto_OFF_time8", ComboBox8->Text );

   delete ini;
   Close();
}
//---------------------------------------------------------------------------
