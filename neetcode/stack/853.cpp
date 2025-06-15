// Ivan Yeung
// 853.cpp

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs; // pair: (position, speed)
        vector<int> stack;
        for (int i = 0; i < position.size(); ++i) {
            pairs.push_back(make_pair(position[i], speed[i]));
        }
        // sorting in descending order
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());

        for (int i = 0; i < pairs.size(); ++i) {
            if (stack.empty()) {
                stack.push_back(i);
            } else if (pairs[i].second <= pairs[stack.back()].second) {
                stack.push_back(i);
            } else {
                int top = stack.back();
                double posDiff = pairs[top].first - pairs[i].first;
                double speedDiff = pairs[i].second - pairs[top].second;
                // checking if the car will catch up to current top of stack
                if (pairs[top].first + (posDiff / speedDiff) * pairs[top].second > target) {
                    stack.push_back(i);
                }
            }
        }

        return stack.size();
    }
};

