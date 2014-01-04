#include <iostream>
using namespace std;

int climbStairs(int n); 
int fib(int n,int *mem);
int main()
{
  cout<<climbStairs(2)<<endl;
  return 1;
}
int climbStairs(int n) { // Fibonacci sequence f(n) = f(n-1) + f(n-2); f(1)=1,f(2)=2
        // memorized DP:
       int *mem = new int[n];
       for(int i=0;i<n;i++)
            mem[i]=1;
       return fib(n,mem);
}
int fib(int n,int *mem){
       if(n<=1) return 1;
       if(mem[n-1]!=1) return mem[n-1];
       mem[n-1] = fib(n-1,mem) + fib(n-2,mem); 
       return mem[n-1];
} 
