#ifndef BARAGE_H
#define BARAGE_H
#include"BUnit.h"

#include<string>
#include<vector>
using namespace std;
////////////////////




class Barage
{
    public:
        Barage();
        virtual ~Barage();
        void GetBarage();
        void GetBarageT();///temp function
        vector<BUnit>::iterator InsertBarage(BUnit nBarage,vector<BUnit>::iterator pos);
        vector<BUnit>::iterator DeleteBarage(vector<BUnit>::iterator pos);
        void Clear();
        void Compress();
        void Move();
        void InitTimer();
        void SetGap(int nGap)
        {
            gap=nGap;
        }
        void move();
        void setWnd(HWND hwnd)
        {
            this->hwnd=hwnd;
        }

        void draw(HDC hdc,HWND hwnd);
    protected:
    private:
        vector<BUnit> vec;
        vector<BUnit>::iterator it;
        HWND hwnd;
        int gap;
        int RollLineInformation[16];
        int StaticLineInformation[16];



};

#endif // BARAGE_H
