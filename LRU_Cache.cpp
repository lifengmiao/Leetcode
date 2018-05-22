//http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html
/*
首先，对于cache，如果希望有O(1)的查找复杂度，肯定要用hashmap来保存key和对象的映射。对于LRU而言，问题在于如何用O(1)解决cache entry的替换问题。

简单的说，cache的存储是一个链表的话，那么只要保证从头到尾的顺序就是cache从新到旧的顺序就好了，对于任何一个节点，如果被访问了，那么就将该节点移至头部。如果cache已满，那么就把尾部的删掉，从头部插入新节点。

所以，需要用到两个数据结构

1. hashmap， 保存key和对象位置的映射

2. list，保存对象新旧程度的序列。不一定是list，也可以用vector，不过list的好处是已经实现了头尾操作的api，vector的话，还要自己写，麻烦。
   list api: list.push_front(element), list.pop_back(), list.erase(iterator)
*/

class LRUCache {
public:
    struct CacheEntry { //Entry in Cache memory save both key and val; key is for moveTohead and remove elment from hashtable
    public:
        int key;
        int val;
        CacheEntry(int k, int v):key(k), val(v) {}
    };
    
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(m_map.find(key)==m_map.end())
            return -1;
        moveTohead(key);
        return m_map[key]->val; //m_map[key] is an iterator point to Entry in Cache list, which is CacheEntry. So it has two member, key and val. This key is equal to the key in hashtable
    }
    
    void put(int key, int value) {
        if(m_map.find(key)==m_map.end()) {
            CacheEntry newItem(key, value);
            if(m_LRU_cache.size()>=m_capacity) {
                m_map.erase(m_LRU_cache.back().key);//use key saved in cache memory to erase element in hashmap
                m_LRU_cache.pop_back();
            }
            m_LRU_cache.push_front(newItem);
            m_map[key]=m_LRU_cache.begin();
        }
        else {
            m_map[key]->val = value; //use hashtable to find entry in cache
            moveTohead(key);
        }
    }
private:
    unordered_map<int, list<CacheEntry>::iterator> m_map; //map key with the position Entry is saved in Cache 
    list<CacheEntry> m_LRU_cache; //main Cache memory
    int m_capacity;
    
    void moveTohead(int key) {
        CacheEntry Entry_tmp = *m_map[key];
        m_LRU_cache.erase(m_map[key]); // hashmap存iterator是为了这里删除element时方便；
        m_LRU_cache.push_front(Entry_tmp);
        m_map[key] = m_LRU_cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
