#include"QuadListNode.h"
template<typename T>
class QuadList
{
    int _size;
    QuadListNode<T>* header;
    QuadListNode<T>* trailer;
protected:
    void init();
    void clear();
public:
    QuadList(){init();}
    ~QuadList(){clear();delete header;delete trailer;}
    int size(){return _size;}
    bool empty(){return _size<=0;}
    QuadListNode<T>* first() const{return header->succ;}
    QuadListNode<T>* last()  const{return trailer->pred;}
    QuadListNode<T>* insertAsFirst(const T& entry);
    QuadListNode<T>* insertAsLast (const T& entry);
    QuadListNode<T>* insertAfterAbove(const T& entry,
                                      QuadListNode<T>* p,
                                      QuadListNode<T>* b=nullptr);
    
    bool valid(QuadListNode<T>* x){return x!=nullptr&&x!=header&&x!=trailer;}
    void remove(QuadListNode<T>* x);
};
template<typename T>
void QuadList<T>::init()
{
    header=new QuadListNode<T>;
    trailer=new QuadListNode<T>;
    header->succ=trailer;
    header->pred=nullptr;
    trailer->pred=header;
    trailer->succ=nullptr;
    _size=0;
}
template<typename T>
QuadListNode<T>* QuadList<T>::insertAsFirst(const T& entry)
{
    _size++;
    QuadListNode<T>* x=new QuadListNode<T>(entry);
    x->succ=header->succ;
    header->succ->pred=x;
    x->pred=header;
    header->succ=x;
    return x;
}
template<typename T>
QuadListNode<T>* QuadList<T>::insertAsLast(const T& entry)
{
    _size++;
    QuadListNode<T>* x=new QuadListNode<T>(entry);
    x->pred=trailer->pred;
    trailer->pred->succ=x;
    x->succ=trailer;
    trailer->pred=x;
    return x;
}
template<typename T>
QuadListNode<T>* QuadList<T>::insertAfterAbove(const T& entry,
                                               QuadListNode<T>* p,
                                               QuadListNode<T>* b)
{
    _size++;
    return p->insertAsSuccAbove(entry,b);
}
template<typename T>
void QuadList<T>::remove(QuadListNode<T>* x)
{
    //std::cout<<x->entry.value<<std::endl;
    x->pred->succ=x->succ;
    x->succ->pred=x->pred;
    delete x;
}
template<typename T>
void QuadList<T>::clear()
{
    while(_size--)
    {
        remove(header->succ);
    }
}
