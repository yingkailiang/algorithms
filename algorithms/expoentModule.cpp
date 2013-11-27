#include <iostream>

using namespace std;

//method to compute expoential x module n like x^y mod N
int modexp(int x,int y ,int n)
{
   if (y==0)
    return 1;
   else 
    {
     int z =modexp(x,y/2,n);
     if(y % 2 ==1)
       return x*z*z%n ;
     if(y % 2 ==0)
       return z*z%n;  
     }

}  //end func modexp

int main()
{
   int x;
   int y;
   int n;
   cout<<"input x,y,n:"<<endl;
   cin>>x>>y>>n;
   cout<<"the answer of x^y mod N is "<<modexp(x,y,n)<<endl; 
   return 1;
}  //end func main
