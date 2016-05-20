#include <stdio.h>
#include <stdlib.h>

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

	while(T--) {

		printf("Sherlock\n");
	}

	return 0;
}