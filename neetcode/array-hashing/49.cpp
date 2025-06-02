// Ivan Yeung
// 49. Group Anagrams

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(str);
        }

        for (const pair<string, vector<string>>& pair : map) {
            res.push_back(pair.second);
        }

        return res;
    }
};
