class Solution:
    # @param A : list of strings
    # @param B : integer
    # @return a list of strings
    def geP(self, A, B):
        ans = []
        r =""
        n = len(A)
        i = 0
        while i < n:
            t = ""
            if r=="":
                t = A[i]
            else:
                t = r + " " + A[i]
            if(len(t) > B):
                ans.append(r)
                r = ""
            else:
                r = t
                i+=1
                if(i==n and len(r) <= B):
                    ans.append(r)
        return ans
    
    def genans(self, A, B):
        l = A.split()
        tl = 0
        n = len(l)
        if n==1:
            while len(A) < B:
                A = A + " "
            return A
            
        for i in l:
            tl+= len(i)
        left = B - tl
        k = left/(n-1)
        res = ""
        tt = " " * k
        nolarge = left%(n-1)
        llc =0
        for i in range(n-1):
            res+= l[i]
            if llc < nolarge:
                res += tt + " "
                llc+=1
            else:
                res += tt
        res += l[n-1]
        return res
            
    def fullJustify(self, A, B):
        ans = []
        tvv = self.geP(A, B)
        xx = len(tvv)
        for i in range(xx):
            if i == xx-1:
                left = B - len(tvv[i])
                rr = " " * left
                ans.append(tvv[i] + rr)
                continue
            ans.append(self.genans(tvv[i], B))
            # ans.append(i)
        return ans