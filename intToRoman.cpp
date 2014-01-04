#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num); 
int main()
{
 cout<<intToRoman(1212)<<endl;
 return 1;
}
string intToRoman(int num) {
        string str;
        int intnum[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int i= 0;
        while(num>0){
            for(int times = num/intnum[i];times>0;--times){
                str += roman[i];
                num -=intnum[i];
            }
            i++;
  }
        return str;
    }
