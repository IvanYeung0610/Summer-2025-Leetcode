// Ivan Yeung
// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) { // one of the list is empty
            if (list1) {
                return list1;
            }
            return list2;
        }

        ListNode* res = list2;
        ListNode* head1 = list2; // pointer used to traverse main list
        ListNode* head2 = list1; // pointer used to travese other list

        if (list1->val < list2->val) {
            res = list1;
            head1 = list1;
            head2 = list2;
        }

        while (head1 && head2) {
            ListNode* next = head1->next;
            if (head2->val >= head1->val && (!next || head2->val <= next->val)) {
                head1->next = head2;
                head2 = head2->next;
                head1->next->next = next;
            }
                head1 = head1->next;
        }

        return res;
    }
};
