# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        output = []

        if not root:
            return output
        
        q = deque()
        q.append(root)

        while q:
            levelSize = len(q)
            
            for i in range(levelSize):
                cur = q.popleft()
                if i == levelSize - 1:
                    output.append(cur.val)
                
                if cur.left:
                    q.append(cur.left)
                
                if cur.right:
                    q.append(cur.right)
                
        return output
                    

        