#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

//check whether three number can form one triangle
class FormTriangle
{
  int a[3];
public :
  /////////////////////////////////////////////////////////////////////////////
  //checkFormed`
  //description:get three input and check whether three number can form triangle
  //input:none
  //return :bool
  /////////////////////////////////////////////////////////////////////////////
   bool checkFormed()
 {
  for (int i=0;i <3;i++)
  {
    cout<<"please input three ascending ordered number:"<<endl; 
    cin>>a[i];
  }
  //check condition
  int a=3;
  int b=4;
  int c=5;

  // if ((a[0]+a[1])>a[2] && (a[2]-a[1])<a[0] )
     if ((a+b)>c &&(c-b)<a)
  {
   cout<<"these three number can form triangle"<<endl;
   return true;
  }
  else 
  {
   cout<<"these three number can not form triangle"<<endl;
   return false;
  }
 } //end func checkFormed  
};  //end class FormTriangle
//main func
int main()
{
  FormTriangle ft;
  ft.checkFormed();
  return 1;
}

