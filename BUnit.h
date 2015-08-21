#ifndef BUNIT_H
#define BUNIT_H
#include<string>
#include<windows.h>
#include<iostream>
#include"externFunc.h"
///////
#define POS_ROLL 758
#define POS_UP 714
#define POS_DOWN 452
#define LINES 16
#define STAYTIME 2000
///////
using namespace std;

class BUnit
{
    public:
        BUnit(int Size,char* Words,COLORREF Color,int Position,int gap);
        int CalculateLength()
        {
            return (int)(words.length()*PoundToPixel(nSize));
        }
        virtual ~BUnit();
        int nSize;
        string words;
        COLORREF color;
        int position;
        //CFont font;
        int left;
        int line;
        int speed;
        int nLength;
        int IsPass;
        int showTime;

    protected:
    private:
};

#endif // BUNIT_H