// Ivan Yeung
// 25. Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* last;
        ListNode* nextL;
        ListNode* res;
        // first iteration done seperate to get the head of res
        for (int i = 1; i < k; ++i) {
            end = end->next;
        }
        ListNode* prev = nullptr;
        nextL = end->next;
        while (head != nextL) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        res = end;
        last = start;
        start->next = head;
        while (head && head->next) {
            start = head;
            end = head;
            for (int i = 1; i < k; ++i) {
                if (end->next == nullptr) return res;
                end = end->next;
            }
            nextL = end->next;
            while (head != nextL) {
                ListNode* temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            last->next = end;
            start->next = head;
            last = start;
        }

        return res;
    }
};
