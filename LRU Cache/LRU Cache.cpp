#include <map>
#include <vector>
#include <algorithm>
#include <utility>

//   2015-5-30
//   Hint#: ref is a list used to store the pairs in order
//          cache is the map link the key value to the position of ref

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if(iter == cache.end()) return -1;
        else{
            movehead(key);
            return cache[key]->second;
        }
    }
    
    void set(int key, int value) {
        auto iter = cache.find(key);
        int n = cache.size();
        
        if(iter == cache.end()){
            if(n < capacity) {
                addhead(key, value);
            }
            else{
                deletekey();
                addhead(key, value);
            }
        }
        else{
            movehead(key);
            cache[key]->second = value;
        }
        
        return;
    }
    
private:
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> ref;
    int capacity;
    
    void movehead(int key){
        auto entry = *cache[key];
        ref.erase(cache[key]);
        ref.push_front(entry);
        cache[key] = ref.begin();
        return;
    }
    
    void addhead(int key, int value){
        pair<int, int> entry(key, value);
        ref.push_front(entry);
        cache[key] = ref.begin();
        return;
    }
    
    void deletekey(){
        int key = ref.back().first;
        cache.erase(cache.find(key));
        ref.pop_back();
        return;
    }
};