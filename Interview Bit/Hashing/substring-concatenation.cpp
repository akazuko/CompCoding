vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    int num = B.size();
    int len = B[0].size();
    if (num==0){return res;}
    map<string,int> mp;  
    for (int i=0;i<num;i++){mp[B[i]]++;}      
          
    int i=0;
    while ((i+num*len-1)<A.size()){
        map<string,int> mp2;
        int j=0;
        while (j<num){
            string subs = A.substr(i+j*len,len);
            if (mp.find(subs)==mp.end()){
                    break;
            }else{
                mp2[subs]++;
                if (mp2[subs]>mp[subs]){
                    break;
                }
                j++;  
            }
        }
        if (j==num){res.push_back(i);}
        i++;
    }
      
        return res;
}
