#include <iostream>
using namespace std;

class Fabonnaci
{
public :
  int fabonnaci(int n)
  {
    if (n==0)
     return 0;
    if (n==1)
     return 1;
    else if (n>1)
     return(fabonnaci(n-1)+fabonnaci(n-2)); 
  }
}; //end class Fabonnaci

int main()
{
   Fabonnaci f;
   int n;
   cout<<"input a number :"<<endl;
   cin>>n;
   cout<<"the result is "<<f.fabonnaci(n)<<endl;
   return 1;

}  //end main
