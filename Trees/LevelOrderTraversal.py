# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
from Queue import Queue
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        q=Queue()
        if root is not None:
            root.level=1
            q.put(root)
            
        self.ans = list()
        
        while(True):
            count = q.qsize()
            if count==0:
                break
            t=[]
            while(count > 0):
                node = q.get()
                t.append(node.val)
                if node.left is not None:
                    #node.left.level = root.level + 1
                    q.put(node.left)
                if node.right is not None:
                    #node.right.level = root.level + 1
                    q.put(node.right)
                count-=1
            self.ans.append(t)
        return self.ans
        
        
            