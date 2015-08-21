
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
#define STAYTIME 2000
#define POS_ROLL 758
#define POS_UP 714
#define POS_DOWN 452



Barage::Barage()
{

    gap=20;
    for(int i=0;i<=15;i++)
    {
        RollLineInformation[i]=0;
    }
    for(int i=0;i<=15;i++)
    {
        StaticLineInformation[i]=0;
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
    int temp=rand()%3;
    if(temp==0)//roll
        for(int i=0;i<=15;i++)
        {
            if(RollLineInformation[i]==0)
            {
                Compress();
                BUnit *nBar=new BUnit(10,"123456789",RGB(66,87,52),POS_ROLL,gap);
                nBar->line=i;
                InsertBarage(*nBar,vec.begin()+vec.capacity());
                break;///////////////////////////是否要DELETE待定

            }
        }
    if(temp==1)//up
        for(int i=0;i<=7;i++)
        {
            if(StaticLineInformation[i]==0)
            {
                Compress();
                BUnit *nBar=new BUnit(10,"123456789",RGB(66,87,52),POS_UP,gap);
                nBar->line=i;
                InsertBarage(*nBar,vec.begin()+vec.capacity());
                break;///////////////////////////是否要DELETE待定

            }
        }
    if(temp==2)//down
        for(int i=15;i>=8;i--)
        {
            if(StaticLineInformation[i]==0)
            {
                Compress();
                BUnit *nBar=new BUnit(10,"123456789",RGB(66,87,52),POS_DOWN,gap);
                nBar->line=i;
                InsertBarage(*nBar,vec.begin()+vec.capacity());
                break;///////////////////////////是否要DELETE待定

            }
        }
}
vector<BUnit>::iterator Barage::InsertBarage(BUnit nBarage,vector<BUnit>::iterator pos)
{
    return vec.insert(pos,nBarage);
}

void Barage::Compress()
{
    vector<BUnit>(vec).swap(vec);//压缩空间。
}


void Barage::InitTimer()
{
    SetTimer(hwnd,IDT_TIMER1,gap,NULL);
}

void Barage::move()
{
    memset(RollLineInformation,0,sizeof(RollLineInformation));
    memset(StaticLineInformation,0,sizeof(RollLineInformation));
    if(vec.empty())return;
    it = vec.begin() ;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        if(it->position==POS_ROLL)
        {
            it->left-=it->speed;
            //cout<<it->nLength;
            if(it->left<(-(it->nLength)))///出左界.
                {

                     cout<<vec.capacity();///test
                     it=DeleteBarage(it);
                     if(it==vec.end())
                       return;
                }
            if(it->left<WIDTH-it->nLength)///出右界
            {
                it->IsPass=1;
            }
            else
            {
                RollLineInformation[it->line]=1;
            }
        }


        if(it->position==POS_DOWN||it->position==POS_UP)
        {
            it->showTime-=gap;
            if(it->showTime<=0)
            {
                it=DeleteBarage(it);
                if(it==vec.end())
                    return;
            }
            else
            {
                StaticLineInformation[it->line]=1;
            }
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
