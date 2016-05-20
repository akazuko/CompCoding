#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",&x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);

using namespace std;

bool isPrime[10000], visited[10000];
int level[10000];



bool checkPrime(int n){
	for(int i=2; i<=sqrt(n); ++i){
		if(n%i==0)
			return false;
	}
	return true;
}


void initPrime(){
	for(int i=1000; i<10000; ++i){
		isPrime[i] = checkPrime(i);
	}
	
}

void initVisitLevel(){
	for(int i=0; i<10000; ++i){
		visited[i]=false;
		level[i]=0;
	}
}

int bfs(int start, int end){
	initVisitLevel();
	queue<int> q;
	visited[start] = true;
	level[start] = 0;
	q.push(start);

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		for(int pos = 0 ; pos<4; ++pos){
			int ones, two, hund, thou;

			ones = temp%10;
			two	 = (temp%100)/10;
			hund = (temp%1000)/100;
			thou = (temp%10000)/1000; 

			for(int val = 0; val<=9 ; ++val){
				int genNum = 0;
				if(pos==0){
					genNum = thou*1000+hund*100+two*10+((ones+val)%10);
				}
				else if(pos==1){
					genNum = thou*1000+hund*100+((two+val)%10)*10+ones;
				}
				else if(pos==2){
					genNum = thou*1000+((hund+val)%10)*100+two*10+ones;
				}
				else if(pos==3){
					int jki  = (thou+val)%10;
					if(jki!=0)
						genNum = ((thou+val)%10)*1000+hund*100+two*10+ones;
				}

				if(!visited[genNum] && isPrime[genNum] && genNum!=temp){
					visited[genNum]=true;
					level[genNum]=level[temp] + 1;
					q.push(genNum);
					if(genNum==end)
						return level[end];
				}
			
			}

		}

	}

	return level[end];
}

int main(int argc, char const *argv[]) {
	initPrime();
	int T;
	int n1, n2;
	sd(T);
	
	while(T--){
		sd(n1);
		sd(n2);
		if(n1==n2)
			printf("0\n");
		else{
			int lev = bfs(n1,n2);
			if(lev!=0)
				printf("%d\n", lev);
			else
				printf("Impossible\n");
		}
		
	}
	return 0;
}