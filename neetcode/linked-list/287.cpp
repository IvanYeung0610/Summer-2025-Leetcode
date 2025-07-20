// Ivan Yeung
// 287. Find the Duplicate Number

#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int slow2 = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);

        // Floyd's Algorithm
        // This uses the fact that the intersection point of 
        // the fast and slow pointer is the same distance from the 
        // start of the cycle as the beginning is to the start of the
        // cycle
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
