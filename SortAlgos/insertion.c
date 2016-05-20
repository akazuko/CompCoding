#include <stdio.h>

void insertionSort(int *arr, int low, int high){
	if(low < high) insertionSort(arr,low,high-1);
	int j = high;
	int key = arr[high];
	//use < for descending order and > for ascending order
	while(j >= 0 && arr[j] <= key) {
		arr[j] = arr[j-1];
		--j;
	}
	arr[j+1] = key;

}

int main() {
	int arr[] = {1,7,4,6,2,3,5};
	insertionSort(arr,0,6);
	int i;
	for (i = 0; i < 7; ++i)	printf("%d\n", arr[i]);
	return 0;

}