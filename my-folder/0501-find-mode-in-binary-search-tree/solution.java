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
    Integer maxCount;
    List<Integer> maxNums;
    Integer currentCount;
    Integer currentNum;
    public int[] findMode(TreeNode root) {
        maxCount = 0;
        currentCount = 0;
        currentNum = 0;
        maxNums = new ArrayList<>();

        dfs(root);
        int[] result = new int[maxNums.size()];
        for (int i = 0; i < maxNums.size(); ++i) {
            result[i] = maxNums.get(i);
        }
        return result;
    }

    public void dfs(TreeNode root) {
        if (root ==  null)
            return;
        
        dfs(root.left);

        if (root.val == currentNum) {
            ++currentCount;
        }
        else {
            currentCount = 1;
            currentNum = root.val;
        }

        if (currentCount == maxCount) {
            maxNums.add(currentNum);
        }
        else if (currentCount > maxCount) {
            maxNums.clear();
            maxNums.add(currentNum);
            maxCount = currentCount;
        }
        
        dfs(root.right);
    }
}
