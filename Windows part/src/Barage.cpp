#include "Barage.h"
#include"BUnit.h"
#include<windows.h>
#include<iostream>
#include<vector>

#define WIDTH 1024
#define HEIGHT 768
#define IDT_TIMER1 456
using namespace std;

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
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        it->left-=it->speed;
    }


}

void Barage::draw(HDC hdc)
{
    if(vec.empty())return;
    for(it = vec.begin() ; it != vec.end() ; ++it)
    {
        cout<<it->words.data();
        TextOut(hdc,it->left,it->top,it->words.data(),it->words.size());

    }

}
