
//MergeSort include mergeSort func and merge func
#include <iostream>

using namespace std;

void merge (int a[],int temp[],int left,int mid,int right);
//mergeSort func which recursive divide the array into two parts
void mergeSort(int a[],int temp[],int left,int right)
{

//end recursive condition right>left`
  if(right>left) 
  {
  //set one index is the middle of the left and the right  
  int mid =(left + right )/2 ;
  //recursive sort array by mergesort
  mergeSort(a,temp,left,mid); 
  mergeSort(a,temp,mid+1,right);
  merge(a,temp,left,mid+1,right);
  } 
}  //end func MergeSort

//merge func which combine two sorted array 
void merge (int a[],int temp[],int left,int mid,int right)
{
   //initial three parameter 
   int left_end =mid-1;   //define the end of the left array
   int elementsNo =right -left+1;  //the total number of elements in right&left 
   int index =left;
   
   //two array have elements
   while(left<=left_end && mid <=right)
   {
      if(a[left]<=a[mid])
      {
        temp[index]=a[left];
        index++;
        left++;
      }
      else
      {
        temp[index]=a[mid];
        mid++;
        index++;
      }
   }  
   
   //only left sub array have elements
   while(left<=left_end)
   {

     temp[index]=a[left];
     index++;
     left++;
   }
   
   //only right sub array have elements 
   while(mid<=right )
   {
     temp[index]=a[mid];
     index++;
     mid++;
   } 
   
   //copy temp[] elements back to a[]
   for(int i=0;i <elementsNo;i++)
   {
     a[right]=temp[right];
     right--;
   }
}  //end func merge 

//main func 
int main()
{
  int a[10]={9,8,7,6,5,4,3,2,1,0};
  int temp[10];
  
  int length =sizeof(a)/sizeof(int);
  mergeSort(a,temp,0,length-1); 
  for(int i=0;i<length;i++)
  {
   cout<<a[i]<<" ,";
  }
   cout<<endl;
   system("pause");
  return 1;
}  //end func main

