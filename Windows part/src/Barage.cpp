
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
#define LINES 16



Barage::Barage()
{

    gap=10;
    for(int i=0;i<=15;i++)
   {
        LineInformation[i]=0;
    }
}

Barage::~Barage()
{
   vec.~vector<BUnit>();
}

void Barage::Clear()
{
    vec.clear();
}

vector<BUnit>::iterator Barage::DeleteBarage(vector<BUnit>::iterator pos)
{
    pos=vec.erase(pos);
    return pos;
}

void Barage::GetBarageT()
{
    for(int i=0;i<=15;i++)
    {
        if(LineInformation[i]==0)
        {
            Compress();
            BUnit *nBar=new BUnit(10,"123456789",RGB(66,87,52),10);
            nBar->line=i;
            InsertBarage(*nBar,vec.begin()+vec.capacity());
            LineInformation[i]=0;
            break;

        }
    }


}
vector<BUnit>::iterator Barage::InsertBarage(BUnit nBarage,vector<BUnit>::iterator pos)
{
    return vec.insert(pos,nBarage);
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
    memset(LineInformation,0,sizeof(LineInformation));
    if(vec.empty())return;
    it = vec.begin() ;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        it->left-=it->speed;
        //cout<<it->nLength;
        if(it->left<(-(it->nLength)))///出左界.
            {

                 cout<<vec.capacity();
                 it=DeleteBarage(it);
                 if(it==vec.end())
                   return;
            }
        if(it->left<WIDTH-it->nLength)///出有界
        {
            it->IsPass=1;
        }
        else
        {
            LineInformation[it->line]=1;
        }
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
        TextOut(dc,it->left,it->line*HEIGHT/LINES,it->words.data(),it->words.size());
        DeleteFontTd(dc,pFont);

    }
    BitBlt(hdc,0,0,WIDTH,HEIGHT,dc,0,0,SRCCOPY);
    SelectObject(dc,hOld);
    DeleteObject(hBmp);
    ReleaseDC(hwnd,dc);

}
