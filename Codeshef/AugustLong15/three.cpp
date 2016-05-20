#include <cmath>
#include <iostream>
#include <stdio.h>

const double pheta = 0.5*(std::sqrt(5)+1);

double fib(unsigned int n)
{
    return (std::pow(pheta, n) - std::pow(1 - pheta, n)) / std::sqrt(5);
}

unsigned int fibo_lowerbound(double N, unsigned min=0, unsigned max=1000)
{
    unsigned newpivot = (min+max)/2;
    if (min==newpivot)
        return newpivot;

    if (fib(newpivot) <= N)
        return fibo_lowerbound(N, newpivot, max);
    else
        return fibo_lowerbound(N, min, newpivot);
}

std::pair<double, double> fibo_range(unsigned int n)
// unsigned int fibo_range(unsigned int n)
{
    // if (n<=2)
        // return n;
    unsigned int lbound = fibo_lowerbound(n);
    // return lbound;
    // return std::make_pair(fib(lbound), fib(lbound+1));
}

void display(unsigned int n)
{
    std::pair<double, double> range = fibo_range(n);
    std::cout << "Fibonacci range wrapping " << n << " is "
              << "[" << (unsigned long long) range.first << ", " << (unsigned long long) range.second << "]"
              << std::endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    int a[]={1,2,3,3,4,4,4,5,5,5,5};
    while(T--){
        int N;
        scanf("%d",&N);
        // printf("%d\n", fibo_range(N));
        std::cout<<display(N);
    }
}