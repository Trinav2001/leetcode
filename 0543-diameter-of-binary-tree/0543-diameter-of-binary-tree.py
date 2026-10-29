# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0

        def maxHeight(root):
            nonlocal res

            if not root:
                return 0
            
            leftHeight = maxHeight(root.left)
            rightHeight = maxHeight(root.right)
            res = max(res, leftHeight + rightHeight)

            return 1 + max(leftHeight, rightHeight)
        
        maxHeight(root)
        return res

        