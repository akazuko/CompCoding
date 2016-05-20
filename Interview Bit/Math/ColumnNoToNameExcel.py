class Solution:
    # @param A : integer
    # @return a strings
    def convertToTitle(self, A):
        ans=''
        div = A
        m=0
        while(div>0):
            m = (div-1)%26
            ans = chr(65 + m) + ans
            div = int((div-m)/26)
        return ans