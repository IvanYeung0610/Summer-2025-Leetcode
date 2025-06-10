// Ivan Yeung
// 150. Evaluate Reverse Polish Notation

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int first;
        int second;

        for (string token : tokens) {
            if (token == "+") {
                second = nums.top();
                nums.pop();
                first = nums.top();
                nums.pop();
                nums.push(first + second);
            } else if (token == "-") {
                second = nums.top();
                nums.pop();
                first = nums.top();
                nums.pop();
                nums.push(first - second);

            } else if (token == "*") {
                second = nums.top();
                nums.pop();
                first = nums.top();
                nums.pop();
                nums.push(first * second);
            } else if (token == "/") {
                second = nums.top();
                nums.pop();
                first = nums.top();
                nums.pop();
                nums.push(first / second);
            } else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};
