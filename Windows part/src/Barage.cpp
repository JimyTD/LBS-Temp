
#include "Barage.h"
#include"BUnit.h"

#include<iostream>
#include<vector>
#include"externFunc.h"
using namespace std;

#define WIDTH 1024
#define HEIGHT 768
#define IDT_TIMER1 456


Barage::Barage()
{

    gap=10;
}

Barage::~Barage()
{
   vec.~vector<BUnit>();
}

void Barage::Clear()
{
    vec.clear();
}

void Barage::DeleteBarage(vector<BUnit>::iterator pos)
{
    vec.erase(pos);
}

void Barage::GetBarageT()
{
    BUnit *nBar=new BUnit(10,"sdasdsadas",RGB(66,87,52),10);
    InsertBarage(*nBar);


}
void Barage::InsertBarage(BUnit nBarage)
{
    vec.push_back(nBarage);
}

void Barage::Compress()
{
    vector<BUnit>(vec).swap(vec);
}


void Barage::InitTimer()
{
    SetTimer(hwnd,IDT_TIMER1,gap,NULL);
}

void Barage::move()
{
     cout<<1;
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        it->left-=it->speed;
    }


}

void Barage::draw(HDC hdc,HWND hwnd)
{
   // HDC dc=CreateCompatibleDC(hdc);
   // HBITMAP hBmp=CreateCompatibleBitmap(hdc,WIDTH,HEIGHT);
   // HGDIOBJ hOld=SelectObject(dc,hBmp);
	//Instance=hInstance;
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        //cout<<1;
        LPTDFONT pFont;
        pFont=ChangeFontTd(hdc,40);
        TextOut(hdc,it->left,it->top,it->words.data(),it->words.size());
        DeleteFontTd(hdc,pFont);

    }
   // BitBlt(hdc,0,0,WIDTH,HEIGHT,dc,0,0,PATPAINT);

}
