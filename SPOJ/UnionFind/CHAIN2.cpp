#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// vector<char> animal(50001);

// void init(int n){
// 	for(int i=0; i<=n; ++i){
// 		animal[i] = 'D';
// 	}
// }

void disp(int n, vector<char> a){
	for(int i=1;i<=n;++i)
		cout<<"("<<i<<","<<a[i]<<")"<<" ";
}

int main(int argc, char const *argv[]) {
	int t,n,k,type,count,a,b;
	char A,B;
	cin>>t;
	while(t--){
		count = 0;
		
		cin>>n;
		cin>>k;
		vector<char> animal(n+1,'D');
		
		// init(n);
		while(k--){
			
			cin>>type>>a>>b;

			if(a<=n && b<=n){

				A = animal[a];
				B = animal[b];

				if(type==1){
					if(A=='D' && B=='D'){
						animal[a] = 'A';
						animal[b] = 'A';
					}
					else if(A==B){

					}
					else if(A=='A' && B=='D'){
						animal[b] = 'A';
					}
					else if(A=='B' && B=='D'){
						animal[b] = 'B';
					}
					else if(A=='C' && B=='D'){
						animal[b] = 'C';
					}
					else if(A=='D' && B=='A'){
						animal[a] = 'A'; 
					}
					else if(A=='D' && B=='B'){
						animal[a] = 'B';
					}
					else if(A=='D' && B=='C'){
						animal[a] = 'C';
					}
					else if(A!=B){
						// cout<<"unsame\n";
						count++;
					}
				}
				else if(type == 2){
					if(a!=b){
						if(A=='D' && B=='D'){
								animal[a] = 'A';
								animal[b] = 'B';
						}
						else if(A!=B){
							 
							if( (A=='A' && B=='C') || (A=='C' && B=='B') || (A=='B' && B=='A') ){
								// cout<<"rev\n";
								count++;
							}
							else{
								if(A=='D' && B=='A') animal[a] = 'C';
								else if(A=='D' && B=='B') animal[a] = 'A';
								else if(A=='D' && B=='C') animal[a] = 'B';
								else if(B=='D' && A=='A') animal[b] = 'B';
								else if(B=='D' && A=='B') animal[b] = 'C';
								else if(B=='D' && A=='C') animal[b] = 'A';
							}
						}
						else{
							// cout<<"=\n";
							count++;	
						}
					}
					else{
						// cout<<"=\n";
						count++;
					}
				// cout<<a<<": "<<A<<" "<<b<<": "<<B<<endl;
				}
			}
			else{
				count++;
				// cout<<">n\n";
			}
			// disp(n,animal);
			// cout<<endl;
		}
		cout<<count<<endl;
	}
	return 0;
}
