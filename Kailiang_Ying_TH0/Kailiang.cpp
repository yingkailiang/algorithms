#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
//////////////////////////////////////////////////////////////////////////
//ValidIntInput
//
//Describe: getline a valid input int number other wise input again
//
//input:   none 
//
//return:  int input 
///////////////////////////////////////////////////////////////////////////
int ValidIntInput()
{
  string input="";
  bool done =false; 
  int temp;
  while (!done)
  {
    getline(cin,input);
    stringstream mystream(input);
    
    if (mystream>>temp)
    {
     done =true;
     return temp;
    }
    else 
    {
     cout<<"Your input is invalid ,please type agagin: ";
     continue;
    }
  }
}  //end func ValidIntInput

///////////////////////////////////////////////////////////////////////////
//ValidDoubleInput
//
//Describe: getline a valid input double number other wise input again
//
//input:   none 
//
//return:  double input 
///////////////////////////////////////////////////////////////////////////
double ValidDoubleInput()
{
  string input="";
  bool done =false; 
  double temp;
  while (!done)
  {
    getline(cin,input);
    stringstream mystream(input);
    
    if (mystream>>temp)
    {
     done =true;
     return temp;
    }
    else 
    {
     cout<<"Your input is invalid ,please type agagin: ";
     continue;
    }
  }
}  //end func ValidDoubleInput

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
//           return maximun of tempary[i] or tempary[n] 
//           i from 0 to n-1 
//
//intput:    double tempary[]  :store the post optimun possibility 
//           int length
//           int & ith
//
//output:    int & ith
//
//return:    double the maximun element in p[] 
////////////////////////////////////////////////////////////////////////////
double Maximun(double tempary[],int length,int & ith)
{
   //store the tempary result 
   double temp=tempary[length];   

   //store optimun result
   ith=0;

   //compare one n time  
    for (int j=0;j<length;j++)
    {
      //get one time operation probability
      if (temp<tempary[j]) 
       {
       temp =tempary[j];
       ith =j; 
       }
    } 
    if (temp==tempary[length])
     ith =length; 
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
  double temp;
  for (int i=0;i<n;i++)
  {
   temp=Probability(r[i],m[i]);
   _P *=temp;
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
//EnumCi
//
//Describe: enum P(C-k*ci,post[C-k*ci]{mi +k}) and return the maximun between  P(C-k*ci,post[C-k*ci]{mi +k}) and P
//          k from 1 to LowerInt (C/ci)
//          use dynamic program
//
//input:    int ith: the index of c[ith]
//          double r[]: the possibility of a device function properly 
//          int c[] :cost of a device 
//          double temparyC[] : store the tempary result for P(C-k*ci,postM[C-k*ci]{mi +k})
//          double P          : store the current TotalP(m,r,n)
//          int C  : cost constraint 
//          int n  : number of device 
//          int **postM  : store the post solution in order to track back
//          int &No  : store the optimum C-k*ci
//          int &k   : store the optimum k
//
//output:   int &No  : store the optimum C-k*ci
//          int &k   : store the optimum k
//
//return :  double the maximun of P(C-k*ci,postM[C-k*ci]{mi +k}) or P(C,M) 
////////////////////////////////////////////////////////////
double EnumCi(int ith,double r[],int c[],double temparyC[],double P,int C,int n,int **postM,int &No,int &k)
{
	int multi =1;
	while((C-multi*c[ith])>=0)
	{
		//enum every possible C-k*ci situation 
		//if is under cost constraint ,then add to temparyC
		postM[C - multi*c[ith]][ith] +=multi;
		if (CheckCost(postM[C - multi*c[ith]],c,n,C))
		{
			temparyC[multi-1] = TotalP(postM[C - multi*c[ith]],r,n);
		}
		else 
		{
			temparyC[multi-1] = 0;
		}
		postM[C - multi*c[ith]][ith] -=multi;
		multi++;
	}  //end while

	temparyC[C] = P;
	double temp;
	temp= Maximun(temparyC,C,k);
	
	//output the k 
	if(k==C)
	{
		k=0;
		No=C;
	}  
	else
	{
		//for k start from 0 ,so need to add one 
		No =C-(k+1)*c[ith];
		k +=1;
	}

   return temp;	
}  //end func EnumCi

//////////////////////////////////////////////////////////
//Optimun
//
//Describe: define P(C)=max[P(C-K*ci,M*{postM[C-k*ci][i]+k});P(C,M)]
//          i from 1 to n
//          k from 1 to LowerInt(C/ci)
//          use dynamic program
//
//input:    int m[] :store the current solution
//          double r[]: the possibility of a device function properly 
//          int c[] :cost of a device 
//          double P[] :store the optimun possibility
//          double temparyN[N+1] : store the tempary result for maximun[P(C-K*ci,M*{postM[C-k*ci][i]+k})]
//          double temparyC[C+1] : store the tempary result for totalP(M*{postM[C-k*ci][i]+k},c,n) and current P(C,M)
//          int C  : cost constraint 
//          int n  : number of device 
//          int **postM  : store the post solution in order to track back  
//          int address[C+1]: store n optimum C-k*ci (i from 0 to n) and current C
//          int multi[n] : store n optimum k
//
//output:   int m[] :store the current solution
//          int P[] :store the optimun possibility
//          int **postM  : store the post solution in order to track back  
//
//return :  double P[n-1] : the optimun possibility 
//
//parameter:int No : store the optimun C -k*ci
//          int k  : store the optimun k
//            
//           
////////////////////////////////////////////////////////////
double Optimun(int m[],double r[],int c[],double P[],double temparyN[],double temparyC[],int C,int n,int **postM,int address[],int multi[])
{
  //to get the post solution 
  int No;
  int k;
  
  for (int i =0;i<=C;i++)
  {
    if(CheckCost(m,c,n,i))
    {
      P[i]=TotalP(m,r,n);      
      for (int j=0;j<n;j++)
      {
		  temparyN[j] =EnumCi(j,r,c,temparyC,P[i],i,n,postM,No,k);
		  //store  C-k*ci
		  address[j]=No;
		  //store  k
		  multi[j]=k;
      }  //end for 

	  //store current cost constraint 
      address[n]=i;

      int ith=0; 
	  temparyN[n]=P[i];
      P[i] =Maximun(temparyN,n,ith);

      //just the current solution 
      if(ith==n)
      {
       CopyArray(m,postM[i],n);
      } //end if  

      //ith is c[ith] 
      else 
      { 
        //copy postM[address[ith]] to m
		  CopyArray(postM[address[ith]],m,n);
		  m[ith] += multi[ith];
		  CopyArray(m,postM[i],n);
      } //end else

    } //end if

    //if checkcost is false 
    else 
    {
     P[i] =0;
     CopyArray(m,postM[i],n);
    }
  }  //end for
  
  return P[C]; 
}  //end func Optimun

void testDrive()
{
  //parameter:

  //number of modules
  int N;
  
  cout<<"Please input the number of device: ";
  N =ValidIntInput(); 
  cout<<endl;

  //cost constraint 
  int C;
  cout<<"please input the cost constraint: ";
  C =ValidIntInput();
  cout<<endl;
  
  //cost of a Di
  int *c;
  c =(int*)malloc(sizeof(int)*N);  
  cout<<"Please input the cost of each device: "<<endl;
  //let user input the ci 
  for (int i =0; i<N; i++)
  {
   cout<<"c["<<i+1<<"]= ";
   c[i] = ValidIntInput();
   cout<<endl;
  } //end for  
 
  //probability Di function properly 
  cout<<"Please input the probability for each device to work properly: "<<endl;
  double *r;
  r =(double*)malloc(sizeof(double)*N);
  //let user input the ri 
  for (int i =0; i<N; i++)
  {
   cout<<"r["<<i+1<<"]= ";
   r[i] = ValidDoubleInput();
   cout<<endl;
  } //end for  
   
  //store the solution 
  int *m; 
  m=(int*)malloc(sizeof(int)*N);
  //initial all value one 
  for (int i=0;i<N; i++)
  {
    m[i]=1;
  }  //end for 

  //store the post solution of each maximun ci
  double *temparyN;
  temparyN =(double*)malloc(sizeof(double)*(N+1));

  //initial all value zero 
  for (int i=0;i<N+1;i++)
  {
   temparyN[i]=0;
  }

//store the post solution of each maximun ci
  double *temparyC;
  temparyC =(double*)malloc(sizeof(double)*(C+1));

  //initial all value zero 
  for (int i=0;i<C+1;i++)
  {
   temparyC[i]=0;
  }

  //store the tempary answer for C-ci
  int *address;
  address =(int*)malloc(sizeof(int)*(C+1));

  //store the tempary k for optimum C-k*ci
  int *multi;
  multi =(int*)malloc(sizeof(int)*(N));
  //tempary parameter only to store possible solution 
  int **postM;
  
  //dynamic allocate the memory and initial tempary to oneo
  postM =(int**)malloc(sizeof(int*)*(C+1));
  for (int i=0;i<(C+1);i++)
  {
   *(postM+i) =(int*)malloc(sizeof(int)*N);
  }
  for (int i=0;i<(C+1);i++)
   for (int j=0;j<N;j++)
   {
    postM[i][j]=1;
   }  

  //int p[] to the optimun possibility
  double *P; 
  P =(double*)malloc(sizeof(double)*(C+1)); 
  //initial all value zero
  for (int i =0;i <(C+1);i++)
  {
   P[i]=0;
  }  //end for
////debug
//  const int N2 =4;
//  const int C2 =30;
//
//  int m2[N2]={1,1,1,1};
//  double r2[N2]={0.9,0.8,0.6,0.85};
//  int c2[N2]={3,5,2,4};
//  double temparyN2[N2+1]={0};
//  double temparyC2[C2+1]={0};
//  int address[C2+1]={0};
//  int multi[N2];
//  for(int i =0;i<N2;i++)
//	  multi[i]=1;
//  int **postM2;
//  postM2 =(int**)malloc(sizeof(int*)*(C2+1));
//  for (int i=0;i<C2+1;i++)
//	  *(postM2+i)=(int*)malloc(sizeof(int)*N2);
//  for(int i=0;i<C2+1;i++)
//	  for(int j=0;j<N2;j++)
//		  postM2[i][j]=0;
//  double P2[C2+1]={0};
////end debug
 
  Optimun(m,r,c,P,temparyN,temparyC,C,N,postM,address,multi);
 
  //display the result 
  for (int i=0;i<=C;i++)
  {
   cout<<"P["<<i<<"] :"<<P[i]<<"     ";
    cout<<"postM["<<i<<"] : ";
   for (int j=0;j<N;j++)
    cout<<postM[i][j]<<" ";
   cout<<endl;
  }
   cout<<endl;
  
  //display the optimun solution 
  for (int j=0;j<N;j++)
  {
    cout<<"m["<<j<<"] :"<<m[j]<<"   ";
  } 
   cout<<endl; 

  //display the optimun solution 
  for (int j=0;j<N;j++)
  {
    cout<<"u["<<j<<"] :"<<MaxU(j,c,N,C)<<"   ";
  } 
   cout<<endl; 
 
  //free the memory
  for(int i=0;i<C+1;i++)
  {
   free(*(postM+i));
  }
  /*free(tempary);
  free(m);
  free(r);
  free(c);
  free(P);*/
}  //end func testDrive

// program excute from here
int main()
{
 testDrive();
 return 1;
}  //end func main
