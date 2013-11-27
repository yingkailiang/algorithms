  import java.util.Scanner;
import java.io.*;

public class fact
{
 //precondition
 int y =1;
 int z =0;

 //function compute y=z!
 public int inv(int n) 
 {
  if(n==0)
   return 1;
  else 
   return n*inv(n-1);  
 }  //end func factorial 
 
 //invariant :  y=z! 
 //postcondition : y=n! ,z=n
 public int factorial(int n)
 {

 //test precondition satisfy invariant 
  int tv =this.inv(z);
  assert y==tv : "precondition does not satisfy invariant";  

  while(z != n)
  {
   z =z+1;
   y =y*z;
  }//end loop
  //check postcondition after loop
  assert !this.controlB(n,z):"control flow n= z";
  return y;
 }//end func invariant 
  
 //test factorial controlflow : B: n >=0
 private boolean controlB(int n,int z)
 {
  return n!=z;
 }//end func controlB 

 //test factorail  
 public static void main(String[] args)
 {
  Scanner reader = new Scanner(System.in);
  System.out.print("Please Input number:");

  int x = reader.nextInt();
  fact f =new fact();
  int a =f.factorial(x);
  int b =f.inv(x);

  //test invariant holds
  assert a==b : "y is not equal to z!";
  System.out.println(x+"!="+a);
  
 }//end func main 
} //end class fact
