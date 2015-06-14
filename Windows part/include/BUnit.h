#ifndef BUNIT_H
#define BUNIT_H
#include<string>
#include<windows.h>
///////
#define POS_DOWN 758
#define POS_UP 714
#define POS_SPECIAL 452
///////
using namespace std;

class BUnit
{
    public:
        BUnit(int Size,char* Words,COLORREF Color,int Speed);
        virtual ~BUnit();
        int nSize;
        string words;
        COLORREF color;
        int position;
        //CFont font;
        int left;
        int top;
        int speed;

    protected:
    private:
};

#endif // BUNIT_H
