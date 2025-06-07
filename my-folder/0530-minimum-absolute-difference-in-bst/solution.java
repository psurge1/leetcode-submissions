/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // in order traversal, comparing the differences of nodes
    TreeNode prevNode = null;
    Integer minDiff = Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        if (root == null)
            return 0;
        dfs(root);
        return minDiff;
    }

    public void dfs(TreeNode root) {
        if (root == null)
            return;
        
        dfs(root.left);
        if (prevNode != null) {
            minDiff = Math.min(minDiff, root.val - prevNode.val);
        }
        prevNode = root;
        dfs(root.right);
    }
}
