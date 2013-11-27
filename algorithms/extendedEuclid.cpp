#include <iostream>

#include "extendedEuclid.h"
using namespace std;
//Extended Euclid method to compute gcd(a,b) =ax+by

//initial the parameter 
extendedEuclid::extendedEuclid()
{
 extendedEuclid::a1=1;
 extendedEuclid::a2=0;
 extendedEuclid::b1=0;
 extendedEuclid::b2=1;
}  //end func extendedEuclid
int extendedEuclid::EE(int a ,int b)
{
   if (b==0)
    return a;
   else 
   {
   //compute the parameter
   int times =a/b;
   int temp1= extendedEuclid::a1;
   int temp2= extendedEuclid::a2;
   extendedEuclid::a1=extendedEuclid::b1;
   extendedEuclid::a2=extendedEuclid::b2;
   extendedEuclid::b1=temp1-times*extendedEuclid::b1;
   extendedEuclid::b2=temp2-times*extendedEuclid::b2; 

   return EE(b,a%b);
   } 
}  //end func EE


//func main to display EE(a,b)=ax+by
int main()
{
   extendedEuclid e; 
   
   int a;
   int b;
   cout<<"please input a,b"<<endl;
   cin>>a>>b;
   cout<<"d="<<e.EE(a,b)<<endl;
   int gcd=a*e.a1+b*e.a2;
   cout<<"x="<<e.a1<<endl;
   cout<<"y="<<e.a2<<endl;
   cout<<"ax+by="<<gcd<<endl;
   if (gcd==1)
   {
    cout<<"x= "<<e.a1<<"  is the inverse multiplication of "<<a <<" module "<<b<<endl;
   } 
   return 1;
}  //end func main



