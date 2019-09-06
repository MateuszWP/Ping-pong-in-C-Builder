//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x = -8;
        int y = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_BallTimer(TObject *Sender)
{
        Ball->Left += x;
        Ball->Top += y;

        //bounce against upper side
        if(Ball->Top-5 <= Background->Top) y = -y;

        //bounce against lower side
        if(Ball->Top+Ball->Height+5 >= Background->Height) y = -y;

        //defeat
        if(Ball->Left <= Paddle1->Left+Paddle1->Width-15)
        {
                T_Ball->Enabled = false;
                Ball->Visible = false;
        }
         if(Ball->Left+Ball->Width-15 >= Paddle2->Left)
        {
                T_Ball->Enabled = false;
                Ball->Visible = false;
        }

        //bounce against left paddle
        else if(Ball->Top > Paddle1->Top-Ball->Height/2 && Ball->Top < Paddle1->Top+Paddle1->Height                && Ball->Left < Paddle1->Left+Paddle1->Width)
                {
                        if(x<0) x = -x;
                }

        //bounce against right paddle
        else if(Ball->Top > Paddle2->Top-Ball->Height/2 && Ball->Top < Paddle2->Top+Paddle2->Height                && Ball->Left+Ball->Width > Paddle2->Left)
                {
                        if(x>0) x = -x;
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Up1Timer(TObject *Sender)
{
        if(Paddle1->Top > 5) Paddle1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Down1Timer(TObject *Sender)
{
        if(Paddle1->Top + Paddle1->Height < Background->Height-10) Paddle1->Top += 10;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Up2Timer(TObject *Sender)
{
        if(Paddle2->Top > 5) Paddle2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Down2Timer(TObject *Sender)
{
        if(Paddle2->Top + Paddle2->Height < Background->Height-10) Paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'W') Up1->Enabled = true;
        if(Key == 'S') Down1->Enabled = true;
        if(Key == VK_UP) Up2->Enabled = true;
        if(Key == VK_DOWN) Down2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == 'W') Up1->Enabled = false;
        if(Key == 'S') Down1->Enabled = false;
        if(Key == VK_UP) Up2->Enabled = false;
        if(Key == VK_DOWN) Down2->Enabled = false;
}
//---------------------------------------------------------------------------
