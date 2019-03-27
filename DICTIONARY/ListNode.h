template<typename T>
struct ListNode
{
    T data;
    ListNode<T>* pred;
    ListNode<T>* succ;
    ListNode(){}
    ListNode(T _data,ListNode<T>* p=nullptr,ListNode<T>* q=nullptr)
    :data(_data),pred(p),succ(q){}
};
