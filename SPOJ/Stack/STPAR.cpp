#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
	int n,t;
	while(1){
		cin>>n;
		if(n==0) break;

		vector<int> data;
		stack<int> s1;
		stack<int> s2;

		int lookup = 1;
		for(int i=0;i<n;++i){
			cin>>t;
			data.push_back(t);
		}

		for(int i=0; i<n; ++i){
			if(data[i]==lookup) {
				s1.push(data[i]);
				lookup++;
			}
			else{
				while(!s2.empty() && s2.top()==lookup){
					s1.push(s2.top());
					s2.pop();
					lookup++;
				}
				s2.push(data[i]);
			}
		}
		
		while(!s2.empty() && s2.top()==lookup){
			s1.push(s2.top());
			s2.pop();
			lookup++;
		}
		
		if(s2.empty()) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}