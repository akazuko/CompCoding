from collections import Counter
class Solution:
    # @param A : string
    # @return an integer
    def findRank(self, A):
        perm=A
        rank = 1
        suffixperms = 1
        ctr = Counter()
        for i in range(len(perm)):
            x = perm[((len(perm) - 1) - i)]
            ctr[x] += 1
            for y in ctr:
                if (y < x):
                    rank += ((suffixperms * ctr[y]) // ctr[x])
            suffixperms = ((suffixperms * (i + 1)) // ctr[x])
        return rank%1000003