/*
  problem: reverse the string 
 
  approach: first reverse every word. Second reverse the whole string 

  Analysis: traverse whole string twice T=O(n) space =O(1) 
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

  void reverse(char* str) {
   char tmp;
   char* end =str;

   while(*end) {
     end++;
   }
   end--;

   while(str<end) {
      tmp = *str;
      *str++= *end;
      *end--= tmp;    
   } 
  }

  void testPrint(char* start, char* end) {
    char tmp;
    while(start<end){
     tmp= *start; 
     *start++ = *end; 
     *end-- = tmp;
    }
  }

  int main() {
    char str[] = "12345";   
    testPrint(str,str+4);
    cout<<str<<"\n";
    return 1;
  }

