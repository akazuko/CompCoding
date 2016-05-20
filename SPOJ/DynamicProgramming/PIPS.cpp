#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <strings.h>

using namespace std;

#define sd(x)   scanf("%d",&x); 
#define sll(x)  scanf("%lld",&x);
#define ss(x)   scanf("%s",x);
#define ll long long
#define pll(x)  printf("%lld",x);
#define pd(x)   printf("%d",x);
#define ps(x)   printf("%s",x);
#define pii pair<int,int>
#define pp pair<int, pair<int,int>>

float dp[1000][1000];

int main()
{
    for(int i=0;i<1000;i++)
    dp[0][i]=0;
    
    dp[1][0]=0;
    
    for(int i=1;i<7;i++)
    dp[1][i]=1/6.0;
    
    for(int i=7;i<1000;i++)
    dp[1][i]=0;
    
    for(int i=0;i<1000;i++)
    dp[i][0]=0;
    
    for(int i=2;i<1000;i++)
    for(int k=1;k<1000;k++)
    {
            switch(k)
            {
                     case 1: dp[i][k]=dp[i-1][k-1]/6.0;
                             break;
                     case 2: dp[i][k]=(dp[i-1][k-1]+dp[i-1][k-2])/6.0;
                             break;
                     case 3: dp[i][k]=(dp[i-1][k-1]+dp[i-1][k-2]+dp[i-1][k-3])/6.0;
                             break;
                     case 4: dp[i][k]=(dp[i-1][k-1]+dp[i-1][k-2]+dp[i-1][k-3]+dp[i-1][k-4])/6.0;
                             break;
                     case 5: dp[i][k]=(dp[i-1][k-1]+dp[i-1][k-2]+dp[i-1][k-3]+dp[i-1][k-4]+dp[i-1][k-5])/6.0;
                             break;
                     default: dp[i][k]=(dp[i-1][k-1]+dp[i-1][k-2]+dp[i-1][k-3]+dp[i-1][k-4]+dp[i-1][k-5]+dp[i-1][k-6])/6.0;
                             break;
            }
            
    }
    
    int t; sd(t);
    while(t--){
        int n,k;
        sd(n); sd(k);
        if(n<1000 && k<1000){
            // unsigned long long y=(long long)(dp[n][k]*100);
            // cout<<y<<endl;
            cout<<(ll)(dp[n][k]*100)<<endl;
        }
        else
            cout<<0<<endl;
    }
    return 0;
}