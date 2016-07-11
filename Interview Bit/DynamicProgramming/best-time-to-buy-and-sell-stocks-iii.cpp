int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = A.size();
    int k = 2;
	if (len < 2 || k <= 0)
		return 0;
    
    vector<int> local(k+1, 0);
    vector<int> global(k+1, 0);
		
	for (int i = 0; i <len - 1; i++) {
		int diff = A[i + 1] - A[i];
		for (int j = k; j >= 1; j--) {
			local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
			global[j] = max(local[j], global[j]);
		}
	}
 
	return global[k];
}
