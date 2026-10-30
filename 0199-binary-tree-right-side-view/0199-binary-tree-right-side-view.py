# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode | None) -> list[int]:
        output = []

        if not root:
            return output
        
        q = deque()
        q.append(root)

        while q:
            sz = len(q)

            while sz:
                node = q.popleft()

                if sz == 1:
                    output.append(node.val)
                
                if node.left:
                    q.append(node.left)
                
                if node.right:
                    q.append(node.right)
                
                sz -= 1

        return output            
        