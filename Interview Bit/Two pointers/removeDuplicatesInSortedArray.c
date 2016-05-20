#include <stdio.h>
int removeDuplicates(int* A, int n1) {
    int removed=1;
    int temp;
    if(n1>0)
        temp=A[0];
    int inarr=0;
    while(inarr<n1){
        if(temp!=A[inarr]){
            temp=A[inarr];
            A[removed++]=temp;
        }
        inarr++;
    }
    return removed;
}

int main(int argc, char const *argv[])
{
    int A[] = {0};
    printf("%d\n", removeDuplicates(A, 1));
    return 0;
}