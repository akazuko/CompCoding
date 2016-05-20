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
    double N,X,Y,sum,sum2,count1,count2,count11,count22,equals;
    int *arr,temp,i;
	while(T--) {
        count2 = 0;
        count1 = 0;
        count11 =0;
        count22 = 0;
        scanf("%lf", &N);
        scanf("%lf", &X);
        scanf("%lf", &Y);
        arr = (int *)malloc(sizeof(int)*N);

        for(i = 0 ;i <N ;++i) {
            scanf("%d",arr+i);
        }
        sum = 0;
        equals = 0;
        sum2 = 0;
        for(i = 0 ;i <N ;++i) {
            scanf("%d",&temp);
            if( temp > arr[i]){
                if( count2 < Y) {
                sum+=temp;
                //sum2+=temp;
                count2++;
                //continue;
                }

            }
            else if ( temp < arr[i])
                 if(count1 < X) {
                sum+=arr[i];
                //sum2 += arr[i];
                count1++;
                //continue;
                 }
                 else if(count2 < Y) {
                sum+=temp;
                //sum2+=temp;
                count2++;

                }
            else{
                sum = sum + temp;
                equals++;
            }
            
            /*if( temp < arr[i]){
                if( count11 < X) {
                sum2+=arr[i];
                //sum2+=temp;
                count11++;
                //continue;
                }

            }
            else
            if(count22 < Y) {
                sum2+=temp;
                //sum2 += arr[i];
                count22++;
                //continue;
            }
            else if(count11 < X)
            {
                sum2+=arr[i];
                //sum2+=temp;
                count11++;

            }

            //if(temp == arr[i])

*/
        }
         if(sum > sum2) printf("%.0lf\n",sum);
            else printf("%.0lf\n",sum2);

//	    printf("%.0lf\n",sum);
        free(arr);
    }

	return 0;
}