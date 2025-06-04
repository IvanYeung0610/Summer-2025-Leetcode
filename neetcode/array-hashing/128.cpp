// Ivan Yeung
// 128. Longest Consecutive Sequence

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> starts; // vector storing numbers that could be the start of a seq
        int max = 0;

        for (int i : set) {
            if (set.find(i - 1) == set.end()) starts.push_back(i);
        }

        for (int i : starts) {
            int count = 1;
            while (set.find(i + count) != set.end()) {
                count++;
            }
            if (count > max) max = count;
        }

        return max;

    }
};
