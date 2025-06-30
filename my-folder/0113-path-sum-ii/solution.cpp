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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> sums;
        vector<int> currpath;
        dfs(root, targetSum, currpath, sums);

        return sums;
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& sums) {
        if (!root)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (!(root->left || root->right)) {
            if (targetSum == 0) {
                sums.push_back(path);
            }
        }
        dfs(root->left, targetSum, path, sums);
        dfs(root->right, targetSum, path, sums);

        path.pop_back();
    }
};
