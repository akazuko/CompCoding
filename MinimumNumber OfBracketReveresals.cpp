#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main(int argc, char const *argv[]) {
	string data;
	cin>>data;

	stack<char> s;
	int c = 0;
	for(int i=0; i<data.size(); ++i){
		if(data[i]=='{') s.push('{');
		else{
			if(!s.empty() && s.top()=='}') s.pop();
			else c++;
		}
	}
	c+= s.size();

	cout<<c/2;

	return 0;
}