//
// Created by Younghusband on 2024/8/30.
//


#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;  // 缓存容量
    std::list<std::pair<int, int>> lruList; // 存储键值对
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // 快速查找
public:

    LRUCache(int capacity) : capacity(capacity) {}

    // 获取值
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // 键不存在
        }
        // 移动到列表前面
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second; // 返回值
    }

    // 放入键值对
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // 更新值并移动到前面
            cache[key]->second = value; // 更新值
            lruList.splice(lruList.begin(), lruList, cache[key]);
        } else {
            // 检查是否超出容量
            if (lruList.size() == capacity) {
                // 删除最久未使用的元素
                cache.erase(lruList.back().first);
                lruList.pop_back(); // 删除链表最后一个元素
            }
            // 插入新元素
            lruList.emplace_front(key, value);
            cache[key] = lruList.begin(); // 更新哈希表
        }
    }
};

