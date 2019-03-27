#include"List.h"
#include"Dictionary.h"
#include"QuadList.h"
template<typename K,typename V>
class SkipList:public Dictionary<K, V>,public List<QuadList<Entry<K,V>>*>
{
protected:
    bool SkipSearch(ListNode<QuadList<Entry<K,V>>*>* &qlist,
                    QuadListNode<Entry<K,V>>* &p,
                    K& k);
public:
    int size() const
    {return List<QuadList<Entry<K,V>>*>::empty()? 0: List<QuadList<Entry<K,V>>*>::last()->data->size();
    }
    int level(){return List<QuadList<Entry<K,V>>*>::size();}
    bool put(K,V);
    V* get(K k);
    bool remove(K k);
};
