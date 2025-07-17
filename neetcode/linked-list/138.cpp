// Ivan Yeung
// 138. Copy List with Random Pointer

#include <cstddef>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {return nullptr;}
        // hashmap containing nodes
        unordered_map<Node*, Node*> map; // (old addr, new addr)
        Node* newHead = new Node(head->val);
        Node* res = newHead;
        map[head] = newHead;
        while (head) {
            if (map.find(head->next) == map.end()) {
                if (head->next == NULL) {
                    map[head->next] = NULL;
                } else {
                    map[head->next] = new Node(head->next->val);
                }
            }
            if (map.find(head->random) == map.end()) {
                if (head->random == NULL) {
                    map[head->random] = NULL;
                } else {
                    map[head->random] = new Node(head->random->val);
                }
            }
            newHead->next = map[head->next];
            newHead->random = map[head->random];
            newHead = newHead->next;
            head = head->next;
        }

        return res;
    }
};
