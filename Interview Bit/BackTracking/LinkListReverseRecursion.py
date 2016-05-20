# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param A : head node of linked list
    # @return the head node in the linked list
    def reverse(self, cur, prev):
        if cur is not None:
            temp=cur.next
            cur.next = prev
            prev = cur
            cur = temp
            return self.reverse(cur, prev)
        return prev
        
    def reverseList(self, A):
        prev=None
        cur = A
        return self.reverse(cur, prev)