// Ivan Yeung
// 125. Valid Palindrome

#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string formatted = "";
        // getting rid of non letters and making everything lowercase
        for (int i = 0; i < s.size() ; ++i) {
            // Upper case letters
            if (s[i] > 64 && s[i] < 91) {
                formatted.push_back(tolower(s[i]));
            }
            // Lower case letters
            if (s[i] > 96 && s[i] < 123) formatted.push_back(s[i]);
            // Numbers
            if (s[i] > 47 && s[i] < 58) formatted.push_back(s[i]);
        }

        int frontPtr = 0;
        int endPtr = formatted.size() - 1;

        while (frontPtr < endPtr) {
            if (formatted[frontPtr] != formatted[endPtr]) return false;
            frontPtr++;
            endPtr--;
        }

        return true;
    }
};
