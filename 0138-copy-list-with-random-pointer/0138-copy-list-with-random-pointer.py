"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        mp = {}
        mp[None] = None
        
        cur = head

        while cur:
            new_node = Node(cur.val)
            mp[cur] = new_node
            cur = cur.next

        cur = head

        while cur:
            node = mp[cur]
            node.next = mp[cur.next]
            node.random = mp[cur.random]
            cur = cur.next
        
        return mp[head]

        