int Solution::maximumGap(const vector<int> &A) {
	int n = A.size();
    if(n==0 || n==1) return 0;	
	int maxx = A[0];
	int minn = A[0];    

	for(int a : A){
		maxx = max(maxx, a);
		minn = min(minn, a);
	}

    int interval = (maxx-minn-1)/(n-1) + 1;
	
	vector<pair<int,int> > buckets(n-1, make_pair(INT_MAX,INT_MIN));
	for(int i = 0; i<n; ++i){
	    if(A[i]!=maxx && A[i]!=minn){
	        int index = (A[i] - minn)/interval;
			buckets[index].first = min(buckets[index].first, A[i]);
			buckets[index].second = max(buckets[index].second, A[i]);    
	    }
	}
	
	int ans = INT_MIN;
	int prev= minn;
	for(int i = 0; i<n-1; ++i){
	    if(buckets[i].first==INT_MAX && buckets[i].second==INT_MIN) continue;
	    ans = max(ans, buckets[i].first - prev);
        prev = buckets[i].second;
	}
	ans = max(ans, maxx-prev);
	return ans;
}
