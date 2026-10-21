# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        q = None
        p = head

        while p:
            r = q
            q = p
            p = p.next
            q.next = r
        
        return q
        

        