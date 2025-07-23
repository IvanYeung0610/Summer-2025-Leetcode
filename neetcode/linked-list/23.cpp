// Ivan Yeung
// 23. Merge k Sorted Lists

#include <vector>

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
    ListNode* mergeTwo(ListNode* one, ListNode* two) {
        // empty list case
        if (one == nullptr) return two;
        if (two == nullptr) return one;

        ListNode* res;
        ListNode* small = one;
        ListNode* big = two;
        if (one->val > two->val) {
            swap(big, small);
        }
        res = small;

        while (big && small->next) {
            if (big->val >= small->val && 
                (big->val <= small->next->val)) {
                ListNode* sTemp = small->next;
                ListNode* bTemp = big->next;
                small->next = big;
                big->next = sTemp;
                big = bTemp;
            }
            small = small->next;
        }
        if (big) {
            small->next = big;
        }

        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        /* O(n * k) solution
        ListNode* res = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            res = mergeTwo(res, lists[i]);
        }
        */

        // by combining by pairs, we avoid repeated work which results in a faster runtime O(nlogk)
        while (lists.size() > 1) {
            vector<ListNode*> mergedList;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedList.push_back(mergeTwo(l1, l2));
            }
            lists = mergedList;
        }

        return lists[0];
    }
};
