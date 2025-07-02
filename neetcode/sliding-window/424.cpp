// Ivan Yeung
// 424. Longest Repeating Character Replacement

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k)  {
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int res = 0;
        vector<int> freq(26, 0); // 0->A, 1->B, ..., 25->Z

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            // fixes window when there are too many replacements
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
