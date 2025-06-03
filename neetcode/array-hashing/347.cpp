// Ivan Yeung
// 347. Top K Frequent Elements

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> pairs;
        vector<int> res;

        for (int i : nums) {
            freq[i]++;
        }

        for (const pair<int, int>& ele : freq) {
            pairs.push_back(make_pair(ele.second, ele.first)); // swap so that frequence comes first
        }

        sort(pairs.begin(), pairs.end());

        for (int i = 1; i < k + 1; ++i) {
            res.push_back(pairs[pairs.size() - i].second);
        }

        return res;

    }
};
