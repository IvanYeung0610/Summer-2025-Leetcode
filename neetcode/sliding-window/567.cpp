// Ivan Yeung
// 567. Permutation in String

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> ref; // letter frequencies of s1
        unordered_map<char, int> track; // letter frequencies of the window on s2
        int left = 0;
        int right = 0;

        for (char c : s1) {
            ref[c]++;
        }
        track = ref;

        while (right < s2.size()) {
            if (ref.find(s2[right]) == ref.end()) {
                track = ref;
                right++;
                left = right;
            } else {
                if (track.find(s2[right]) == track.end()) {
                    while (s2[left] != s2[right]) {
                        track[s2[left]]++;
                        left++;
                    }
                    track[s2[left]]++;
                    left++;
                }
                track[s2[right]]--;
                if (track[s2[right]] == 0) track.erase(s2[right]);
                if (track.empty()) return true;
                right++;
            }
        }

        return false;
    }
};
