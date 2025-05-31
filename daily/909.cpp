// Ivan Yeung
// 909. Snakes and Ladders

#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	int getRow(int num, int n) {
		return (n - 1) - ((num - 1) / n);
	}

	int getCol(int num, int n, int row) {
		bool parity;

		if (n % 2 == 0) {
			if (row % 2 == 0) {
				parity = false;
			} else {
				parity = true;
			}
		} else {
			if (row % 2 == 0) {
				parity = true;
			} else {
				parity = false;
			}
		}

		if (parity) { // row is normal
			return ((num - 1) % n);
		} else { // row is reversed
			return n - (((num - 1) % n) + 1);
		}
	}

	int snakesAndLadders(vector<vector<int>>& board) {
		int n = board.size();
		pair<int, int> child, curr;
		queue<pair<int, int>> q;
		unordered_set<int> visited;

		int row;
		int col;
		int new_square;

		curr.first = 1; // square
		curr.second = 0; // # of rolls to get to the square
		child.first = 1;
		child.second = 0;
		q.push(child);

		while (curr.first != n * n && !q.empty()) {
			q.pop();
			for (int i = 1; i < 7; ++i) {
				new_square = curr.first + i;
				if (new_square > n * n) break;
				row = getRow(new_square, n);
				col = getCol(new_square, n, row);

				if (board[row][col] != -1) new_square = board[row][col];

				if (visited.find(new_square) == visited.end()) {
					visited.insert(new_square);
					child.first = new_square;
					child.second = curr.second + 1;
					q.push(child);
				}
			}
			curr = q.front();
		}

		if (curr.first != n * n) return -1;
		return curr.second;
	}
};


int main() {
	vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
	Solution sol;
	int res = sol.snakesAndLadders(board);

	cout << " res: " << res << endl;
}

