// Ivan Yeung
// 143. Reorder List

#include <deque>

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
    void reorderList(ListNode* head) {
        // solution using a deque
        /*
        if (!head) return;

        deque<ListNode*> nodes;

        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }

        bool swap = true;
        head = nodes.front();
        nodes.pop_front();
        while (!nodes.empty()) {
            if (swap) {
                head->next = nodes.back();
                nodes.pop_back();
            } else {
                head->next = nodes.front();
                nodes.pop_front();
            }
            head = head->next;
            swap = !swap;
        }
        head->next = nullptr;

        return;
        */

        // O(1) Memory solution
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* reverse;

        // spliting lists into 2 at midpoint (everything to left shouldn't change)
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        reverse = slow->next;
        slow->next = nullptr;

        // reverse the reverse list
        ListNode* temp;
        ListNode* temp2;
        ListNode* prev = nullptr;
        while (reverse != nullptr) {
            temp = reverse->next;
            reverse->next = prev;
            prev = reverse;
            reverse = temp;
        }
        reverse = prev;

        // combine the two list
        while (head != nullptr && reverse != nullptr) {
            temp = head->next;
            temp2 = reverse->next;
            head->next = reverse;
            reverse->next = temp;
            head = temp;
            reverse = temp2;
        }

        return;
    }
};
