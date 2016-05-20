#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <queue>

using namespace std;

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

int main(int argc, char const *argv[]){
	int t;
	sd(t);
	while(t--){
		vector<char> s1;
		vector<char> s2;
		string inp;
		cin>>inp;
		for(int i=0; i<inp.size(); ++i){
			if(inp[i]=='(') continue;
			if(inp[i]=='+' || inp[i]=='-' || inp[i]=='*' || inp[i]=='/' || inp[i]=='^') s2.push_back(inp[i]);
			else if(inp[i]==')'){
				char temp = s2.back();
				s2.pop_back();
				s1.push_back(temp);
			}
			else{
				s1.push_back(inp[i]);
			}
		}
		int size = s1.size();
		for(int i=0;i<size; ++i){
			cout<<s1[i];
		}
		cout<<endl;
	}
	return 0;
}