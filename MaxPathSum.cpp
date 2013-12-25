#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int maxPathSum(TreeNode *root); 
void maxBSF(TreeNode *root,int &cur,int& value);
int main()
{
 TreeNode *a = new TreeNode(0);
 cout<< maxPathSum <<endl;
 return 1;
}
int maxPathSum(TreeNode *root) {
        int maximum;
        int cur;
        if(root){
           maximum = root->val;
           cur = root->val;
        }
        else return 0;
        maxBSF(root,cur,maximum);
        return maximum;
    }
    void maxBSF(TreeNode *root,int &cur,int& value){
        if(!root) {cur = 0; return;}
        int ls=0;
        int rs=0;
        maxBSF(root->left,ls,value);
        maxBSF(root->right,rs,value);
        cur = max(max(root->val + ls,root->val +rs),root->val);
        value = max(value,max(cur,root->val + rs +ls));
    }
