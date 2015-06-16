#include "BUnit.h"
#define WIDTH 1024
#define HEIGHT 768
#include<string>
#include<iostream>
using namespace std;
BUnit::BUnit(int Size,char* Words,COLORREF Color,int Speed)
{
    nSize=Size;
    words=Words;
    color=Color;
    speed=Speed;
    left=WIDTH;
    int a=rand();
    top=600;//a%HEIGHT-100;
}

BUnit::~BUnit()
{
    //dtor
}
