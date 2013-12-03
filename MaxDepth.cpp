/*
  problem: give binary tree, find max depth 
  
  approach: DFS to get leaf of tree and compute the max depth
            the reason to use this is because stack only store number of 
            node in one branch is the depth 
           
            start from left to search right, will never duplicate 
            
            use extra data structure stack to store visited nodes instead of using flag to record visited 
  
  anylysis: T=O(E) space=O(V)
*/
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/*
 * non-recursive sulotion 
 */

int DFS(TreeNode *root) {

 if (root==NULL) return 0;
 stack<TreeNode*> s;
 int maxDepth=0;
 s.push(root); 
 TreeNode *prev =NULL;

 while(!s.empty()) {
  TreeNode *curr = s.top();
  if(!prev || prev->left == curr || prev->right ==curr) { // is child node of current node
    if(curr->left)
      s.push(curr->left); 
    else if(curr->right)
      s.push(curr->right);
   } else if (curr->left == prev) { //return from child node and continue search right node 
     if (curr->right)
       s.push(curr->right);
   } else {
     s.pop();
   } 
   prev = curr;
   if(s.size() > maxDepth)
     maxDepth = s.size();
  }

  return maxDepth;
 }

/*
 * recursive DFS
 */
TreeNode *prev= NULL;
int maxDepth=0;
int depth=1;
int DFSR(TreeNode *curr){
  if(!curr && maxDepth==0)
    return 0;
  if(!prev || prev->left==curr || prev->right==curr) {
    if(curr->left){
      DFSR(curr->left);
        depth++; 
      if(depth > maxDepth)
        maxDepth = depth; 
   }
    if (curr->right) {
      DFSR(curr->right);
      depth++; 
      if(depth > maxDepth)
        maxDepth = depth; 
   } 
  } else if(curr->left == prev) {
     if(curr->right) {
     DFSR(curr->right);
        depth++;
     if(depth > maxDepth)
        maxDepth = depth; 
    }
  } else {
     depth--;
  }
  prev= curr; 
   if(depth > maxDepth)
     maxDepth = depth; 

 return maxDepth; //??how recursive func return value, have not fully recursive find out 
                  //terminate point of recursive   
}


int main() {
  TreeNode *a;
  TreeNode *b;
  TreeNode *c;
  TreeNode *d;
  TreeNode *e;
  
  a= new TreeNode(1);
  b= new TreeNode(2);
  c= new TreeNode(3);
  d= new TreeNode(4);
  e= new TreeNode(5);

  a->left=b;
  a->right=c;
  c->left=d;
  c->right=e;
  

  cout<<"Max depth: "<<DFSR(a)<<"\n";
return 1;
}


