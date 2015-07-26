#include "BUnit.h"
#define WIDTH 1024
#define HEIGHT 768
#define LINES 16
#define STAYTIME 3000
#include<string>
#include<iostream>
using namespace std;
BUnit::BUnit(int Size,char* Words,COLORREF Color)
{
    nSize=Size;
    words=Words;
    color=Color;
    //speed=;
    left=WIDTH;
    int a=rand();
    nLength=CalculateLength()+100;//提前给予一定缓冲空间
    IsPass=0;
}

BUnit::~BUnit()
{
    //dtor
}
