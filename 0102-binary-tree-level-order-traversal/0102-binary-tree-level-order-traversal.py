# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        
        output = []

        if not root:
            return output

        q = deque()
        q.append(root)

        while q:
            sz = len(q)
            level = []

            while sz:
                node = q.popleft()
                level.append(node.val)

                if node.left:
                    q.append(node.left)
                
                if node.right:
                    q.append(node.right)
                
                sz -= 1
            
            output.append(level)
            
        return output