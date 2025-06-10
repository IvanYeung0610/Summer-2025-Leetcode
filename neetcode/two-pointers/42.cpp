// Ivan Yeung
// 42. Trapping Rain Water

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0;
        int rightmax = 0;
        int temp = 0;
        int water = 0;

        // going from the start
        for (int i : height) {
            if (i < leftmax) {
                temp += leftmax - i;
            } else {
                water += temp;
                leftmax = i;
                temp = 0;
            }
        }

        temp = 0;
        // going from the back
        // does not do equal to case to prevent repetition
        for (int i = height.size() ; i > 0; --i) {
            if (height[i - 1] < rightmax) {
                temp += rightmax - height[i - 1]; 
            } else if (height[i - 1] > rightmax) {
                water += temp;
                rightmax = height[i - 1];
                temp = 0;
            }
        }

        return water;
    }
};
