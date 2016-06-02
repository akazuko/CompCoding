#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    map<string, vector<int> > m;
    string t;
    for(int i=0 ; i<A.size(); ++i){
        t = A[i];
        sort(t.begin(), t.end());
        m[t].push_back(i);
    }
    
    vector<vector<int> > ans;
    for(auto i : m){
        ans.push_back(i.second);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}