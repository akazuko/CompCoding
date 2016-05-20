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
	long long int N,K;
	int turn;
	long long int *arr;
	while(T--) {
		turn = 0;
		N = getInt();
		K = getInt();

		arr = calloc(sizeof(long long int),N);
		int num = 1;
		printf("%d ",num);

		while(K > 0) {
			if(num+K <= N) num = num + K;
			else num = num - K;
			arr[num - 1] = 1;
			printf("%d ", num );
			K--;
		}
		int i;
		arr[0] = 1;
		for (i = 0; i < N; ++i) {
			if(arr[i] != 1) printf("%d " , i+1);
		}

		printf("\n");
		free(arr);
		
	}

	return 0;
}