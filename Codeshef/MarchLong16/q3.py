def computeLPSArray(pat, M, lps):
    len = 0 # length of the previous longest prefix suffix
 
    lps[0] # lps[0] is always 0
    i = 1
 
    # the loop calculates lps[i] for i = 1 to M-1
    while i < M:
        if pat[i]==pat[len]:
            len+=1
            lps[i] = len
            i+=1
        else:
            if len!=0:
                # This is tricky. Consier the example AAACAAAA
                # and i = 7
                len = lps[len-1]
 
                # Also, note that we do not increment i here
            else:
                lps[i] = 0
                i+=1
for i in range(int(raw_input())):
    s=raw_input()
    n=len(s)
    lps = [0]*n
    computeLPSArray(s, n, lps)
    
     
print("--- %s seconds ---" % (time.time() - start_time))