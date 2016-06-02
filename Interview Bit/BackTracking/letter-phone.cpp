void data(string inp, string sos, int i, int N, vector<string> &ans){

    if(i==N){
        ans.push_back(sos);
        return;
    }

    string daa[] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index = inp[i] - '0';
    for(char inn : daa[index]){
        data(inp, sos + string(1,inn), i+1, N, ans);
    }
    return;
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    data(A, "", 0, A.size(), ans);
    return ans;
}
