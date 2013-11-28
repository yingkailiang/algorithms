#include <iostream>

using namespace std;

struct TreeNode {
    int val; 
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int main()
{

 return 1;
}
 
class Solution 
{
int maxDepth(TreeNode *root) {
 if (root==NULL) return 0;
 stack<TreeNode*> s;  /* use stack to store DFS */ 
 s.push(root);
 int maxDepth=0;
  
 }
};
