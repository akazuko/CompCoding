/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */
char* longestPalindrome(char* A) {
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = strlen(A);
 
    int low, high;
 
    // One by one consider every character as center point of 
    // even and length palindromes
    int i;
    for (i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && A[low] == A[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && A[low] == A[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
    char *res = (char *)malloc(sizeof(char)*(maxLength));
    int j=0;
    for(i=start; i<start+maxLength; ++i,++j)
        res[j]=A[i];
    return res;

}
