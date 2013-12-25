
//MergeSort include mergeSort func and merge func
#include <iostream>

using namespace std;

void merge (int a[],int temp[],int left,int mid,int right);
void mergeAll(int a[],int temp[],int length,int end_len);
//mergeSort func which iteratvie mergesort one array
void mergeSortIterative(int a[],int temp[],int left,int right)
{
   //parameter input a[] length
   int length =right -left +1;

   //int iterative end control parameter  
   int end_len =1;

   //loop index to attend left and right sub array 
   int i =0;
   while (end_len<=(length/2)+1)
   {
     mergeAll(a,temp,length,end_len);
     
     cout<<"end_len="<<end_len<<endl;
	 end_len *=2;
   }
}  //end func mergeSortInterative 

//mergeAll func :every time merge all array in one while loop 
void mergeAll(int a[],int temp[],int length,int end_len)
{
   //loop index 
   int i=0;
   int left;
    int right;
	int mid;
   while (i<length)
   {
    left =i;
	if ((i +2*end_len -1)<length)
	{
	   right=i+2*end_len-1;
       mid =(right+ left)/2;
	}
	else 
	{
	 right =length-1;
     mid =right-1;
	}
	merge(a,temp,left,mid+1 ,right);
	
    i+=2*end_len;
   } 
   
}  //end func mergeAll

//mergeSort func which recursive divide the array into two parts
void mergeSort(int a[],int temp[],int left,int right)
{

//end recursive condition right>left
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
  int a[6]={8,7,6,5,4,3};
  int temp[6];
  int length =sizeof(a)/sizeof(int);
  cout<<"length="<<length<<endl;
  mergeSortIterative(a,temp,0,length-1); 
  for (int i=0;i<length;i++)
  {
	  cout<<a[i]<<endl;
  }
   cout<<endl;
   system("pause");
  return 1;
}  //end func main

