// Ivan Yeung
// 20. Valid Parentheses

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.size() == 0) return false; // empty case
                int top = st.top();
                st.pop();
                if (c == ')') {
                    if (top != '(') return false;
                } else if (c == ']') {
                    if (top != '[') return false;
                } else {
                    if (top != '{') return false;
                }
            }
        }

        return st.size() == 0;
    }
};
