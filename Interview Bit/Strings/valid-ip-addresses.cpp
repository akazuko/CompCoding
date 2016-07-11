void genP(string A, int cur, int left, vector<string> &present, vector<string> pres){
    // cout<<pres<<endl;
    if(left == 0 ){
        if(cur>=A.size()){
            bool valid = true;
            for( string data : pres){
                if(stoi(data)>255 or (data[0]=='0' && data.size() > 1) ){
                    valid = false;
                    break;
                }
            }
            if(valid){
                string tt = pres[0] + "." + pres[1] + "." + pres[2] + "." + pres[3] ;
                present.push_back(tt);
            }
                
        }
        return;
    }
    
    for(int i = 1; i<4; ++i){
        if (cur + i > A.size()) continue;
        
        string t = A.substr(cur, i);
        pres.push_back(t);
        genP(A, cur + i, left -1, present, pres);
        pres.pop_back();
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ans;
    vector<string> pres;
    genP(A, 0, 4, ans, pres);
    return ans;
}
