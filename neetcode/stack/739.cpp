// Ivan Yeung
// 739. Daily Temperatures

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st; // stack of indexes
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[st.back()] < temperatures[i]) {
                res[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }

        return res;
    }
};
