/*
  problem: reverse the string 
 
  approach: first reverse every word. Second reverse the whole string 

  Analysis: traverse whole string twice T=O(n) space =O(1) 
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

  void reverse(char* start, char* end); 
  void reverseSentence(char* str) {
   char* end =str; 
   char* p=str;
   char* q=str; 
   while(*end){
    end++;
   }
   end--;
   while(p<end) {
     if(*q == ' ') {
      reverse(p,q);
      p=q;
     } 
     q++;
   }
  }

  void reverse(char* start, char* end) {
    char tmp;
    while(start<end){
     tmp= *start; 
     *start++ = *end; 
     *end-- = tmp;
    }
  }

  int main() {
    char str[] = "a b";   
    reverseSentence(str);
    cout<<str<<"\n";
    return 1;
  }

