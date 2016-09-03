#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> a(n);
	    for(int i = 0; i<n; ++i) cin>>a[i];
	    int i = 0;
	    int ele;
	    int next;
	    stack<int> s;
	    map<int,int> m;
	    s.push(a[0]);
	    for(i = 1; i<n; ++i){
	        next = a[i];
	        if(!s.empty()){
	            ele = s.top();
	            s.pop();
	            while(ele < next){
	                m[ele] = next;
	                if(s.empty()) break;
	                ele = s.top();
	                s.pop();
	            }
	            if(ele > next) s.push(ele);
	        }
	        s.push(next);
	   }
	   while(!s.empty()){
	       ele = s.top();
	       m[ele] = -1;
	       s.pop();
	   }
	   for(i = 0; i<n; ++i) cout<<m[a[i]]<<" ";
	   cout<<endl;
	    
	}
	return 0;
}
