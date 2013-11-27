#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//sort algorithms :sort one array
class insertionSort
{
  int array[3];
public:
  void insertSort()
  {
   for (int i=0;i<3;i++)
   {
   cout<<"please input number :"<<endl;
   int No;
   cin>>No;
   for (int i=0;i<3;i++)
    array[i] =No;
   }
   for (int i=1;i<2;i++)
   {
     //array[i] is add to a sorted array
     //save array[i] to make a hole at iHole
     int item =array[i];
     int iHole =i;
     //keep moving the hole to next smaller index until A[iHole -1] <= item 
     while ( iHole > 0 && array[iHole-1] >item)
      {
        int temp;
        array[iHole]=temp;
        array[iHole]=array[iHole-1];
        array[iHole-1] =temp;
 
      }
        array[iHole] =item;
   }
   cout<<"the result is :"<<endl;
   for (int i=0;i<3;i++)
   {
      cout<<array[i]<<"     "<<i<<endl; 
   }
  }  //end func insrtSort 
};  //end class insertionSort

int main()
{
  insertionSort i ;
  i.insertSort();
  return 1;

}

