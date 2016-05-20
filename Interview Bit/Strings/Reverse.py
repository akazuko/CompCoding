class Solution:
    # @param A : string
    # @return string
    def reverseWords(self, A):
        l=A.split(" ")
        l=l[::-1]
        ans=""
        print l
        for i in l:
 			if i!='':
 			ans=ans+i.replace(' ','')+" "
        return ans[:-1]
s=Solution()
s.reverseWords("fwbpudnbrozzifml osdt  ulc jsx kxorifrhubk ouhsuhf  sswz qfho dqmy  sn myq igjgip iwfcqq")