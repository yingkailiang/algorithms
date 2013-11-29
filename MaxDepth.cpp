#include <iostream>

using namespace std;

struct TreeNode {
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class stack{
   struct TreeNode * top;
   public:
     stack();
     void push(int);
     int pop();
     bool isEmpty();
     void display();
};

stack::stack() {
   top = NULL;
} 

void stack::push(int data) {
   TreeNode *p;
   if((p=(TreeNode*)malloc(sizeof(TreeNode)))==NULL) {
	cout<<"memory exhausted";
        exit(0);
    }
   p = new TreeNode(0);
   
} 
int pop() {

}
 
bool isEmpty() {

}
class Solution 
{


int DFS(TreeNode *root) {
 if (root==NULL) return 0;
 int maxDepth=0;
  
 }
};
