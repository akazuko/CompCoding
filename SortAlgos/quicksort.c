#include <stdio.h>

int partition(int *arr,int p, int r) {
	int j = p+1;
	int temp2,i;
	i = p;
	int temp = arr[p];
	while(j<=r) {
		if(arr[j] <= temp) {
			i++;
			temp2 = arr[j];
			arr[j] = arr[i];
			arr[i] = temp2;
		}
		++j;
	}
	temp2 = arr[p];
	arr[p] = arr[i];
	arr[i] = temp2;
	//printf("%d\n", i);
	return i;
}

void quicksort(int *arr, int start, int end) {
	int q;
	if(start < end) {
		q = partition(arr,start,end);
		int i = 0;
	for (i = 0; i < 10; ++i) {
		printf("%d ",arr[i] );
	}
		printf("\n");
		quicksort(arr,start,q-1);
	quicksort(arr,q+1,end);
	}
	/*if(start-q>-1 || q+1-end>0) return;
	quicksort(arr,start,q-1);
	quicksort(arr,q+1,end);*/
}

int main(void) {

	int array[] = {4,8,3,9,7,10,1,2,5,6};
	quicksort(array,0,9);
	int i = 0;
	/*for (i = 0; i < 8; ++i) {
		printf("%d ",array[i] );
	}*/
	printf("\n");
	return 0;
}