#include <iostream>
using namespace std;

int main(){
  int ret = 0x01<<2;
  ret = ret^2;
  cout<<ret<<endl;
  return 1;
}
