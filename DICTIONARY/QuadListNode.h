#include"Entry.h"
template<typename T>
struct QuadListNode
{
    T entry;
    QuadListNode<T>* pred;
    QuadListNode<T>* succ;
    QuadListNode<T>* above;
    QuadListNode<T>* below;
    QuadListNode(T _entry=T(),
                 QuadListNode<T>* _pred=nullptr,
                 QuadListNode<T>*_succ=nullptr,
                 QuadListNode<T>* _above=nullptr,
                 QuadListNode<T>* _below=nullptr):
    entry(_entry),pred(_pred),succ(_succ),above(_above),below(_below){}
    
    QuadListNode<T>* insertAsSuccAbove(const T& entry,QuadListNode<T>* b=nullptr);
};
template<typename T>
QuadListNode<T>* QuadListNode<T>::insertAsSuccAbove(const T& entry,QuadListNode<T>* b)
{
    QuadListNode<T>* x=new QuadListNode<T>(entry,this,succ,nullptr,b);
    succ->pred=x;
    succ=x;
    if(b!=nullptr)b->above=x;
    return x;
}
