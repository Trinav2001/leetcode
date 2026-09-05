# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        output = []

        if not root:
            return output
        
        q = deque()

        q.append(root)

        while q:
            levelSize = len(q)
            level = []
            for i in range(levelSize):
                cur = q.popleft()
                level.append(cur.val)

                if cur.left:
                    q.append(cur.left)
                
                if cur.right:
                    q.append(cur.right)
            
            output.append(level)
        
        return output

        