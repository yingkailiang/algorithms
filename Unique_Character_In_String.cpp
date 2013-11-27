#include <iostream>

/*
  problem: 
  assume input is only little charater a~z, find out if string is unique or not     

  approach:
  use hash table to store 26 character, 
  if first enter, increase count by 1,
  if second enter same position, return false ,else return true

  complexity: 
  T=O(n)
  space=O(n)
*/
using namespace std;

bool checkUnique(char* str,int len);

int main()
{
 if(checkUnique("world",5))
   cout << "this is unique string \n";
 else 
   cout << "this is duplicate string \n";
    
 return 0; 
}

bool checkUnique(char* str,int len)
{
  int asc[26]={0};  
  int tmp;
  for(int i=0;i<len;i++) {
    tmp = str[i] -'a'; 
    asc[tmp]++;
    if(asc[tmp]>1)
     return false;
  } 
  return true;
}
