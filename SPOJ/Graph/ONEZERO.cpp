#include <iostream>
#include <queue>
#include <string>

using namespace std;

string bfs(int n){
	queue<string> q;
	q.push("1");
	while(!q.empty()){
		string temp  = q.front();
		q.pop();
		if(stoll(temp)%n==0)
			return temp;
		q.push(string(stoll(temp)*10+0));
		q.push(string(stoll(temp)*10+1));
	}
	return "-1";
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<bfs(n)<<endl;
	}
	return 0;
}