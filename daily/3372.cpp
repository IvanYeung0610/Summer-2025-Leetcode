// Ivan Yeung
// 3372. Maximize the Number of Target Nodes after Connecting Trees I

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
	// function that runs dfs and counts # of nodes reached from start in at most k edges
	// function that runs bfs and counts # of nodes reached from start in at most k edges
	int bfs(const vector<vector<int>>& adjList, int start, int k) {
		int count = 0;
		queue<pair<int, int>> q;
		vector<bool> visited(adjList.size(), false);
		pair<int, int> curr = make_pair(start, 0);
		visited[start] = true;
		q.push(curr);
		while (!q.empty() && curr.second <= k) {
			q.pop();
			count++;
			for (int i = 0; i < adjList[curr.first].size(); ++i) {
				if (!visited[adjList[curr.first][i]]) {
					q.push(make_pair(adjList[curr.first][i], curr.second + 1));
					visited[adjList[curr.first][i]] = true;
				}
			}
			curr = q.front();
		}

		return count;
	}

	vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
		vector<int> res;

		// Creating adjacency list from edges1 array
		int maxN = edges1[0][0];
		for (int i = 0; i < edges1.size(); ++i) { // find # of nodes in tree 1
			if (edges1[i][0] > maxN) maxN = edges1[i][0];
			if (edges1[i][1] > maxN) maxN = edges1[i][1];
		}
		vector<vector<int>> adj1(maxN + 1, vector<int>());
		for (int i = 0; i < edges1.size(); ++i) {
			adj1[edges1[i][0]].push_back(edges1[i][1]);
			adj1[edges1[i][1]].push_back(edges1[i][0]);
		}

		// Creating adjacency list from edges2 array
		maxN = edges2[0][0];
		for (int i = 0; i < edges2.size(); ++i) { // find # of nodes in tree 1
			if (edges2[i][0] > maxN) maxN = edges2[i][0];
			if (edges2[i][1] > maxN) maxN = edges2[i][1];
		}
		vector<vector<int>> adj2(maxN + 1, vector<int>());
		for (int i = 0; i < edges2.size(); ++i) {
			adj2[edges2[i][0]].push_back(edges2[i][1]);
			adj2[edges2[i][1]].push_back(edges2[i][0]);
		}

		// running bfs on each nodes for tree 1
		for (int i = 0; i < adj1.size(); ++i) {
			res.push_back(bfs(adj1, i, k));
		}

		// finding most connected node in tree 2
		int maxT = 0;
		for (int i = 0; i < adj2.size(); ++i) {
			int t = bfs(adj2, i, k - 1);
			if (t > maxT) maxT = t;
		}

		// adding that num of connections to each node
		for (int i = 0; i < res.size(); ++i) {
			res[i] += maxT;
		}
		
		return res;

	}
};

int main() {
	return 0;
}
