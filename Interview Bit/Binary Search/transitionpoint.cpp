int pos(int a[], int start, int end){
    int mid;
    while(a[start]<a[end]){
        mid = start + (end - start)/2;
        if(a[mid]==0 && a[end]==1) start = mid + 1;
        else end = mid;
    }
    return start;
}
int transitionPoint(int arr[],int n)
{
    return pos(arr, 0, n-1);
}
