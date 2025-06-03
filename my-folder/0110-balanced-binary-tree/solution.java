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
    class DFSResult {
        public int depth;
        public boolean isBalanced;
        public DFSResult (int depth, boolean isBalanced) {this.depth = depth; this.isBalanced = isBalanced;}
    }

    public boolean isBalanced(TreeNode root) {
        return dfs(root, 1).isBalanced;
    }

    public DFSResult dfs(TreeNode root, int depth) {
        if (root == null) {
            return new DFSResult(depth, true);
        }
        DFSResult leftResult = dfs(root.left, depth + 1);
        DFSResult rightResult = dfs(root.right, depth + 1);
        return new DFSResult(Math.max(leftResult.depth, rightResult.depth), leftResult.isBalanced && rightResult.isBalanced && Math.abs(leftResult.depth - rightResult.depth) <= 1);
    }
}
