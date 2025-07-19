// Ivan Yeung
// 2. Add Two Numbers

#include <cstdlib>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        int carry = 0;
        while (l1->next && l2) {
            l1->val += l2->val + carry;
            carry = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                carry = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1->next == nullptr) {
            while (l2) {
                l1->val += l2->val + carry;
                carry = 0;
                if (l1->val > 9) {
                    l1->val -= 10;
                    carry = 1;
                }
                l2 = l2->next;
                if (l2 || carry != 0) {
                    l1->next = new ListNode();
                    l1 = l1->next;
                }
            }
        }

        while (carry != 0) {
            l1->val += carry;
            carry = 0;
            if (l1->val > 9) {
                l1->val -= 10;
                carry = 1;
            }
            if (l1->next == nullptr && carry != 0) l1->next = new ListNode();
            l1 = l1->next;
        }

        return res;
    }
};
