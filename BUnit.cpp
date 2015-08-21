#include "BUnit.h"
#define WIDTH 1024
#define HEIGHT 768
#define LINES 16
#define POS_ROLL 758
#define POS_UP 714
#define POS_DOWN 452
#include<string>
#include<iostream>
using namespace std;
BUnit::BUnit(int Size,char* Words,COLORREF Color,int Position,int gap)
{
    position=Position;
    nSize=Size;
    words=Words;
    color=Color;
    left=WIDTH;
    int a=rand();
    nLength=CalculateLength()+100;//提前给予一定缓冲空间
    IsPass=0;
    if(position==POS_ROLL)speed=(WIDTH+nLength)/(STAYTIME/gap);
    else speed=0;
    if(position!=POS_ROLL)showTime=3000;//默认
    if(position==POS_DOWN||position==POS_UP)
    {
        left=WIDTH/2-nLength/2;
    }
}

BUnit::~BUnit()
{
    //dtor
}
