#include"ListNode.h"
template<typename T>
using Node = ListNode<T>;
template<typename T>
class List
{
    int _size;
    ListNode<T>* header;
    ListNode<T>* trailer;
protected:
    void init();
    void clear();
public:
    List(){init();}
    ~List(){clear();delete header;delete trailer;}
    int size(){return _size;}
    bool empty(){return _size<=0;};
    ListNode<T>* first() const{return header->succ;}
    ListNode<T>* last() const{return trailer->pred;}
    ListNode<T>* insertAsFirst(const T& e);
    ListNode<T>* insertAsLast(const T& e);
    void print();
};
template <typename T>
void List<T>::init()
{
    header=new ListNode<T>;
    trailer=new ListNode<T>;
    header->succ=trailer;
    header->pred=nullptr;
    trailer->pred=header;
    trailer->succ=nullptr;
}
template<typename T>
ListNode<T>* List<T>::insertAsLast(const T& e)
{
    _size++;
    ListNode<T>* x=new ListNode<T>(e);
    x->pred=trailer->pred;
    trailer->pred->succ=x;
    x->succ=trailer;
    trailer->pred=x;
    return x;
}
template<typename T>
ListNode<T>* List<T>::insertAsFirst(const T& e)
{
    _size++;
    ListNode<T>* x=new ListNode<T>(e);
    x->succ=header->succ;
    header->succ->pred=x;
    x->pred=header;
    header->succ=x;
    return x;
}
template<typename T>
void List<T>::print()
{
    for(ListNode<T>* x=header->succ;x!=trailer;x=x->succ)
    {
        std::cout<<x->data<<" ";
    }
    std::cout<<std::endl;
}
