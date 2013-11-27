#include <iostream>
#include <cstdlib>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//Probability
//
//Describe:  calculate probability the divice Di run properly
//           p= 1-(1-r)^m
//
//input :    int r the probability that device Di function properly 
//           int m the number of Device Di
//return:    double probability that m Di will run properly 
////////////////////////////////////////////////////////////////////////////
double Probability(double r,int m)
{
  double temp=1;
  for (int i=0 ;i <m;i++)
  {
   temp *= (1-r);
  } //end for  
  
  return 1-temp;
}  //end func Probability


///////////////////////////////////////////////////////////////////////////
//LowerInt
//
//Describe:  get ground of a real number 
//
//input :    double x
//return:    int lower[x]
////////////////////////////////////////////////////////////////////////////
int LowerInt(double x)
{
  int a =static_cast<int>(x);
  return a;
}  //end function LowerInt 


///////////////////////////////////////////////////////////////////////////
//Sum
//
//Describe:  get the sum of n ci  
//
//intput:    int c[]
//           int n 
//return:    int sum(c[i]) i from 0 to n-1
////////////////////////////////////////////////////////////////////////////
int Sum(int c[],int n)
{
  int temp=0;
  for (int i =0;i<n;i++)
  {
    temp += c[i];
  }  //end for  

  return temp;
}// end func Sum

///////////////////////////////////////////////////////////////////////////
//Sum
//
//Describe:  get the sum of n ci*mi  
//
//intput:    int c[]
//           int m[]
//           int n 
//return:    int sum(c[i]) i from 0 to n-1
////////////////////////////////////////////////////////////////////////////
int Sum(int c[],int m[],int n)
{
  int temp=0;
  for (int i =0;i<n;i++)
  {
    temp += c[i]*m[i];
  }  //end for  

  return temp;
}// end func Sum

///////////////////////////////////////////////////////////////////////////
//MaxU
//
//Describe:  calculate the max of mi
//           U = LowerInt[ ( C + ci - sum(cj) ) / ci ] 
//
//input :    int ith the i th Di  (the realistic number start from 0)
//           int c[] the cost of a Di
//           int n   number of modules 
//           int C  cost constraint
//return:    int probability that m Di will run properly 
////////////////////////////////////////////////////////////////////////////
double MaxU(int ith,int c[],int n ,int C)
{
  double temp;
  temp = (C +c[ith] -Sum(c,n) ) / c[ith]; 
  
  return LowerInt(temp); 

}  //end func MaxU

///////////////////////////////////////////////////////////////////////////
//CheckM
//
//Describe:  check whether mi has exceed the bound ui 
//           1<= mi <= ui
//
//input :    int ith the i th Di (start from 0) 
//           int c[] the cost of a Di
//           int n   number of modules 
//           int C  cost constraint
//           int mi current ith solution 
//return:    true if with in the bound other wise false  
////////////////////////////////////////////////////////////////////////////
bool CheckM(int ith,int c[],int n,int C,int mi)
{
   if(mi>MaxU(ith,c,n,C))
   {
     return false;
   } 
   if(mi<1)
   {
     return false;
   }
   
   return true;
}  //end func CheckM


///////////////////////////////////////////////////////////////////////////
//Maximun
//
//           return maximun of tempary[i]*Probability(i) or tempary[n] 
//           i from 0 to n-1 
//
//input:     int m[] : current solution
//           double tempary[]  :store the post optimun possibility 
//           double r[]  : possibability of a device functon properly 
//           int length
//           int & ith
//
//output:    int & ith
//
//return:    double the maximun element in p[] 
////////////////////////////////////////////////////////////////////////////
double Maximun(int m[],double tempary[],double r[],int length,int & ith)
{
   //store the tempary result 
   double temp=tempary[length];   
   
   //store optimun result
   ith=0;

   //compare one n time  
    for (int j=0;j<length;j++)
    {
      double prp =Probability(r[j],m[j]);
      if (temp<tempary[j]*prp) 
       {
       temp =tempary[j]*prp;
       ith =j; 
       }
    } 
    
   return temp;
}  //end func Maximun

///////////////////////////////////////////////////////////////////////////
//CheckCost
//
//Describe:  check whether total cost exceed C  
//           and check every mi is include [1,ui] 
//
//intput:    int m[]  store the solution 
//           int n
//           int c[] 
//           int C
//
//return:    true if with in the cost constraint other wise false 
////////////////////////////////////////////////////////////////////////////
bool CheckCost(int m[],int c[],int n,int C)
{
   int _sum=0;
   _sum=Sum(m,c,n); 
   
   //check mi is include [1,ui]
   for (int i =0;i<n;i++)
   {
     if(!CheckM(i,c,n,C,m[i]))
     {
       return false;
     }
   }
   if(_sum<=C && _sum>=0)
   {
    return true;
   }
   else 
    return false;
}  //end func CheckCost 

