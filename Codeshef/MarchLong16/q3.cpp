#include <iostream>
#include <stdio.h>

using namespace std;

int ch(string s, int n){
	if(n%2==0){
			if(n==2){
				if(s[0]==s[1]){
					return 1;
				}
			}
			else{
				string temp1 = s.substr(0,n/2);
				string temp2 = s.substr(n/2,n/2);
				if(temp1==temp2){
					return 1;
				}
			}
		}
	return 0;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	string str;
	
	while(t--){
		// scanf("%s",&str);
		cin>>str;
		int n = str.length();
		int y=0;
		
		if(ch(str, n) == 1){
			printf("YES\n");
			y=1;
		}
		if(y!=1){
			for(int i=0 ; i<=n-1; ++i){
				string jas = str.substr(0,i) + str.substr(i+1,n-i-1);
				if(ch(jas, jas.length()) == 1){
					printf("YES\n");
					y=1;
					break;
				}
			}
		}
		if(y!=1)
			printf("NO\n");
	}
	return 0;
}