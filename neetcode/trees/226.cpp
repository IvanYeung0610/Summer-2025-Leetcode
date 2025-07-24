// Ivan Yeung
// 226. Invert Binary Tree

#include <queue>

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
    TreeNode* invertTree(TreeNode* root) {
        /* Recursive Solution
        if (!root) return root;

        TreeNode* nLeft = invertTree(root->right);
        TreeNode* nRight = invertTree(root->left);

        root->left = nLeft;
        root->right = nRight;
        */
        queue<TreeNode*> q;
        if (root) q.push(root);
        TreeNode* curr = q.front();
        while (curr && !q.empty()) {
            q.pop();
            swap(curr->left, curr->right);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            curr = q.front();
        }
        
        return root;
    }
};
