
#include "Barage.h"
#include"BUnit.h"

#include<iostream>
#include<vector>
#include<wingdi.h>
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
    BUnit *nBar=new BUnit(10,"123456789",RGB(66,87,52),10);
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
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        it->left-=it->speed;
        //cout<<it->nLength;
        if(it->left<-(it->nLength))
            DeleteBarage(it);
    }


}

void Barage::draw(HDC hdc,HWND hwnd)
{
    HDC dc=CreateCompatibleDC(hdc);
    HBITMAP hBmp=CreateCompatibleBitmap(hdc,WIDTH,HEIGHT);
    HGDIOBJ hOld=SelectObject(dc,hBmp);
    SetTextColor(dc,RGB(210,45,78));
    SetBkMode(dc,TRANSPARENT);
	//Instance=hInstance;
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        LPTDFONT pFont;
        pFont=ChangeFontTd(dc,40);
        TextOut(dc,it->left,it->top,it->words.data(),it->words.size());
        DeleteFontTd(dc,pFont);

    }
    BitBlt(hdc,0,0,WIDTH,HEIGHT,dc,0,0,SRCCOPY);
    SelectObject(dc,hOld);
    DeleteObject(hBmp);
    ReleaseDC(hwnd,dc);

}
