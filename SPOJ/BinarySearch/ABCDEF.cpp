#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
	int n,temp;
	long long ans = 0;
	vector<int> l,s1,s2;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		l.push_back(temp);
	}
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				s1.push_back(l[i]*l[j] + l[k]);
	sort(s1.begin(),s1.end());

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				if(l[k]!=0)
					s2.push_back((l[i]+l[j])*l[k]);
	sort(s2.begin(),s2.end());
	
	for(int i=0; i<s1.size(); ++i){
		int lo = lower_bound(s2.begin(), s2.end(), s1[i])-s2.begin();
		int hi = upper_bound(s2.begin(), s2.end(), s1[i])-s2.begin();
		ans += (hi-lo);
	}
	printf("%lld\n",ans);
	return 0;
}