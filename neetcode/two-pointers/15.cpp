// Ivan Yeung
// 15. 3Sum

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        // sort input array to prevent duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum < 0) {
                    start++;
                } else if (sum > 0) {
                    end--;
                } else {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    // needs to check for same num here to avoid adding duplicates
                    while (nums[start] == nums[start - 1] && start < end) {
                        start++;
                    }
                }
            }
        }

        return res;

    }
};
