// Ivan Yeung
// 110. Balanced Binary Tree

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        // returns 2 element vector: (tree balanced?, depth)
        if (!root) return {0,0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        // checking if the depth of the 2 subtrees differ by more than 1
        if (left[1] == right[1] || left[1] == right[1] - 1 
            || left[1] - 1 == right[1]) {
            return {max(left[0], right[0]), max(left[1], right[1]) + 1};
        } else {
            return {1, max(left[1], right[1]) + 1};
        }
    }

    bool isBalanced(TreeNode* root) {
        return !dfs(root)[0];
    }
};
