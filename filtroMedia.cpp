//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "filtroMedia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
//  Image1->Picture->LoadFromFile("cg.bmp"); // Carregando imagem
	Image1->Picture->LoadFromFile("branc.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	int x, y, r, b, g;

	for(x = 0; x < Image1->Width; x++){
		for(y = 0; y < Image1->Height; y++){
			r = GetRValue(Image1->Canvas->Pixels[x-1][y-1]) + GetRValue(Image1->Canvas->Pixels[x][y-1]) + GetRValue(Image1->Canvas->Pixels[x+1][y-1]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y]) + GetRValue(Image1->Canvas->Pixels[x][y]) + GetRValue(Image1->Canvas->Pixels[x+1][y]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y+1]) + GetRValue(Image1->Canvas->Pixels[x][y+1]) + GetRValue(Image1->Canvas->Pixels[x+1][y+1]);
			r = (int)(r/9);

			b = GetRValue(Image1->Canvas->Pixels[x-1][y-1]) + GetRValue(Image1->Canvas->Pixels[x][y-1]) + GetRValue(Image1->Canvas->Pixels[x+1][y-1]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y]) + GetRValue(Image1->Canvas->Pixels[x][y]) + GetRValue(Image1->Canvas->Pixels[x+1][y]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y+1]) + GetRValue(Image1->Canvas->Pixels[x][y+1]) + GetRValue(Image1->Canvas->Pixels[x+1][y+1]);
			b = (int)(b/9);

			g = GetRValue(Image1->Canvas->Pixels[x-1][y-1]) + GetRValue(Image1->Canvas->Pixels[x][y-1]) + GetRValue(Image1->Canvas->Pixels[x+1][y-1]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y]) + GetRValue(Image1->Canvas->Pixels[x][y]) + GetRValue(Image1->Canvas->Pixels[x+1][y]) +
					   GetRValue(Image1->Canvas->Pixels[x-1][y+1]) + GetRValue(Image1->Canvas->Pixels[x][y+1]) + GetRValue(Image1->Canvas->Pixels[x+1][y+1]);
			g = (int)(g/9);

			Image1->Canvas->Pixels[x][y] = RGB(r,g,b);
		}
	}
};
//---------------------------------------------------------------------------
