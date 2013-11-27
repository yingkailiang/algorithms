#include <iostream>

using  namespace std;
//method to compute the great common digit of a and b like gcd(a,b)=d
int gcd(int a,int b)
{
   if (b==0)
   return a ;
   else 
    return gcd(b ,a %b);
}  //end func gcd
 
int main()
{
   int a ;
   int b ;
   cout<<"input a,b :"<<endl;
   cin>>a>>b;
   cout<<"the great common digit of "<<a <<" and "<<b<<" is "<<gcd(a,b)<<endl;
   return 1;
}  //end func main
