#include "Barage.h"
#include<vector>
#define WIDTH 1024
#define HEIGHT 768
using namespace std;

Barage::Barage()
{
    //ctor
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

BUnit Barage::GetBarageT()
{
    BUnit nBar(10,"sdasdsadas",RGB(66,87,52),10);
    return nBar;

}
void Barage::InsertBarage(BUnit nBarage)
{
    vec.push_back(nBarage);
}

void Barage::Compress()
{
    vector<BUnit>(vec).swap(vec);
}


