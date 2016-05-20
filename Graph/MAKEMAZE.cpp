#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string.h>

#define sd(x)	scanf("%d",&x); 
#define sll(x)	scanf("%lld",&x);
#define ss(x)	scanf("%s",&x);
#define sc(x)	scanf("%c",&x);
#define ll long long
#define pll(x)	printf("%lld",x);
#define pd(x)	printf("%d",x);
#define ps(x)	printf("%s",x);
#define pc(x)	printf("%c",x);


using namespace std;

bool bfs(string mat[], int m, int n, pair<int,int> start, pair<int,int> end){
	queue< pair<int,int> > q;
	bool visit[n][m];
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			visit[i][j] = false;
	q.push(start);
	visit[start.first][start.second] = true;
	while(!q.empty()){
		pair<int, int> temp = q.front();
		// printf(" first : %d second : %d\n", temp.first, temp.second);
		q.pop();

		int i,j;
		i = temp.first-1;
		j = temp.second;
		if(i>=0 && j>=0 && i<n && j<m && !visit[i][j] && mat[i][j]=='.'){
			visit[i][j] = true;
			pair<int,int> repo;
			repo.first = i;
			repo.second = j;
			q.push(repo);
			if(repo==end)
				return true;
		}

		i = temp.first+1;
		j = temp.second;
		if(i>=0 && j>=0 && i<n && j<m && !visit[i][j] && mat[i][j]=='.'){
			visit[i][j] = true;
			pair<int,int> repo;
			repo.first = i;
			repo.second = j;
			q.push(repo);
			if(repo==end)
				return true;
		}

		i = temp.first;
		j = temp.second-1;
		if(i>=0 && j>=0 && i<n && j<m && !visit[i][j]  && mat[i][j]=='.'){
			visit[i][j] = true;
			pair<int,int> repo;
			repo.first = i;
			repo.second = j;
			q.push(repo);
			if(repo==end)
				return true;
		}

		i = temp.first;
		j = temp.second+1;
		if(i>=0 && j>=0 && i<n && j<m && !visit[i][j]  && mat[i][j]=='.'){
			visit[i][j] = true;
			pair<int,int> repo;
			repo.first = i;
			repo.second = j;
			q.push(repo);
			if(repo==end)
				return true;
		}

		
	}
	return false;
}


int main(int argc, char const *argv[]) {
	int t,n,m;
	sd(t);
	while(t--){
		sd(n);
		sd(m);

		string mat[n];
		for(int i=0; i<n; ++i)
			cin>>mat[i];

		bool extra = false;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(mat[i][j]!='.' && mat[i][j]!='#'){
					extra = true; break;}
		if(extra){
			printf("invalid\n");
			continue;
		}

		pair<int,int> start, end;
		int count=0;

		int pos=0;
		for(int i=0; i<n; ++i){
			if(mat[i][0]=='.'){
				if(pos==0){
					start.first = i;
					start.second = 0;
					pos++;
				}
				else if(pos==1){
					end.first = i;
					end.second = 0;
					pos++;
				}
				count++;
			}
		}

		if(m!=1){
			for(int i=0; i<n; ++i){
				if(mat[i][m-1]=='.'){
					if(pos==0){
						start.first = i;
						start.second = m-1;
						pos++;
					}
					else if(pos==1){
						end.first = i;
						end.second = m-1;
						pos++;
					}
					count++;
				}
			}
		}

		for(int i=1; i<m-1; ++i){
			if(mat[0][i]=='.'){
				if(pos==0){
					start.first = 0;
					start.second = i;
					pos++;
				}
				else if(pos==1){
					end.first = 0;
					end.second = i;
					pos++;
				}
				
				count++;
			}
		}
		if(n!=1){
			for(int i=1; i<m-1; ++i){
				if(mat[n-1][i]=='.'){
					if(pos==0){
						start.first = n-1;
						start.second = i;
						pos++;
					}
					else if(pos==1){
						end.first = n-1;
						end.second = i;
						pos++;
					}
					count++;
				}
			}
		}

		// printf("start : %d %d\n", start.first, start.second);
		// printf("end : %d %d\n", end.first, end.second);
		if(count>2){
			printf("%s\n", "invalid");
		}
		else{
			bool res = bfs(mat, m, n, start, end);
			if(res) 
				printf("%s\n","valid" );
			else
				printf("invalid\n");
		}
	}		
	return 0;
}