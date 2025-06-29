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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long minRange, long maxRange) {
        if (!root)
            return true;
        
        bool nodeSatisfied = minRange < root->val && root->val < maxRange;
        if (!nodeSatisfied)
            return false;
        
        bool leftSatisfied = dfs(root->left, minRange, root->val);
        bool rightSatisfied = dfs(root->right, root->val, maxRange);
        return leftSatisfied && rightSatisfied;
    }
};
