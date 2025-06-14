// Ivan Yeung
// 22. Generate Parentheses

#include <vector> 
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& res, string& comb) {
        // valid complete combination
        if (open == close && open == n) {
            res.push_back(comb);
        }

        // can still add an open parentheses
        if (open < n) {
            comb.push_back('(');
            backtrack(open + 1, close, n, res, comb);
            comb.pop_back();
        }

        // can add a closing parentheses
        if (close < open) {
            comb.push_back(')');
            backtrack(open, close + 1, n, res, comb);
            comb.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        backtrack(0, 0, n, res, s);
        return res;
    }
};
