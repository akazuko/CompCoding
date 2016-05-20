#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	int k,t;
	cin>>k;
	priority_queue<int> p;
	
	for(int i=0; i<n; ++i){
		cin>>t;
		if(i<k){
			p.push(t);
		}
		else{
			if(p.top() > t){
				p.pop();
				p.push(t);
			}
		}
	}
	
	stack<int> s;
	while(!p.empty()){
		s.push(p.top());
		p.pop();
	}	

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}