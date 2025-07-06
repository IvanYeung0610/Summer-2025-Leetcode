// Ivan Yeung
// 875. Koko Eating Bananas

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) {
            int remainder = piles[0] % h > 0 ? 1 : 0;
            return (piles[0] / h) + remainder;
        }

        double sum = 0;
        int maxI = piles[0];
        for (int i : piles) {
            sum += i ;
            maxI = max(maxI, i);
        }
        /*
         * Bounds for binary search is the sum / h and
         * the largest element in the bunch
         */
        int left = ceil((double)sum / (double)h);
        int right = maxI;
        int res = maxI;

        while (left <= right) {
            long long time = 0;
            int mid = (left + right) / 2;
            // determines # of hours if k = mid
            for (int i : piles) {
                if (i <= mid) {
                    time++;
                } else {
                    time += ceil((double)i / (double)mid);
                }
            }

            if (time <= h) {
                res = mid;
                right = mid - 1;
            } else { // time > h
                left = mid + 1;
            }
        }

        return res;
    }
};
