// Ivan Yeung
// 271. Encode and Decode Strings

#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (string& s : strs) {
            res.append(to_string(s.size()) + " " + s);
        }

        return res;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string> res;

        while (index != s.size()) {
            string length;
            string str;

            while (s[index] != ' ') {
                length.push_back(s[index]);
                index++;
            }
            index++;

            for (int i = 0; i < stoi(length); ++i) {
                str.push_back(s[index]);
                index++;
            }

            res.push_back(str);
        }

        return res;
    }
};
