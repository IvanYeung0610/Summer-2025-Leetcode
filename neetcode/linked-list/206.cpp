// Ivan Yeung
// 206. Reverse Linked List

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        // iterative solution
        ListNode* res = head;
        ListNode* prev = nullptr;
        while (res != nullptr) {
            ListNode* nextNode = res->next;
            res->next = prev;
            prev = res;
            res = nextNode;
        }
        return res;
        */
        // recursive solution
        if (head == nullptr) return nullptr;
        ListNode* newHead = head;
        if (head->next != nullptr) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }

};
