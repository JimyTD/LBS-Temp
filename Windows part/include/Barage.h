#ifndef BARAGE_H
#define BARAGE_H
#include"BUnit.h"

#include<string>
#include<vector>
using namespace std;
class Barage
{
    public:
        Barage();
        virtual ~Barage();
        void GetBarage();
        void GetBarageT();
        void InsertBarage(BUnit nBarage);
        void DeleteBarage(vector<BUnit>::iterator pos);
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


};

#endif // BARAGE_H
