//
// Created by Younghusband on 2024/8/30.
//
#include <iostream>
#include <list>
#include <unordered_map>

template<typename KeyType, typename ValueType>
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity_(capacity) {}

    ValueType get(const KeyType& key) {
        auto it = cache_map_.find(key);
        if (it == cache_map_.end()) {
            throw std::runtime_error("Key not found");
        } else {
            // 将访问的节点移到链表头部（表示最近使用）
            cache_list_.splice(cache_list_.begin(), cache_list_, it->second);
            return it->second->second;
        }
    }

    void put(const KeyType& key, const ValueType& value) {
        auto it = cache_map_.find(key);
        if (it != cache_map_.end()) {
            // 更新现有节点，将其移到链表头部
            cache_list_.splice(cache_list_.begin(), cache_list_, it->second);
            it->second->second = value;
        } else {
            // 如果缓存已满，移除最久未使用的节点
            if (cache_list_.size() == capacity_) {
                auto last = cache_list_.end();
                --last;
                cache_map_.erase(last->first);
                cache_list_.pop_back();
            }
            // 插入新节点
            cache_list_.emplace_front(key, value);
            cache_map_[key] = cache_list_.begin();
        }
    }

    void display() const {
        for (auto it = cache_list_.begin(); it != cache_list_.end(); ++it) {
            std::cout << it->first << ":" << it->second << " ";
        }
        std::cout << std::endl;
    }

private:
    size_t capacity_;
    std::list<std::pair<KeyType, ValueType>> cache_list_; // 双向链表用于维护LRU顺序
    std::unordered_map<KeyType, typename std::list<std::pair<KeyType, ValueType>>::iterator> cache_map_; // 哈希表用于快速查找

};

// int main() {
//     LRUCache<int, std::string> cache(3);
//
//     cache.put(1, "one");
//     cache.put(2, "two");
//     cache.put(3, "three");
//     cache.display(); // 显示缓存内容: 3:three 2:two 1:one
//
//     cache.get(2);
//     cache.display(); // 显示缓存内容: 2:two 3:three 1:one
//
//     cache.put(4, "four");
//     cache.display(); // 显示缓存内容: 4:four 2:two 3:three (1:one被移除)
//
//     return 0;
// }
