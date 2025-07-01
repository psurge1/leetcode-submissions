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
    int sumNumbers(TreeNode* root) {
        // track current number
        // when leaf reached, add to sum
        int sumAmount = 0;
        dfs(root, 0, sumAmount);
        return sumAmount;
    }

    void dfs(TreeNode* root, int runningNumber, int& sumAmount) {
        if (!root)
            return;
        runningNumber = runningNumber * 10 + root->val;
        if (!(root->left || root->right)) {
            sumAmount += runningNumber;
        }
        if (root->left)
            dfs(root->left, runningNumber, sumAmount);
        if (root->right)
            dfs(root->right, runningNumber, sumAmount);
    }
};
