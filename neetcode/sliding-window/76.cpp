// Ivan Yeung
// 76. Minimum Window Substring

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return "";

        int left = 0;
        int right = 0;
        int need = 0;
        int have = 0;
        int res = 0;
        int resLen = 0;
        unordered_map<char, int> ref;
        unordered_map<char, int> window;

        for (char c : t) {
            ref[c]++;
        }
        need = ref.size();

        while (right < s.size()) {
            if (ref.find(s[right]) != ref.end()) { // if it is a character in t
                window[s[right]]++;
                if (window[s[right]] == ref[s[right]]) have++;
            }

            if (have == need) {
                    if (resLen == 0 || resLen > (right - left + 1)) {
                        res = left;
                        resLen = (right - left + 1);
                    }
            }

            while (have == need) {
                if (resLen == 0 || resLen > (right - left + 1)) {
                    res = left;
                    resLen = (right - left + 1);
                }

                if (ref.find(s[left]) != ref.end()) {
                    if (window[s[left]] == ref[s[left]]) have--;
                    window[s[left]]--;
                }

                left++;
            }

            right++;
        }

        if (resLen == 0) return "";

        return s.substr(res, resLen);
    }
};
