class Solution:
    # @param A : string
    # @param B : list of strings
    # @return an integer
    def wordBreak(self, A, B):
        d = {}
        for i in B:
            d[i] = 1
        dictWordLen = set(map(len,d))
        ans = [ False ] * len(A)
        for start in xrange(len(A)-1, -1, -1):
            for wordLen in dictWordLen:
                if start + wordLen >  len(A) or A[start : start + wordLen] not in d:
                    continue
                if start + wordLen == len(A):
                    ans[start] = True
                else:
                    ans[start] = ans[start] or ans[start + wordLen]
        if ans[0]:
            return 1
        return 0
