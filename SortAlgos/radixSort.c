#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *countingSort(int *A, int len, int k, int run){
	int C[k];
	int *B;
	B = (int *)malloc(sizeof(int)*len);
	int i;

	int fig = pow(10,run);

	for(i = 0 ; i<k ; ++i)	C[i]=0;
	for(i = 0 ; i<len ; ++i) C[( (A[i] / fig) % 10)] += 1;
	for(i = 1 ; i<k ; ++i)	C[i] += C[i-1];
	for(i = len-1 ; i>=0 ; --i) {
		B[C[( (A[i] / fig) % 10)]-1] = A[i];
		C[( (A[i] / fig) % 10)] -= 1;
	}
	return B;
}

int *radixSort(int *array, int d, int len) {
	int i;
	
	//int *res;
	//res = (int *)malloc(sizeof(int)*len);
	//res = array;
	
	for( i=0 ; i<d ; ++i) {
		//res = countingSort(res,len,10,i);
		array = countingSort(array,len,10,i);
	}
	return array;
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
	B = radixSort(A,4,length);

	for(i = 0 ; i<length ; ++i)     printf("%d ",B[i]);
	printf("\n");
	return  0;
}