// Ivan Yeung
// 153. Find Minimum in Rotated Sorted Array

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int res = nums[left];

        while (left <= right) {
            int mid = (left + right) / 2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
