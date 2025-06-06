// Ivan Yeung
// 11. Container With Most Water

#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            if (maxArea < (right - left) * min(height[left], height[right])) {
                maxArea = (right - left) * min(height[left], height[right]);
            }
            // moving the pointer to the shorter line
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }
};
