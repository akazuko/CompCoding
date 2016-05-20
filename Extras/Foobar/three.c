#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int getInt() {
	long long int value = 0;
    int c = getchar_unlocked();
    while(c < 48 || c > 57) c = getchar_unlocked();
    while(c >= 48 && c <= 57){
        value = (value << 1) + (value << 3) + (c - 48);
        c = getchar_unlocked();
    }
    return value;
}

int main(void) {

	long long int T = getInt();
	long long int A, B, C;
	int turn;

	while(T--) {
		A = getInt();
		B = getInt();
		C = getInt();

		long long int mul = (A+B+C)*(B+C-A)*(C+A-B)*(A+B-C);
		mul = sqrt(mul);
		mul = (A*B*C)/mul;

		printf("%lld\n",mul );

	}

	return 0;
}