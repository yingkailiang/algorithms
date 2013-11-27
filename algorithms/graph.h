#include <iostream>
using namespace std;

class graph
{
public:
////////////////////////////////////////////
//constructor
//describe:initial the graph matrix  
//input: int dimension
//return: 
////////////////////////////////////////////
graph(int dimension);

////////////////////////////////////////////
//SetLength
//describe:set matrix (x,y) length 
//input : int x ,int y ,int length
//return: true if set success
////////////////////////////////////////////
bool SetLength(int x,int y,int length);


////////////////////////////////////////////
//GetLength
//describe:get matrix (x,y) length 
//input : int x ,int y
//return: int length
////////////////////////////////////////////
int GetLength(int x,int y);

////////////////////////////////////////////
//CheckOutBound
//describe:check input is out of dimension 
//         or not  
//input : int x 
//return: true if x<dimension other wise false  
////////////////////////////////////////////
bool CheckOutBound(int x);


private:
//the matrix dimension
int _dimension;

//two dimensional matrix to store node and edge length 
//if have edge should have length
//else length equal to INT_MAX
int **matrix;

};  //end class graph

//<---------------------------------------------------------------------->



////////////////////////////////////////////
//constructor
//describe:initial the graph matrix  
//input: int dimension
//return: 
////////////////////////////////////////////
graph::graph(int _dimension)
:dimension(_dimension)
{
  //initial the matrix by _dimension*_dimension size
  *matrix =new int[_dimension];  

  for (int i=0;i<_dimension;i++)
  {
   matrix[i] =new int[_dimension];
  }

}  //end func graph

////////////////////////////////////////////
//SetLength
//describe:set matrix (x,y) length 
//input : int x ,int y ,int length
//return: true if set success
////////////////////////////////////////////
bool graph::SetLength(int x,int y ,int length)
{
 if (CheckOutBound(x) && CheckOutBound(y))
 {
  matrix[x][y]=length;
  return true;   
 } 
 else 
  return false;
}  //end func SetLength 

////////////////////////////////////////////
//GetLength
//describe:get matrix (x,y) length 
//input : int x ,int y
//return: int length
////////////////////////////////////////////
int graph::GetLength(int x,int y)
{
  if(CheckOutBound(x),CheckOutBound(y))
   return matrix[x][y]; 
}  //end func GetLength

////////////////////////////////////////////
//CheckOutBound
//describe:check input is out of dimension 
//         or not  
//input : int x 
//return: true if x<dimension other wise false  
////////////////////////////////////////////
bool graph::CheckOutBound(int x)
{
  if (x>=0 && x<dimension )
    return true;
  else
    return false;

}  //end func CheckOutBound  
