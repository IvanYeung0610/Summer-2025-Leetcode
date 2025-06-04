// Ivan Yeung
// 36. Valid Sudoku

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> seen(9, false);

        // check every row
        for (const vector<char>& row : board) {
            for (char c : row) {
                if (c != '.') {
                    int num = c - '0'; // converts char to number
                    if (seen[num - 1]) return false;
                    seen[num - 1] = true;
                }
            }
            fill(seen.begin(), seen.end(), false); // resets vector
        }

        // check every column
        for (int i = 0; i < board[0].size(); ++i) {
            for (const vector<char>& row : board) {
                if (row[i] != '.') {
                    int num = row[i] - '0'; // converts char to number
                    if (seen[num - 1]) return false;
                    seen[num - 1] = true;
                }
            }
            fill(seen.begin(), seen.end(), false); // resets vector
        }

        // check every 3x3 box
        for (int i = 0; i < 7; i += 3) {
            for (int j = 0; j < 7; j += 3) {
                // from this double for loop we reach every top left corner
                // of each box: [0][0] [0][3] [0][6] [3][0].......

                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i + k][j + l] != '.') {
                            int num = board[i + k][j + l] - '0';
                            if (seen[num - 1]) return false;
                            seen[num - 1] = true;
                        }
                    }
                }

                fill(seen.begin(), seen.end(), false); // resets vector
            }
        }

        return true;
    }
};
