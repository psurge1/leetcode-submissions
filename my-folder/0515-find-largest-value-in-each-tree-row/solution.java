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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> l = new ArrayList<>();
        dfs(root, 0, l);
        return l;
    }

    public void dfs(TreeNode root, int depth, List<Integer> list) {
        if (root == null)
            return;
        if (depth == list.size()) {
            list.add(root.val);
        }
        else {
            if (root.val > list.get(depth))
                list.set(depth, root.val);
        }

        dfs(root.left, depth + 1, list);
        dfs(root.right, depth + 1, list);
    }
}
