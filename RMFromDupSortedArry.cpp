#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n); 
int main()
{
  int a[]={1,1,2}; 
  cout<<removeDuplicates(a,3)<<endl;
  return 1;
}

int removeDuplicates(int A[], int n) {
    if(n==2) {
      if(A[0]==A[1]) return 1;
    }
    int len = n;
    for(int i=0;i<len;i++){
        if(A[i] == A[i+1]){
            for(int j =i;j<len-1;j++){
                A[j]=A[j+1];
            }
            len--;
         }
     }
        return len;
 }
