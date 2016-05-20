class Solution:
    # @param arr : list of integers
    # @return a list of integers
    def prevSmaller(self, arr):
        s=list()
        s.append(-1)
        g=[0] * len(arr)
        for i in range(len(arr)):
            while(s[-1]>=arr[i]):
                s.pop()
            g[i]=s[-1]
            s.append(arr[i])
        return g