// Ivan Yeung
// 242. Valid Anagram

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (char c : s) {
            if (count.find(c) == count.end()) {
                count[c] = 0;
            }
            count[c]++;
        }

        for (char c : t) {
            if (count.find(c) == count.end()) return false;
            count[c]--;
        }

        for (const pair<char, int>& e : count) {
            if (e.second != 0) return false;
        }

        return true;
    }
};
