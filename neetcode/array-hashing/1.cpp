// Ivan Yeung
// 1. Two Sum

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = {i};
            } else {
                map[nums[i]].push_back(i);
            }
        }

        for (const pair<int, vector<int>>& ele : map) {
            int other = target - ele.first;
            if (ele.first == other && ele.second.size() == 2) return ele.second;
            if (map.find(other) != map.end() && other != ele.first) {
                res.push_back(ele.second[0]);
                res.push_back(map[other][0]);
                return res;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> test = {2, 4, 11, 3};
    vector<int> res = sol.twoSum(test, 6);
    
    for (int i : res) {
        cout << i << " ";
    }
}
