#include <iostream>
#include <stdio.h>

using namespace std;

int check(string s, int n){
	if(n==2){
		if(s[0]==s[1])
			return 1;
		return 0;
	}
	else{
		if(s.substr(0,n/2)==s.substr(n/2,n/2))
			return 1;
		return 0;
	}
}

int main(int argc, char const *argv[])
{

	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n = s.length();
		if(n%2==0){
			if(check(s,n)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			int ans = 0;
			for(int i=0;i<n;++i){
				string temp = s.substr(0,i) + s.substr(i+1,n-i-1);
				if(check(temp,n-1)==1){
					ans = 1;
					break;
				}
			}
			if(ans==1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}