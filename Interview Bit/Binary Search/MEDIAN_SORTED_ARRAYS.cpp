    int min(int a, int b){
        return a<=b?a:b;
    }
    double findKth(const int *A,int m,const int *B,int n,int k){
        if(m>n) return findKth(B,n,A,m,k);
        if(m==0) return B[k-1];
        if(k<=1) return min(A[0],B[0]);
        int pa=min(k/2,m);
        int pb=k-pa;
        if(A[pa-1]<B[pb-1]) return findKth(A+pa,m-pa,B,n,k-pa);
        else if(A[pa-1]>B[pb-1]) return findKth(A,m,B+pb,n-pb,k-pb);
        else return A[pa-1];
    }

double findMedianSortedArrays(const int* A, int n1, const int* B, int n2) {
    int k=n1+n2;
    if(k&0x1) return findKth(A,n1,B,n2,k/2+1);
    else return (findKth(A,n1,B,n2,k/2)+findKth(A,n1,B,n2,k/2+1))/2;
    
}
