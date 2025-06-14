// Ivan Yeung
// 84. Largest Rectangle in Histogram

#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // pair: (index, height)
        int index = 0;
        int maxArea = 0;

        while (index < heights.size()) {
            int lastIndex = index; // keeps index of last popped element
            while (!st.empty() && st.top().second >= heights[index]) {
                int area = st.top().second * (index - st.top().first);
                if (area > maxArea) maxArea = area;
                lastIndex = st.top().first;
                st.pop();
            }

            if (st.empty() || heights[index] > st.top().second) {
                st.push(make_pair(lastIndex, heights[index]));
            }

            index++;
        }

        // calculates the remaining heights in the stack
        while (!st.empty()) {
                int area = st.top().second * (heights.size() - st.top().first);
                if (area > maxArea) maxArea = area;
                st.pop();
        }

        return maxArea;
    }
};
