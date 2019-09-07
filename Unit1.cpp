//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x = -8;
        int y = -8;
        int count = 0;
        int point1 = 0;
        int point2 = 0;
        int timeToStart = 3;

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
                point2++;
                if(point2 < 6)
                {
                    Info->Caption = "Punkt dla prawego gracza";
                }
                else
                    Info->Caption = "Wygrana prawego gracza";
                Defeat();
        }
        if(Ball->Left+Ball->Width-15 >= Paddle2->Left)
        {
                point1++;
                if(point1 < 6)
                {
                    Info->Caption = "Punkt dla lewego gracza";
                }
                else
                    Info->Caption = "Wygrana lewego gracza";
                Defeat();
        }

        //bounce against left paddle
        else if(Ball->Top > Paddle1->Top-Ball->Height/2 && Ball->Top < Paddle1->Top+Paddle1->Height                && Ball->Left < Paddle1->Left+Paddle1->Width)
                {
                        if(x<0) x = -x;
                        count++;
                }

        //bounce against right paddle
        else if(Ball->Top > Paddle2->Top-Ball->Height/2 && Ball->Top < Paddle2->Top+Paddle2->Height                && Ball->Left+Ball->Width > Paddle2->Left)
                {
                        if(x>0) x = -x;
                        count++;
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
        if(START->Visible == false)
        {
                if(Key == 'W') Up1->Enabled = true;
                if(Key == 'S') Down1->Enabled = true;
                if(Key == VK_UP) Up2->Enabled = true;
                if(Key == VK_DOWN) Down2->Enabled = true;
        }
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
void __fastcall TForm1::STARTClick(TObject *Sender)
{
        Reset();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Ball->Left = 400;
        Ball->Top = 250;
        Paddle1->Top = 200;
        Paddle2->Top = 200;
        T_Ball->Enabled = false;
        Info->Visible = false;
        Bounce->Visible = false;
        Table->Visible = false;
        New_game->Visible = false;
        Time->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Defeat()
{
        T_Ball->Enabled = false;
        Ball->Visible = false;
        if(point1 < 6 && point2 < 6)
        {
                START->Caption = "Ponów grê";
                START->Visible = true;
        }
        Info->Visible = true;
        Bounce->Caption = "Liczba odbic: " + InttoString(count);
        Bounce->Visible = true;
        Table->Caption = InttoString(point1) + " : " + InttoString(point2);
        Table->Visible = true;
        New_game->Visible = true;
}

AnsiString __fastcall TForm1::InttoString(int number)
{
        AnsiString tmp;
        sprintf((char*)tmp.c_str(), "%d", number);
        AnsiString str = tmp.c_str();
        return str;
}
void __fastcall TForm1::New_gameClick(TObject *Sender)
{
       Reset();
       point1 = 0;
       point2 = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Reset()
{
        Ball->Left = 400;
        Ball->Top = 250;
        Paddle1->Top = 200;
        Paddle2->Top = 200;
        Ball->Visible = true;
        x = -8;
        y = -8;
        //T_Ball->Enabled = true;
        START->Visible = false;
        Info->Visible = false;
        count = 0;
        Bounce->Visible = false;
        Table->Visible = false;
        New_game->Visible = false;
        timeToStart = 3;
        T_Start->Enabled = true;
}
void __fastcall TForm1::T_StartTimer(TObject *Sender)
{
       Time->Visible = true;
       Time->Caption = timeToStart--;
       if(timeToStart < 0)
       {
                T_Ball->Enabled = true;
                Time->Visible = false;
                T_Start->Enabled = false;

       }
}
//---------------------------------------------------------------------------

