// Ivan Yeung
// 141. Linked List Cycle

#include <cstdio>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // solution changing the Linked List
        /*
        ListNode* start = head;
        while (head != nullptr) {
            if (head->next == start) {
                return true;
            }
            ListNode* temp = head->next;
            head->next = start;
            head = temp;
        }
        return false;
        */
        // fast and slow pointer solution
        // fast pointer moves by 2, slow pointer moves by 1
        // if there is a cycle slow and fast pointer will meet
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;

    }
};
