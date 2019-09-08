//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *Ball;
        TTimer *T_Ball;
        TImage *Paddle1;
        TImage *Paddle2;
        TTimer *Up1;
        TTimer *Down1;
        TTimer *Up2;
        TTimer *Down2;
        TButton *START;
        TLabel *Info;
        TLabel *Bounce;
        TLabel *Table;
        TButton *New_game;
        TTimer *T_Start;
        TLabel *Time;
        TLabel *Stopwatch;
        TTimer *T_Stopwatch;
        void __fastcall T_BallTimer(TObject *Sender);
        void __fastcall Up1Timer(TObject *Sender);
        void __fastcall Down1Timer(TObject *Sender);
        void __fastcall Up2Timer(TObject *Sender);
        void __fastcall Down2Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall STARTClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Defeat();
        AnsiString __fastcall InttoString(int number);
        void __fastcall New_gameClick(TObject *Sender);
        void __fastcall Reset();
        void __fastcall T_StartTimer(TObject *Sender);
        void __fastcall T_StopwatchTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
