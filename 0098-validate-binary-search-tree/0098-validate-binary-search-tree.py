# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode | None) -> bool:

        def DFS(node, maxValue, minValue):
            if not node:
                return True
            
            if not (minValue < node.val < maxValue):
                return False
            
            return DFS(node.left, node.val, minValue) and DFS(node.right, maxValue, node.val)


        return DFS(root, float("infinity"), float("-infinity"))
        