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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        
        return dfs(root, targetSum);
    }

    bool dfs(TreeNode* root, int targetSum) {
        targetSum -= root->val;
        if (!(root->left || root->right)) {
            return targetSum == 0;
        }
        bool pathExists = false;
        if (root->left) {
            pathExists = pathExists || dfs(root->left, targetSum);
        }
        if (root->right) {
            pathExists = pathExists || dfs(root->right, targetSum);
        }
        return pathExists;
    }
};
