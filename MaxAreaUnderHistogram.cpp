#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int getMaxArea(vector<int> hist, int n) {
   
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    for(i=0; i<n; ++i){
        if (s.empty() || hist[s.top()] <= hist[i]) s.push(i);
        else{
            while(!s.empty() && hist[s.top()] > hist[i]){
                tp = s.top();
                s.pop();
                area_with_top = hist[tp]*(s.empty()?i:i-s.top()-1);
                if (max_area < area_with_top)
                   max_area = area_with_top;
            }
            s.push(i);
        }
    }
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    
    return max_area;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0; i<n; ++i) cin>>ar[i];
    
    cout<<getMaxArea(ar,n);
    return 0;
}
