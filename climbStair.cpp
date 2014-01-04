#include<iostream>
using namespace std;

int climbStairs(int n);
int main()
{
  cout<<climbStairs(3)<<endl;
  return 1;
}
int climbStairs(int n) { // Fibonacci sequence f(n) = f(n-1) + f(n-2); f(1)=1,f(2)=2
        int current=1;
        int prev=0;
        for(int i=1; i<=n;i++){
            int tmp = current;
            current = current + prev;
            prev=tmp;
        }
        return current;
    }

