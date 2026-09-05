# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def DFS(root: TreeNode, maxValue: int) -> int:
            if not root:
                return 0
            
            good = 1 if root.val >= maxValue else 0
            maxValue = max(root.val, maxValue)

            return good + DFS(root.left, maxValue) + DFS(root.right, maxValue)
        
        return DFS(root, root.val)
        

        