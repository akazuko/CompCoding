class Solution:
    # @param A : string
    # @param B : list of strings
    # @return a list of strings
    def wordBreak(self, A, B):
        d = dict()
        for i in B:
            d[i] = 1
        ans = [[] for x in range(len(A)) ]
        dictWordLen = set(map(len,d))
        for start in xrange(len(A)-1, -1, -1):
            for wordLen in dictWordLen:
                if start + wordLen > len(A) or A[start : start + wordLen] not in d:
                    continue
                if start + wordLen == len(A):
                    ans[start].append(A[start : start + wordLen])
                else:
                    for sentence in ans[start + wordLen]:
                        ans[start].append(A[start : start + wordLen] + " " + sentence)
        return ans[0]