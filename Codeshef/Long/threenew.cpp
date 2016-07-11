#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	
	bool possible;
	long long c;
	while(t--){
		deque<int> rz;
		deque<int> ro;
		int lo = 0;
		int lz = 0;

		string a;
		string b;

		cin>>a;
		cin>>b;

		c = 0;
		for(int i=0;i<a.size(); ++i){
			if(a[i]=='0' && b[i]=='1') 			rz.push_back(i);
			else if(a[i]=='1' && b[i]=='0')		ro.push_back(i);
			else if(a[i]=='1' && b[i]=='1')		lo++;
			else if(a[i]=='0' && b[i]=='0')		lz++;
		}

		for(int i=0; i<a.size(); ++i){
			if(a[i]!=b[i]){
				if(a[i]=='0'){
					
					if(!ro.empty()){
						int index = ro[0];
						ro.pop_front();
						rz.pop_front();
						lo++;
						lz++;
						a[i] = '1';
						a[index] = '0';
						c++;
					}
					else if(lo) {
						lo++;
						c++;
						a[i] = '1';
					}
				}
				else{
					if(!rz.empty()){
						int index = rz[0];
						rz.pop_front();
						ro.pop_front();
						lz++;
						lo++;
						a[i] = '0';
						a[index] = '1';
						c++;
					}
					else if(lz){
						c++;
						lz++;
						a[i] = '0';
					} 
				}
			}
		}


		possible = true;
		for(int i=0; i< a.size(); ++i){
			if(a[i]!=b[i]){
				possible = false;
				break;
			}
		}

		if(possible) cout<<"Lucky Chef"<<endl<<c<<endl;
		else		 cout<<"Unlucky Chef"<<endl;
	}
	return 0;
}