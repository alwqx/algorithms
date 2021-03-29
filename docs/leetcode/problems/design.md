# 架构设计类

# [355. 设计推特](https://leetcode-cn.com/problems/design-twitter/)
感觉有点绕，需要定义struct简化数据结构的使用，参考其中的用法。

# [146. LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)
读写数据，当缓冲区满时，在写入新数据之前删除`最久未使用的数据值`，从而为新的数据值留出空间。

```cpp
class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> m;

public:
    LRUCache(int capacity):cap(capacity) {}

    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        auto value = *m[key];
        cache.erase(m[key]);
        cache.push_front(value);
        m[key] = cache.begin();

        return value.second;
    }

    void put(int key, int value) {
        if(m.find(key) == m.end()) {
            if(cache.size() == cap) {
                m.erase(cache.back().first);
                cache.pop_back();
            }
        } else cache.erase(m[key]);

        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};
 ```