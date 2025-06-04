// Ivan Yeung
// 238. Product of Array Except Self

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /* Solution that cheats by using division operation
        // if there is more than 1 zero, everything is zero
        int zeroExist = 0;
        for (int i : nums) {
            if (i == 0) zeroExist++;
        }

        if (zeroExist > 1) return vector(nums.size(), 0);

        int totalProduct = 1;
        int count = 0;
        vector<int> res;

        for (int i : nums) {
            if (i != 0) totalProduct *= i;
        }

        for (int i : nums) {
            if (zeroExist) {
                if (i == 0) {
                    res.push_back(totalProduct);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(totalProduct / i);
            }
        }

        return res;
        */

        vector<int> res(nums.size());
        int prefix;
        int postfix;

        // inputing the relevant prefix products
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                prefix = nums[i];
                res[i] = 1;
            } else {
                res[i] = prefix;
                prefix *= nums[i];
            }
        }

        // multiplying stored prefix by corresponding postfix
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                postfix = nums[nums.size() - i - 1];
            } else {
                res[nums.size() - i - 1] *= postfix;
                postfix *= nums[nums.size() - i - 1];
            }
        }

        return res;
    }
};
