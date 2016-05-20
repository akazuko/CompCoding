class Solution:
    # @param A : string
    # @return a strings
    def simplifyPath(self, A):
        l=list()
        data1 = A.split('/')
        data =list()
        for i in data1:
            if i != '':
                data.append(i)
        # print data
        slashenc = 0
        for i in data:
            if i == '..':
                if len(l)>0:
                    l.pop()
            else:
                if i != '.':
                    l.append(i)
            # print l
        ans = '/'
        for k in l:
            ans = ans + k + '/'
        if ans == '/':
            return ans
        return ans[:-1]
                
# s = Solution()
# print s.simplifyPath("/a/./b/../../c/")