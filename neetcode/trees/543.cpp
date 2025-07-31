// Ivan Yeung
// 543. Diameter of Binary Tree

#include <algorithm>
#include <utility>

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
    pair<int, int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        int depth = max(left.first, right.first) + 1;
        int maxPath = max(left.second, right.second);
        maxPath = max(maxPath, left.first + right.first);
        return {depth, maxPath};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};
