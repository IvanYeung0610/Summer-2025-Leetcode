// Ivan Yeung
// 1290. Convert Binary Number in a Linked List to Integer

#include <cmath>

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
    int getDecimalValue(ListNode* head) {
        int res;
        int count;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        int mult = pow(2, count);
        while (head) {
            res += head->val * mult;
            head = head->next;
            mult /= 2;
        }

        return res;
    }
};
