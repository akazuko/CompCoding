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
#define pii pair<int,int>
#define pp pair<int, pair<int,int>>

int bfs(pii start, pii end){
		queue<pii > q;
		q.push(start);
		
		int steps[9][9];
		
		bool vis[9][9];
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				vis[i][j] = false;
				steps[i][j] = INT_MAX;
			}
		}
		steps[start.first][start.second] = 0;

		int xadd[] = {2, 2, -2, -2, 1, -1, 1, -1};
		int yadd[] = {1,-1,  1, -1, 2,  2,-2, -2};
		
		vis[start.first][start.second] = true;
		while(!q.empty()){
			pii node = q.front();
			q.pop();

			if(node.first==end.first && node.second==end.second) return steps[node.first][node.second];
			
			for(int i=0;i<8; ++i){
				pii temp = make_pair(node.first + xadd[i], node.second + yadd[i]);
				
				if(temp.first<1 || temp.first>8 || temp.second<1 || temp.second>8) continue;
				
				if(!vis[temp.first][temp.second]){
					vis[temp.first][temp.second] = true;
					steps[temp.first][temp.second] = steps[node.first][node.second] + 1;
					q.push(temp);
				}

			}
		}			
		return -1;
}

int main(int argc, char const *argv[]) {
	int t;
	sd(t);
	while(t--){
		char s1[3];
		char s2[3];
		scanf("%s",s1);
		scanf("%s",s2);
		int startx = s1[0]-'a' + 1;
		int starty = s1[1]-'0';
		int endx = s2[0]-'a' + 1;
		int endy = s2[1]-'0';
		printf("%d\n",(int)bfs(make_pair(startx, starty), make_pair(endx, endy)));
	}
	return 0;
}