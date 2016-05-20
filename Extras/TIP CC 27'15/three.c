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

	long long int T = getInt();
    double N;
    char *arr;
    int i,size,j;
	while(T--) {

		scanf("%lf",&N);
        arr =(char *)malloc(sizeof(char)*N);

        scanf("%s",arr);
        size = 0;
        j=1;
        if(arr[0] == '1') size++;
        if(arr[1] != '\0'){
            for(i = 1 ; i< N ; ++j ) {
       //         if((*(arr + i)=='1' && (*(arr + i+1)-'0')==j) size++;
                if(arr[i]=='1' && (arr[i+1]-'0')==j) size++;
                else    break;
                i=i+j+1;
            }
        }
        printf("%d\n", size);
	}

	return 0;
}