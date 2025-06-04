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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> l = new ArrayList<>();

        if (root == null)
            return l;
        List<Integer> rootLeafPath = new ArrayList<>();
        dfs(root, rootLeafPath, l);
        return l;
    }

    public void dfs(TreeNode root, List<Integer> rootLeafPath, List<String> result) {
        if (root == null) {
            return;
        }
        rootLeafPath.add(root.val);
        if (root.left == null && root.right == null) {
            // leaf node
            String res = "" + rootLeafPath.get(0);
            for (int i = 1; i < rootLeafPath.size(); ++i) {
                res += "->" + rootLeafPath.get(i);
            }
            result.add(res);
        }
        else {
            dfs(root.left, rootLeafPath, result);
            dfs(root.right, rootLeafPath, result);
        }
        rootLeafPath.remove(rootLeafPath.size() - 1);
    }
}
