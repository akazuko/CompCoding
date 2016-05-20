# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param A : root node of tree
    # @return an integer
    def trav(self, A, ans):
        if A is None:
            self.fin += int(ans)
            return 
        
        ans = ans + str(A.val)
        #print ans
        if (not A is None) and (A.left is None) and (A.right is None):
            self.fin += int(ans)
            return 
        if (not A.left is None):
            self.trav(A.left, ans)
        if (not A.right is None):
            self.trav(A.right, ans)
        
    def sumNumbers(self, A):
        self.fin = 0;
        ans=''
        self.trav(A, ans)
        return self.fin%(1003)
            