#include <iostream>
using namespace std;

int singleNumber(int A[], int n); 
int main(){
    int A[] = {4,4,4,1};
    cout<<singleNumber(A,4)<<endl;
    return 1;
}
int singleNumber(int A[], int n) {
        int bit[32]={0};
        int k=1;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                int rotation = A[i]>>j; //compare with 001,need to be the last digits
                if(rotation == 0 ) break; //all digits have already been compared  
                bit[j] += rotation & k;
            }
        }
        for(int i=0;i<32;i++){
            res += bit[i]%3 << i;
        }
        return res;
    }

