// Ivan Yeung
// 239. Sliding Window Maximum

#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        int left = 0;
        int right = 0;

        // creating the initial window
        while (right < k - 1) {
            // making sure the deque is monotonic (increasing)
            while (!deq.empty() && nums[deq.back()] < nums[right]) {
                deq.pop_back();
            }
            deq.push_back(right);
            right++;
        }

        while (right < nums.size()) {
            // removing elements that are no longer within window
            while (!deq.empty() && deq.front() < left) {
                deq.pop_front();
            }
            // making sure the deque is monotonic (increasing)
            while (!deq.empty() && nums[deq.back()] < nums[right]) {
                deq.pop_back();
            }
            deq.push_back(right);

            res.push_back(nums[deq.front()]);
            left++;
            right++;
        }

        return res;
    }
};
