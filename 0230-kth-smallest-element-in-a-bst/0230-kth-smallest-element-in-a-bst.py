# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode | None, k: int) -> int:

        def DFS(node):
            nonlocal k
            if not node:
                return None
            
            left = DFS(node.left)
            if left is not None:
                return left

            k -= 1
            if k == 0:
                return node.val
            
            return DFS(node.right)
        
        return DFS(root)
        