#include <bits/stdc++.h>

using namespace std;
using namespace std;
 
class myComp {
public:
 bool operator()(const pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
 }
};
 
int getIdx(int x, int y, int ncol) {
 return x*ncol+y;
}
 
int getX(int idx, int ncol) {
 return idx/ncol;
}
 
int getY(int idx, int ncol) {
 return idx%ncol;
}
 
int getTrap(vector<vector<int> > &board) {
 int nrow = board.size();
 if (nrow == 0) return 0;
 int ncol = board[0].size();
 
 vector<vector<bool> > visited(nrow, vector<bool>(ncol, false));
 priority_queue<pair<int, int>, vector<pair<int, int> >, myComp> minHeap;
 for (int j=0; j<ncol; ++j) {
  minHeap.push(make_pair(j, board[0][j]));
  visited[0][j] = true;
  minHeap.push(make_pair((nrow-1)*ncol+j, board[nrow-1][j]));
  visited[nrow-1][j] = true;
 }
 
 for (int i=0; i<nrow; ++i) {
  minHeap.push(make_pair(getIdx(i, 0, ncol), board[i][0]));
  visited[i][0] = true;
  minHeap.push(make_pair(getIdx(i, ncol-1, ncol), board[i][ncol-1]));
  visited[i][ncol-1] = true;
 }
  
 int res = 0;
 while (!minHeap.empty()) {
  pair<int, int> cur = minHeap.top();
  minHeap.pop();
  int curHeight = cur.second;
  int curX = getX(cur.first, ncol), curY = getY(cur.first, ncol);
  // four directions
  if (curX-1>=0 && visited[curX-1][curY] == false) {
   visited[curX-1][curY] = true;
   res += max(0, (curHeight - board[curX-1][curY]));
   minHeap.push(make_pair(getIdx(curX-1, curY, ncol), max(board[curX-1][curY], curHeight)));
  }
  if (curX+1<nrow && visited[curX+1][curY] == false) {
   visited[curX+1][curY] = true;
   res += max(0, (curHeight - board[curX+1][curY]));
   minHeap.push(make_pair(getIdx(curX+1, curY, ncol), max(board[curX+1][curY], curHeight)));
  }
  if (curY-1>=0 && visited[curX][curY-1] == false) {
   visited[curX][curY-1] = true;
   res += max(0, (curHeight - board[curX][curY-1]));
   minHeap.push(make_pair(getIdx(curX, curY-1, ncol), max(board[curX][curY-1], curHeight)));
  }
        
  if (curY+1<ncol && visited[curX][curY+1] == false) {
   visited[curX][curY+1] = true;
   res += max(0, (curHeight - board[curX][curY+1]));
   minHeap.push(make_pair(getIdx(curX, curY+1, ncol), max(board[curX][curY+1], curHeight)));
  }
 }
 
 return res;
 
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	int RR, C;

	// vector< vector<int> > L(50, vector<int>(50,0));
	// vector< vector<int> > R(50, vector<int>(50,0));
	// vector< vector<int> > U(50, vector<int>(50,0));
	// vector< vector<int> > D(50, vector<int>(50,0));

	for(int T = 1; T<=t; ++T){
		cin>>RR>>C;
		vector< vector<int> > H(RR, vector<int>(C,0));
		for(int i = 0; i < RR; ++i)
			for(int j = 0; j < C; ++j)
				cin>>H[i][j];

		// for(int i = 0; i<RR; ++i){
		// 	for(int j = 0; j < C; ++j){
		// 		if(j==0)
		// 			L[i][j] = H[i][j];
		// 		else
		// 			L[i][j] = max(L[i][j-1], H[i][j]);
		// 	}
		// }

		// for(int i = 0; i<RR; ++i){
		// 	for(int j = C-1; j >=0 ; --j){
		// 		if(j==C-1)
		// 			R[i][j] = H[i][j];
		// 		else
		// 			R[i][j] = max(R[i][j+1], H[i][j]);
		// 	}
		// }

		// for(int j = 0; j < C; ++j){
		// 	for(int i = 0; i<RR; ++i){
		// 		if(i==0)
		// 			U[i][j] = H[i][j];
		// 		else
		// 			U[i][j] = max(U[i-1][j], H[i][j]);
		// 	}
		// }

		// for(int j = 0; j < C; ++j){
		// 	for(int i = RR-1; i>=0; --i){
		// 		if(i==RR-1)
		// 			D[i][j] = H[i][j];
		// 		else
		// 			D[i][j] = max(D[i+1][j], H[i][j]);
		// 	}
		// }

		// int ans = 0;
		// for(int i = 0; i<RR; ++i){
		// 	for(int j = 0; j < C; ++j){
		// 		ans += max(0, min(L[i][j], min(R[i][j], min(U[i][j], D[i][j]))) - H[i][j] );
		// 	}
		// }
		cout<<getTrap(H)<<endl;
	}
	return 0;
}