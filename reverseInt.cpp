#include <iostream>
using namespace std;

int reverse(int x); 
int main()
{
 cout<<reverse(123)<<"\n";

 return 1;
}

int reverse(int x) {
        int flag=1;
        if(x< 0) {
         x=-x;
         flag=-1;
        }
        else{if(x-10<0) return x;}
        int a = 0;
        while(x>0) {
          a=a*10 + x%10;
          x/=10;
        }
        return a*flag;
 }
