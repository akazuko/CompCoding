#include <bits/stdc++.h>

using namespace std;

vector<int> computePrefix(string w){
	vector<int> prefixTable(w.size());
	int k = 0;
	prefixTable[0] = 0;
	for(int i=1;i<w.size(); ++)i{
		while(k>0 && w[k]!=w[i])
			k = prefixTable[k-1];
		if(w[k]==w[i])
			k++;
		prefixTable[i] = k;
	}
	return prefixTable;
}

void findWord(string word, string data){
	vector<int> prefix = computePrefix(word);
	int k = 0;
	for(int i=0; i<data.size(); ++i){
		while(k>0 && word[k]!=data[i])
			k = prefix[k-1];
		if(word[k]==data[i])
			k++;
		if(k==word.size()){
			cout<<"found at : "<<i-word.size()+1<<endl;
			k = prefix[k-1];
		}
	}
}

int main(){
	string word = "ayush";
	string data = "shdsdayu";
	findWord(word, data + data);
	return 0;
}