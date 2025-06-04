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
    HashMap<Integer, Integer> numCount = new HashMap<>();
    public int[] findMode(TreeNode root) {
        dfs(root);
        List<Integer> sols = new ArrayList<>();
        int runningMaxCount = 0;
        for (Map.Entry<Integer, Integer> entry : numCount.entrySet()) {
            if (entry.getValue() > runningMaxCount) {
                sols.clear();
                sols.add(entry.getKey());
                runningMaxCount = entry.getValue();
            }
            else if (entry.getValue() == runningMaxCount) {
                sols.add(entry.getKey());
            }
        }
        int[] solution = new int[sols.size()];
        for (int i = 0; i < sols.size(); ++i) {
            solution[i] = sols.get(i);
        }
        return solution;
    }

    public void dfs(TreeNode root) {
        if (root ==  null)
            return;
        numCount.put(root.val, numCount.getOrDefault(root.val, 0) + 1);
        dfs(root.left);
        dfs(root.right);
    }
}
