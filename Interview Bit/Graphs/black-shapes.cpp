void bfs(vector<string> A, int R, int C, int r, int c, vector<vector<bool> > &vis){
    queue< pair<int, int> > q;
    vis[r][c] = true;
    q.push(make_pair(r,c));
    while(!q.empty()){
        pair<int, int> pp = q.front();
        q.pop();
        
        int tr = pp.first;
        int tc = pp.second;
        
        if(tr - 1 >=0 && tr -1 < R && A[tr-1][tc]=='X' && !vis[tr-1][tc]){
            vis[tr-1][tc] = true;
            q.push(make_pair(tr-1, tc));
        }
        
        if(tr + 1 >=0 && tr + 1 < R && A[tr+1][tc]=='X' && !vis[tr+1][tc]){
            vis[tr+1][tc] = true;
            q.push(make_pair(tr+1, tc));
        }
        
        if(tc - 1 >=0 && tc -1 < C && A[tr][tc - 1]=='X' && !vis[tr][tc - 1]){
            vis[tr][tc - 1] = true;
            q.push(make_pair(tr, tc - 1));
        }
        
        if(tc + 1 >=0 && tc + 1 < C && A[tr][tc + 1]=='X' && !vis[tr][tc + 1]){
            vis[tr][tc + 1] = true;
            q.push(make_pair(tr, tc + 1));
        }
    }
}
int Solution::black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ans = 0;
    int R = A.size();
    int C = A[0].size();
    
    vector< vector<bool> > vis(R, vector<bool>(C, false));
    
    for(int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            if(A[r][c] == 'X'){
                if(!vis[r][c]){
                    ans++;
                    bfs(A, R, C, r, c, vis);
                }    
            }
        }
    }
    return ans;
}