// Ivan Yeung
// 74. Search a 2D Matrix

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // # of rows
        int n = matrix[0].size(); // # of cols
        int left = 0;
        int right = (m * n) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            // converting to row and col
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] > target) {
                right = mid - 1;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
