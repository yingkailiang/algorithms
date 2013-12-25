#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows); 
int main(){
  vector<vector<int> > a =  generate(1);
  for(int i=0;i<a.size();i++) {
      for(int j=0;j<a[i].size();j++){
	cout<<a[i][j]<<" ";
      }
      cout<<endl;
  }
  return 1;
}
vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vt;
        int n;
        if(numRows == 0) return vt;
        vt[0].push_back(1);
        if(numRows == 1) return vt;
        for(int m=1;m<=numRows;m++){
            vt[m].push_back(1);
            for(n=1;n<numRows-1;n++){
                vt[m].push_back(vt[m-1][n-1]+vt[m-1][n]);
            }
            vt[m].push_back(1);
        }
        return vt;
 }
