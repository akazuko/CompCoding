#include <bits/stdc++.h>
using namespace std;

map <string, bool> ans;

void genPermutations(int index, string cur, string inp, map<int,bool> covered){
	if(index==inp.size()) {
		// cout<<cur<<endl;
		ans[cur] = true;
		return;
	}
	else{
		for(int i=0; i<inp.size(); ++i){
			if(!covered[i]){
				covered[i] = true;
				genPermutations(index+1, cur + string(1,inp[i]), inp, covered);
				covered[i] = false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	map <int,bool> covered;
	genPermutations(0,"", "abb", covered);
	for(auto i : ans){
		cout<<i.first<<endl;
	}
	return 0;
}