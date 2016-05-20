#include <stdio.h>
#include <stdlib.h>

int *countingSort(int *A, int len, int k){
	int C[k];
	int *B;
	B = (int *)malloc(sizeof(int)*len);
	int i;
	for(i = 0 ; i<k ; ++i)	C[i]=0;
	for(i = 0 ; i<len ; ++i) C[A[i]] += 1;
	for(i = 1 ; i<k ; ++i)	C[i] += C[i-1];
	for(i = len-1 ; i>=0 ; --i) {
		B[C[A[i]]-1] = A[i];
		C[A[i]] -= 1;
	}
	return B;
}


int main(){
	int A[100];
	int length;
	int i;
	scanf("%d",&length);

	for(i = 0 ; i<length ; ++i)  scanf("%d",&A[i]);
	for(i = 0 ; i<length ; ++i)  printf("%d ",A[i]);
	printf("\n");

	int *B;
	B = countingSort(A,length,10);

	for(i = 0 ; i<length ; ++i)     printf("%d ",B[i]);
	printf("\n");
	return  0;
}