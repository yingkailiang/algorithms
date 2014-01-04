#include <iostream>
#include <vector>

using namespace std;
vector<int> grayCode(int n); 

int main(){
 vector<int> res = grayCode(3); 
 for(vector<int>::iterator i = res.begin();i!=res.end();++i){
   cout<<*i<<endl; 
 }
 return 1;
}

vector<int> grayCode(int n) {
        vector<int> rec;
        int count = 0x01 << n;
        for (int i=0;i<count;i++){
            rec.push_back(i ^ i>>1);
        }
        return rec;
    }
