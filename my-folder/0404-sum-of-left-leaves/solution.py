# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode | None) -> int:
        def dfs(node):
            branch_sum = 0
            if not node:
                return 0
            if node.left and not node.left.right and not node.left.left:
                branch_sum += node.left.val
            else:
                branch_sum += dfs(node.left)
            branch_sum += dfs(node.right)
            return branch_sum
        return dfs(root)
