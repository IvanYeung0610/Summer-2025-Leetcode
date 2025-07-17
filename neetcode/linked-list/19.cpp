// Ivan Yeung
// 19. Remove Nth Node From End of List

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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        curr = nullptr;
        for (int i = 0; i < size - n; ++i) {
            if (curr != nullptr) {
                curr = curr->next;
            } else {
                curr = head;
            }
        }

        if (curr == nullptr) { // removing 1st ele
            return head->next;
        } else {
            curr->next = curr->next->next;
        }

        return head;
    }
};
