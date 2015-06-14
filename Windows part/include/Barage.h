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
        BUnit GetBarageT();
        void InsertBarage(BUnit nBarage);
        void DeleteBarage(vector<BUnit>::iterator pos);
        void Clear();
        void Compress();
        void Move();

    protected:
    private:
        vector<BUnit> vec;


};

#endif // BARAGE_H
