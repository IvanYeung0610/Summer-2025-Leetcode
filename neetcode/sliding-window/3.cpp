// Ivan Yeung
// 3. Longet Substring Without Repeating Characters

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int maxLen = 0;
        unordered_map<char, int> map; // map of char to index

        while (end < s.size()) {
            if (map.find(s[end]) == map.end()) {
                map[s[end]] = end;
                end++;
            } else {
                start = max(map[s[end]] + 1, start); // new start at index after repeat
                map[s[end]] = end;
                end++;
            }
            maxLen = max(maxLen, end - start);
        }

        return maxLen;
    }
};
