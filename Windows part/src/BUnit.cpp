#include "BUnit.h"
#define WIDTH 1024
#define HEIGHT 768
#define LINES 16
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
    line=a%16;
    nLength=CalculateLength()+50;//��ǰ����һ������ռ�
    IsPass=0;
}

BUnit::~BUnit()
{
    //dtor
}
