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
    void flatten(TreeNode* root) {
        // preorder: node, left, right
        dfs(root);
    }

    TreeNode* dfs(TreeNode* node) {
        /*
        Consider a node
        Recurse until we reach a node with children but no grandchildren
        Move right node to child of left node, then move left node to right side
        */

        if (!node)
            return nullptr;
        if (!(node->left || node->right))
            return node;
        
        TreeNode* leftTail = dfs(node->left);
        if (leftTail) {
            TreeNode* rightSubTree = node->right;
            node->right = node->left;
            node->left = nullptr;
            leftTail->right = rightSubTree;
        }

        return dfs(node->right);
    }
};
