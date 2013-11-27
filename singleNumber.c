/*
 bitwise operation :
 1100 xor 1110 = 0010
 eg: 
   001
   011
   011
   001
   100
--------
   100 
*/

#include <stdio.h> 

int main()
{
 int one=2; 
 int two =1;
 int three =1;
 int ot=0;
 ot = ot ^ one; 
 printf("%d \n",ot);
 ot = ot ^ two; 
 printf("%d \n",ot);
 ot = ot ^ three; 
 printf("%d \n",ot);
 return 0;
}
