import java.io.*;

//data structure :stack using link list
public class MyStack
{
 private Node first;
 private int N;//whether N is initial 0 ??
 
 //inner class Node
 private class Node
 {
   int item;
   Node next;
 }//end class Node

 //check whether stack is empty 
 public boolean isEmpty()
 {
  return first==null;
 }//end func isEmpty 

 //return the size of stack
 public int size()
 {
  return N;
 }//end func size 

 //pop item from stack 
 public int pop()
 {
  //pop preconditon 
  assert isEmpty(): "The stack is empty";
  int item =first.item;
  first =first.next;
  N--; 
  //pop post condition  
  assert inv(): "the size of stack is disqualified";
  return item;
 }//end func pop

 //push item into stack 
 public void push(int item)
 {
  assert inv(): "the size of stack is disqualified";
  Node oldfirst =first;
  first =new Node();
  first.item= item;
  first.next=oldfirst; 
  assert inv(): "the size of stack is disqualified";
  N++;
 }//end func push 
 
 //test the size of stack is greater than zero 
 private boolean inv()
 {
  return (this.size() >=0); 
 }//end func inv

//test main function
public static void main(String[] args)
{
  MyStack s =new MyStack();
  //insert 5 number test push
  for(int i=0;i<5;i++)
  {
   s.push(i);  
  }

  //test pop()
  for(int i=0;i<5;i++)
  {
   System.out.println(s.pop());
  }

}//end func main

}//end class MyStack 
