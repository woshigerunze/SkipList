template<typename K,typename V>
struct Entry
{
    K key;
    V value;
    Entry(K _key=K(),V _value=V()):key(_key),value(_value){}
    Entry(const Entry<K,V>& arg):key(arg.key),value(arg.value){}
    bool operator< (const Entry<K,V>& arg);
    bool operator> (const Entry<K,V>& arg);
    bool operator== (const Entry<K,V>& arg);
    bool operator!= (const Entry<K,V>& arg);
};
template<typename K,typename V>
bool Entry<K,V>::operator< (const Entry<K,V>& arg)
{
    return key<arg.key;
}
template<typename K,typename V>
bool Entry<K,V>::operator> (const Entry<K,V>& arg)
{
    return key>arg.key;
}
template<typename K,typename V>
bool Entry<K,V>::operator== (const Entry<K,V>& arg)
{
    return key==arg.key;
}
template<typename K,typename V>
bool Entry<K,V>::operator!= (const Entry<K,V>& arg)
{
    return key!=arg.key;
}
