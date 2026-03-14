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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        
        deque<TreeNode*> swapQueue;
        swapQueue.push_back(root);
        while (!swapQueue.empty()) {
            TreeNode* node = swapQueue.back();
            swapQueue.pop_back();

            if (node) {
                swapQueue.push_back(node->left);
                swapQueue.push_back(node->right);
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }


        return root;
    }
};
