// Ivan Yeung
// 4. Median of Two Sorted Arrays

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& small = nums2;
        vector<int>& large = nums1;
        if (nums1.size() < nums2.size()) {
            small = nums1;
            large = nums2;
        }

        int half = (nums1.size() + nums2.size()) / 2;
        int mid = (small.size()) / 2;

        while (mid < small.size()) {
            int largeMid = half - (mid + 1);
            if ()
        }
    }
};
