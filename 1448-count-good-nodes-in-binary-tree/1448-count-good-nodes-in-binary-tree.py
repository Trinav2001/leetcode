# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        count = 0

        def DFS(node, maxElement):
            nonlocal count
            if not node:
                return
            
            if node.val >= maxElement:
                count += 1
            
            DFS(node.left, max(maxElement, node.val))
            DFS(node.right, max(maxElement, node.val))
        
        DFS(root, root.val)

        return count