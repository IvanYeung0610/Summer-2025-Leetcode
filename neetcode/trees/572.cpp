// Ivan Yeung
// 572. Subtree of Another Tree

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
    bool compare(TreeNode* one, TreeNode* two) {
        if (!one && !two) return true;
        if (!one || !two) return false;

        bool comp = (one->val == two->val);
        bool leftComp = compare(one->left, two->left);
        bool rightComp = compare(one->right, two->right);

        return leftComp && rightComp && comp;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        bool curr = compare(root, subRoot);

        return left || right || curr;
    }
};
