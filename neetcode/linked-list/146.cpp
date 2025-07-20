// Ivan Yeung
// 146. LRU Cache

#include <cstdlib>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;
    Node() : val(0), key(0), next(nullptr), prev(nullptr) {}
    Node(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
    Node(int x, int y, Node* prev, Node* next) : val(x), key(y), prev(prev), next(next) {}
};

class LRUCache {
    /*
     * Most recently used items will be attached to header
     * and least recently used items will be attached to
     * trailer
     */
public:
    LRUCache(int capacity) {
        cap = capacity;
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node* tmpPrev = map[key]->prev;
        Node* tmpNext = map[key]->next;
        // removing from current location
        tmpNext->prev = tmpPrev;
        tmpPrev->next = tmpNext;
        // moving to the front
        tmpNext = header->next;
        header->next = map[key];
        tmpNext->prev = map[key];
        map[key]->next = tmpNext;
        map[key]->prev = header;

        return map[key]->val;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key]->val = value;
            // removing node from current position
            map[key]->prev->next = map[key]->next;
            map[key]->next->prev = map[key]->prev;
        } else {
            map[key] = new Node(key, value);
            // removing least recently used if necessary
            if (cap < map.size()) {
                Node* least = trailer->prev;
                trailer->prev = least->prev;
                least->prev->next = trailer;
                map.erase(least->key);
                delete least;
                least = nullptr;
            }
        }
        // moving node to front
        Node* tmpNext = header->next;
        map[key]->next = tmpNext;
        map[key]->prev = header;
        header->next = map[key];
        tmpNext->prev = map[key];
    }
private:
    int cap;
    unordered_map<int, Node*> map;
    Node* header;
    Node* trailer;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
