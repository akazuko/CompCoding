#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> P(50001);
vector<int> rank(50001);
vector<char> animal(50001);

int find_set(int x){
	if(x!=P[x])
		P[x] = find_set(P[x]);
	return P[x];
}

int merge_sets(int x, int y){
	int Px = find_set(x);
	// printf("Px : %d \n", Px);
	int Py = find_set(y);
	// printf("Py : %d \n", Py);
	if(rank[Px] > rank[Py])
		P[Py] = Px;
	else
		P[Px] = Py;
	if(rank[Px] == rank[Py])
		rank[Py] = rank[Py] + 1;
}

int create_set(int x){
	P[x] = x;
	rank[x] = 0;
}

void init(int n){
	for(int i=0; i<=n; ++i){
		P[i] = i;
		animal[i] = 'D';
		rank[i] = 0;
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		int count = 0;
		cin>>n;
		cin>>k;
		init(n);
		while(k--){
			int a,b,type;
			cin>>type>>a>>b;
			if(a<=n && b<=n){
				merge_sets(a,b);
				int P_A = find_set(a);
				int P_B = find_set(b);
				char A = animal[P_A];
				char B = animal[P_B]; 
				if(type==1){
					if(A=='D' && B=='D'){
						animal[P_A] = 'A';
						animal[P_B] = 'A';
					}
					else if(A=='A' && B=='D'){
						animal[P_B] = 'A';
						merge_sets(a,b); 
					}
					else if(A=='B' && B=='D'){
						animal[P_B] = 'B';
						merge_sets(a,b);
					}
					else if(A=='C' && B=='D'){
						animal[P_B] = 'C';
						merge_sets(a,b);
					}
					else if(A=='D' && B=='A'){
						animal[P_A] = 'A'; 
						merge_sets(a,b);
					}
					else if(A=='D' && B=='B'){
						animal[P_A] = 'B';
						merge_sets(a,b);
					}
					else if(A=='D' && B=='C'){
						animal[P_A] = 'C';
						merge_sets(a,b);
					}
					else{
						cout<<"unsame\n";
						count++;
					}
					cout<<animal[P_A]<<" "<<animal[P_B]<<endl;
				}
				else if(type == 2){
					if(a!=b){
						if(A=='D' && B=='D'){
							P[P_A] = 'A';
							P[P_B] = 'B';
						} 
						else if( (A=='A' && B=='C') || (A=='C' && B=='B') || (A=='B' && B=='A') ){
							cout<<"rev\n";
							count++;
						}
						else{
							if(A=='D' && B=='A') P[P_A] = 'C';
							else if(A=='D' && B=='B') P[P_A] = 'A';
							else if(A=='D' && B=='C') P[P_A] = 'B';
							else if(B=='D' && A=='A') P[P_B] = 'B';
							else if(B=='D' && A=='B') P[P_B] = 'C';
							else if(B=='D' && A=='C') P[P_B] = 'A';
						}
					}
					else{
						cout<<"=\n";
						count++;
					}
				cout<<a<<": "<<A<<" "<<b<<": "<<B<<endl;
				}
			}
			else{
				count++;
				cout<<">n\n";
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
