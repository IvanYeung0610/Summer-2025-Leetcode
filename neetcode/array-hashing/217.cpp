// Ivan Yeung
// 217. Contains Duplicates

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> exist;

        for (int i : nums) {
            if (exist.find(i) != exist.end()) return true;
            exist.insert(i);
        }

        return false;
    }
};