///////////////////////////////////////////////////////////////////////////
//TotalP
//
//Describe:  Calculate the probability that all Devices will function properly   
//
//intput:    int m[]  store the solution 
//           double r[] 
//           int n 
//
//return:    double P  : the probability 
////////////////////////////////////////////////////////////////////////////
double TotalP(int m[],double r[],int n )
{
  double _P=1;
  for (int i=0;i<n;i++)
  {
   _P *=Probability(r[i],m[i]);
  }
  
  return _P;

}  //end func TotalP

///////////////////////////////////////////////////////////////////////////
//CopyArray
//
//Describe:  copy one array to another 
//
//intput:    int x[]   
//           int copyx[] 
//           int length 
//
//return:    none 
////////////////////////////////////////////////////////////////////////////
void CopyArray(int x[],int copyx[],int length)
{
  for (int i =0;i<length;i++)
  {
    copyx[i]=x[i]; 
  }
}//end func CopyArray

//////////////////////////////////////////////////////////
//Optimun
//
//Describe: define P(C)=max[P(C-ci)*Probability(i);P(C-1)]
//          i from 1 to n
//          use dynamic program
//
//input:    int m[] :store the current solution
//          double r[]: the possibility of a device function properly 
//          int c[] :cost of a device 
//          double P[] :store the optimun possibility
//          double tempary[] : store the tempary result 
//          int C  : cost constraint 
//          int n  : number of device 
//          int **postM  : store the post solution in order to track back  
//
//output:   int m[] :store the current solution
//          int P[] :store the optimun possibility
//          int **postM  : store the post solution in order to track back  
//
//return :  double P[n-1] : the optimun possibility 
////////////////////////////////////////////////////////////
double Optimun(int m[],int r[],int c[],double P[],double tempary[],int C,int n,int **postM){
  //to get the post solution 
  int ith=0; 
  
  for (int i =0;i<C;i++)
  {
    if(CheckCost(m,c,n,i))
    {
      for (int j=0;j<n;j++)
      {
        tempary[j] = P[i-c[j]];
      }  //end for 
      //if ith == n ,then is the solution is the same with i-1  
      tempary[n] =P[i-1];
      
      P[i] =Maximun(m,tempary,r,n+1,ith);
      //CopyArray(postM[i-c[ith]]
    } //end if
  }  //end for
   
}  //end func Optimun

void testDrive()
{
  //parameter:

  //number of modules
  const int N =4;

  //probability Di function properly 
  double r[N]={0.9,0.8,0.6,0.85};
  
  //cost of a Di
  int c[N]={3,5,2,4};
  
  //cost constraint 
  const int C=30;
  
  //store the solution 
  int m[N]={1,1,1,1}; 

  //store the post solution
  int tempary[N+1]={1,1,1,1};

//debug
int m2[N]={1,1,1,1};
double T2 ={0.3,0.5,0.6,0.7,0.5}
int ith2;
//cout<<"P:"<<TotalP(m2,r,N)<<endl;

//test Maximun
cout<<Maximun(m2,T2,r,5,ith2)<<endl;
cout<<"ith:"<<ith2<<endl;
// end debug  

  //tempary parameter only to store possible solution 
  int **postM;
  
  //dynamic allocate the memory and initial tempary to zero
  postM =(int**)malloc(sizeof(int*)*(C+1));
  for (int i=0;i<(C+1);i++)
  {
   *(postM+i) =(int*)malloc(sizeof(int)*N);
  }
  for (int i=0;i<(C+1);i++)
   for (int j=0;j<N;j++)
   {
    postM[i][j]=0;
   }  

  //int p[] to the optimun possibility
  int _P[C+1]; 
  

/*
  //display the result 
  for (int i=0;i<=C;i++)
  {
   cout<<"C["<<i<<"] :"<<_P[i]<<"   ";
  }
   cout<<endl;
  
  //display the optimun solution 
  for (int j=0;j<N;j++)
  {
    cout<<"m["<<j<<"] :"<<m[j]<<"   ";
  } 
   cout<<endl; 
*/

  //free the memory
  for(int i=0;i<C+1;i++)
  {
   free(*(postM+i));
  }
}  //end func testDrive

// program excute from here
int main()
{
 testDrive();
 return 1;
}  //end func main
