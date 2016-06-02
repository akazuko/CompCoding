#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int ans(int a, int b, int c){
	int co = 1;
	int va = a;
	int vb = 0;
	int t;
	while(va!=c || vb!=c){
		if(va==c || vb==c) break;

		if(va==0){
			va = a;
			co++;
		}
		
		if(vb==b){
			vb = 0;
			co++;
		}
		

		t = min(va,b-vb);
		va-=t;
		vb+=t;
		co++;

	}
	return co;
}

int main(int argc, char const *argv[]) {
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);

		if(c>a && c>b) printf("-1\n");
		else if(c%gcd(a,b) != 0) printf("-1\n");
		else if(c==a || c==b) printf("1\n");
		else printf("%d\n", min(ans(a,b,c),ans(b,a,c)));
	}
	return 0;
}