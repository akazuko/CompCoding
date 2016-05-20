#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
 
    }
 
 
 
int isSpaceChar(char c) {
            return c == ' ' || c == '\n' || c == '\r' ;
        }
        
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isSpaceChar(ch))
            ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}



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

	int T;
    scanf("%d",&T);
    int i =0;
    int n,m,count;
    int *arr,*arr2;
    while(T--) {
        
        scanf("%d",&n);
        arr = (int *)malloc(sizeof(int)*n);
        arr2 = (int *)malloc(sizeof(int)*n);
        scanf("%d",&m);

        for(i = 0 ;i < n ; ++i) {scanf("%d",arr  + i); arr2[i] = 0;}


        
        count = 0;
        while(count!=(n)) {
            
            if(arr[i] != -1){
                arr2[i] += m;
            
            if(arr2[i] >= arr[i]){
            arr[i] = -1;
            
            count++;    
            } 
        }
            
            if (i == n-1) i = 0;
            else ++i;
            
        }
        if(i == 0) 
        printf("%d\n",n);
        else
        printf("%d\n",i);
        
        free(arr);
        free(arr2);
    }


	return 0;
}