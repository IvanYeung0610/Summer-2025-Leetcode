// Ivan Yeung
// 05/21/24
// 73. Set Matrix Zeroes

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool mul10 = false;

		// multiply top right by 10 to mitigate collision with -1 and -2
		// indicators if 0 < matrix[0][0] < -10 will be reverted at the end if
		// it is not set to to of the inicators
		if (matrix[0][0] < 0 && matrix[0][0] > -3) {
			matrix[0][0] = matrix[0][0] * 10;
			mul10 = true;
		}

		/* Initial loop to determine which rows/cols need to be zeroed*/
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == 0) {
		/*
			for the first row/col edge case:
			0 indicates both first row and col need to be zeroed
			-1 indicates only first row need to be zeroed
			-2 indicates only first column need to be zeroed
		*/
					if (i == 0) { // zero on the first row
						if (matrix[0][0] > 0 || matrix[0][0] < -2) matrix[0][0] = -1;
						if (matrix[0][0] == -2) matrix[0][0] = 0;
					} else if (j == 0) { // zero on the first column
						if (matrix[0][0] > 0 || matrix[0][0] < -2)
							matrix[0][0] = -2;
						if (matrix[0][0] == -1)
							matrix[0][0] = 0;
					} else {
						matrix[0][j] = 0; // 0 is the indicator variable
						matrix[i][0] = 0;
					}
				}
			}
		}

		// looking through the first row (NOT the top right)
		for (int i = 1; i < matrix[0].size(); ++i) {
			if (matrix[0][i] == 0) {
				for (int j = 0; j < matrix.size(); ++j) {
					matrix[j][i] = 0;
				}
			}
		}
		// looking through the first column (NOT the top right)
		for (int i = 1; i < matrix.size(); ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < matrix[0].size(); ++j) {
					matrix[i][j] = 0;
				}
			}
		}

		// checking top right
		if (matrix[0][0] == 0) {
			// zeroing first row and first column
			for (int i = 0; i < matrix[0].size(); ++i) {
				matrix[0][i] = 0;
			}
			for (int i = 0; i < matrix.size(); ++i) {
				matrix[i][0] = 0;
			}
		} else if (matrix[0][0] == -1) {
			// zeroing first row
			for (int i = 0; i < matrix[0].size(); ++i) {
				matrix[0][i] = 0;
			}
		} else if (matrix[0][0] == -2) {
			// zeroing first column
			for (int i = 0; i < matrix.size(); ++i) {
				matrix[i][0] = 0;
			}
		} else {
			// returning (0, 0) to its original value
			if (mul10)
				matrix[0][0] = matrix[0][0] / 10;
		}
	}
};
