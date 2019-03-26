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
   //------------------------------4�����ƺеı�������������Ϣ------------------------

   Edit1->Text  = ini->ReadString( "Remote_Box_Alias", "Box_1_Alias",  "" ) ;     //��һ·�ĵ�1����ʱ������ֹʱ���
   Edit3->Text  = ini->ReadString( "Remote_Box_Alias", "Box_2_Alias",  "" ) ;
   Edit5->Text  = ini->ReadString( "Remote_Box_Alias", "Box_3_Alias",  "" ) ;
   Edit7->Text  = ini->ReadString( "Remote_Box_Alias", "Box_4_Alias",  "" ) ;

   //------------------------------4�����ƺе����кŲ���������Ϣ------------------------

   Edit2->Text  = ini->ReadString( "Remote_Box_SN", "Box_1_SN",  "" ) ;     //��һ·�ĵ�1����ʱ������ֹʱ���
   Edit4->Text  = ini->ReadString( "Remote_Box_SN", "Box_2_SN",  "" ) ;
   Edit6->Text  = ini->ReadString( "Remote_Box_SN", "Box_3_SN",  "" ) ;
   Edit8->Text  = ini->ReadString( "Remote_Box_SN", "Box_4_SN",  "" ) ;

   if (Edit1->Text!="") {             //�˵�����ĵ�1·���ƺ������趨
	   Form1->N14->Caption=Edit1->Text;
	   Form1->N14->Enabled=true;
   }

   if (Edit3->Text!="") {             //�˵�����ĵ�2·���ƺ������趨
	   Form1->N21->Caption=Edit3->Text;
	   Form1->N21->Enabled=true;
   }

   if (Edit5->Text!="") {            //�˵�����ĵ�3·���ƺ������趨
	   Form1->N31->Caption=Edit5->Text;
	   Form1->N31->Enabled=true;
   }

   if (Edit7->Text!="") {            //�˵�����ĵ�4·���ƺ������趨
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

 //---------------------------------4�����ƺеı��������кŲ���--------------

   ini->WriteString ( "Remote_Box_Alias", "Box_1_Alias", Edit1->Text );   //������ƺеı���
   ini->WriteString ( "Remote_Box_Alias", "Box_2_Alias", Edit3->Text );
   ini->WriteString ( "Remote_Box_Alias", "Box_3_Alias", Edit5->Text );
   ini->WriteString ( "Remote_Box_Alias", "Box_4_Alias", Edit7->Text );

   ini->WriteString ( "Remote_Box_SN", "Box_1_SN", Edit2->Text );   //������ƺе����к�
   ini->WriteString ( "Remote_Box_SN", "Box_2_SN", Edit4->Text );
   ini->WriteString ( "Remote_Box_SN", "Box_3_SN", Edit6->Text );
   ini->WriteString ( "Remote_Box_SN", "Box_4_SN", Edit8->Text );

   delete ini;
   Close();


}
//---------------------------------------------------------------------------
