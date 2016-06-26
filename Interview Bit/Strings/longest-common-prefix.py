class Solution:
    # @param A : list of strings
    # @return a strings
    def longestCommonPrefix(self, A):
        ans = A[0]
        for i in range(1,len(A)):
            pos = 0
            while pos<len(A[i]) and pos<len(ans) and A[i][pos] == ans[pos]:
                pos+=1
            ans = ans[:pos]
        return ans