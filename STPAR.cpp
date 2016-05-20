#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const *argv[]) {
	int n,t;
	while(1){
		cin>>n;
		if(n==0) break;

		stack<int> s1;
		stack<int> s2;

		int lookup = 1;
		for(int i=0;i<n;++i){
			cin>>t;
			if(t==lookup){
				s1.push(t);
				lookup++;
			}
			else{
				s2.push(t);
			}
		}
		int ch = 0;
		while(!s2.empty()){
			if(s2.top() > s1.top()){
				s1.push(s2.top());
				s2.pop();
			}
			else{
				ch = 1;
				break;
			}
		}
		if(ch)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}