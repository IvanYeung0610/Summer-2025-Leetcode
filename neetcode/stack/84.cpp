// Ivan Yeung
// 84. Largest Rectangle in Histogram

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            int m = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                m = min(m, heights[j]);
                int area = m * (j - i + 1);
                if (area > maxArea) maxArea = area;
            }
        }

        return maxArea;
    }
};
