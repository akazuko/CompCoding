class Solution:
    # @param A : string
    # @return an integer
    def braces(self, A):
        s = list()
        k=0
        lastremoved=-1
        first=True
        for i in A:
            if i=='(':
                k+=1
                s.append(k)
            elif i==')':
                l = s.pop()
                if first:
                    lastremoved = l
                else:
                    if lastremoved+1 == l:
                        return 0
                    lastremoved = l;
        return 1
                    
                    
                    