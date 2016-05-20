#include <stdio.h>
#include <stdlib.h>

int partition(int *arr,int p, int r) {
	srand(time(NULL));
	int randomPivot = (rand() % (r+1-p))+p;
	int temp = arr[p];
	arr[p] = arr[randomPivot];
	arr[randomPivot] = temp;
	int j = p+1;
	int temp2,i;
	i = p;
	temp = arr[p];
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
	printf("%d\n", i);
	return i;
}

/*int randomquicksort(int *arr,int start,int end) {
	srand(time(NULL));
	int randomPivot = r = (rand() % (end+1-start))+start;
	int temp = arr[start];
	arr[start] = arr[randomPivot];
	arr[randomPivot] = temp;
	return quicksort(arr,start,end);
}
*/

void randomquicksort(int *arr, int start, int end) {
	int q;
	if(start < end) {
		q = partition(arr,start,end);
		printf("%d\n", q);
	}
	if(start-q>-1 || q+1-end>0) return;
	randomquicksort(arr,start,q-1);
	randomquicksort(arr,q+1,end);
}

int main(void) {

	int array[] = {2,6,5,9,4,3,7,0,8965,236};
	randomquicksort(array,0,9);
	int i = 0;
	for (i = 0; i < 10; ++i) {
		printf("%d ",array[i] );
	}
	printf("\n");
	return 0;
}