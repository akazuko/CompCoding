#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
int main(void){

	int testCases,found;
	scanf("%d",&testCases);
	long *A;
	long coins, e, o;
	int op;
	while(testCases > 0){
		op = 0;
		scanf("%ld",&e);
		scanf("%ld",&o);
		while(e>=o) {
			if((o/e) == 1.5) break;
			else
				if(e >= o) {
					--e;
					++o;
					op++;
				}
				else if ((e/o) < (2/3)) {
					e++;
					
				}
		}


		testCases--;
	}
	return 0;
}