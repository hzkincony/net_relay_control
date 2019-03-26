//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>

#include "Unit5.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{

   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
  // ini = new TIniFile( "C:\Net_Relay_Control.INI" );
   //------------------------------4个控制盒的别名参数配置信息------------------------

   Edit1->Text  = ini->ReadString( "Remote_Box_Alias", "Box_1_Alias",  "" ) ;     //第一路的第1个定时器的起止时间段
   Edit3->Text  = ini->ReadString( "Remote_Box_Alias", "Box_2_Alias",  "" ) ;
   Edit5->Text  = ini->ReadString( "Remote_Box_Alias", "Box_3_Alias",  "" ) ;
   Edit7->Text  = ini->ReadString( "Remote_Box_Alias", "Box_4_Alias",  "" ) ;

   //------------------------------4个控制盒的序列号参数配置信息------------------------

   Edit2->Text  = ini->ReadString( "Remote_Box_SN", "Box_1_SN",  "" ) ;     //第一路的第1个定时器的起止时间段
   Edit4->Text  = ini->ReadString( "Remote_Box_SN", "Box_2_SN",  "" ) ;
   Edit6->Text  = ini->ReadString( "Remote_Box_SN", "Box_3_SN",  "" ) ;
   Edit8->Text  = ini->ReadString( "Remote_Box_SN", "Box_4_SN",  "" ) ;

   if (Edit1->Text!="") {             //菜单下面的第1路控制盒名称设定
	   Form1->N14->Caption=Edit1->Text;
	   Form1->N14->Enabled=true;
   }

   if (Edit3->Text!="") {             //菜单下面的第2路控制盒名称设定
	   Form1->N21->Caption=Edit3->Text;
	   Form1->N21->Enabled=true;
   }

   if (Edit5->Text!="") {            //菜单下面的第3路控制盒名称设定
	   Form1->N31->Caption=Edit5->Text;
	   Form1->N31->Enabled=true;
   }

   if (Edit7->Text!="") {            //菜单下面的第4路控制盒名称设定
	   Form1->N41->Caption=Edit7->Text;
	   Form1->N41->Enabled=true;
   }


   delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "C:\Net_Relay_Control.INI" );

 //---------------------------------4个控制盒的别名和序列号参数--------------

   ini->WriteString ( "Remote_Box_Alias", "Box_1_Alias", Edit1->Text );   //保存控制盒的别名
   ini->WriteString ( "Remote_Box_Alias", "Box_2_Alias", Edit3->Text );
   ini->WriteString ( "Remote_Box_Alias", "Box_3_Alias", Edit5->Text );
   ini->WriteString ( "Remote_Box_Alias", "Box_4_Alias", Edit7->Text );

   ini->WriteString ( "Remote_Box_SN", "Box_1_SN", Edit2->Text );   //保存控制盒的序列号
   ini->WriteString ( "Remote_Box_SN", "Box_2_SN", Edit4->Text );
   ini->WriteString ( "Remote_Box_SN", "Box_3_SN", Edit6->Text );
   ini->WriteString ( "Remote_Box_SN", "Box_4_SN", Edit8->Text );

   delete ini;
   Close();


}
//---------------------------------------------------------------------------
