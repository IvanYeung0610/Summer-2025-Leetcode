// Ivan Yeung
// 4. Median of Two Sorted Arrays

#include <vector>
#include <limits.h> // INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& small = nums2;
        vector<int>& large = nums1;
        if (nums1.size() < nums2.size()) {
            swap(small, large); // not using swap causes errors
        }

        int half = (nums1.size() + nums2.size() + 1) / 2;
        int left = 0;
        int right = small.size();

        while (left <= right) {
            int sMid = (left + right) / 2;
            int lMid = half - sMid;

            int sLeft = sMid > 0 ? small[sMid - 1] : INT_MIN;
            int sRight = sMid < small.size() ? small[sMid] : INT_MAX;
            int lLeft = lMid > 0 ? large[lMid - 1] : INT_MIN;
            int lRight = lMid < large.size() ? large[lMid] : INT_MAX;

            if (sLeft <= lRight && lLeft <= sRight) { // correct partitions
                if ((nums1.size() + nums2.size()) % 2 == 1) { 
                    return max(sLeft, lLeft);
                } else {
                    return (max(sLeft, lLeft) + min(sRight, lRight)) / 2.0;
                }
            } else if (sLeft > lRight) {
                right = sMid - 1;
            } else {
                left = sMid + 1;
            }
        }
        return -1;
    }
};
