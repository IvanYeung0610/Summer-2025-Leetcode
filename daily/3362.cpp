// Ivan Yeung
// 05/22/2025
// 3362. Zero Array Transformation III
/*
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

    Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.

A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
*/

class Solution {
public:
	static bool sortQueries (const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	}

	int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
		// sort the queries by their left endpoints
		sort(queries.begin(), queries.end(), sortQueries);

		// PQ (max heap) to store queries that include curr index
		priority_queue<int> maxHeap;
		// PQ (min heap) to store queries that have been used
		priority_queue<int, vector<int>, greater<int>> minHeap;
		// var to track index of query
		int qIndex = 0;

		// going through each index of nums
		for (int i = 0; i < nums.size(); ++i) {
			// adding ri of queries with li at the curr index
			while (qIndex < queries.size() && queries[qIndex][0] == i) {
				maxHeap.push(queries[qIndex][1]);
				qIndex++;
			}
			while (nums[i] > minHeap.size()) {
				/* Not sufficient queries to make everything
				a 0 in nums*/
				if (maxHeap.empty()) return -1; 
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
			// remove queries that will no longer be in range
			while (minHeap.top() == i) {
				minHeap.pop();
			}
		}

		// return size of maxHeap which were queries that weren't used
		return maxHeap.size();
	}
};
