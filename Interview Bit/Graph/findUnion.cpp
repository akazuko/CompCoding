#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> P(10000);
vector<int> rank(10000);

int find_set(int x){
	if(x!=P[x])
		P[x] = find_set(P[x]);
	return P[x];
}

int merge_sets(int x, int y){
	int Px = find_set(x);
	printf("Px : %d \n", Px);
	int Py = find_set(y);
	printf("Py : %d \n", Py);
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

void printP(int n){
	for(int i=0;i<n;++i){
		printf("%d ", P[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
	int arr[]={1,2,3,4,5,6};
	for(int i=0; i<6; ++i)
		create_set(i);
	merge_sets(0,1);
	printP(6);
	merge_sets(4,5);
	printP(6);
	merge_sets(1,5);
	printP(6);
	printf("1 belongs to : %d\n", find_set(0));
	return 0;
}