#include <iostream>
using namespace std;

//get minium sum of a sequnial 
int minSum(int a[],int n,int &i,int &j)
{
 //loop count
 int k=1;
 //the smallest sum of k-1section
 int t=a[0];
 int s=a[0];
 //tempary variables
 int Ti=0;
 int Tj=0;
 while (k!=n)
 {
  if(t+a[k]<a[k])
  {
   Tj=k;
   t=t+a[k];
  }   
  else
  {
   Ti=k;
   Tj=k;
   t=a[k];
  }
  if(s<t)
  {}
  else
  {
   i=Ti;
   j=Tj;
   s=t;
  }
  k=k+1;
 } //end loop 
 
 return s;
}//end func minSum

int main()
{
 int i=0;
 int j=0;
 int a[3]={-1,3,-2};
 cout<<minSum(a,3,i,j)<<endl; 
 cout<<"i="<<i<<endl;
 cout<<"j="<<j<<endl;
 
 return 1;
}//end main
