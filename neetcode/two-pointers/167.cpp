// Ivan Yeung
// 167. Two Sum II - Input Array is Sorted

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int frontPtr = 0;
        int endPtr = numbers.size() - 1;
        vector<int> res;

        while (numbers[frontPtr] + numbers[endPtr] != target) {
            if (numbers[frontPtr] + numbers[endPtr] > target) {
                endPtr--;
            } else {
                frontPtr++;
            }
        }
        // adding one is it is "1-indexed array"
        res.push_back(frontPtr + 1);
        res.push_back(endPtr + 1);

        return res;
    }
};
