#include<iostream>
#include"SkipList.h"
using namespace std;
int main()
{
    QuadList<Entry<int,int>> test;
    for(int i=0;i<10;i++)
    {
        Entry<int,int> entry(i,i);
        test.insertAsLast(entry);
    }
}
