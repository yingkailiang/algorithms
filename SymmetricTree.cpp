#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSym(TreeNode* left, TreeNode* right);
bool isSymmetric(TreeNode *root); 
int main()
{
 TreeNode *a = new TreeNode(1);
 TreeNode *b = new TreeNode(2);
 TreeNode *c = new TreeNode(3);  
 a->left = b;
 a->right = c;
 if(isSymmetric(a)) cout<<"is symmetric"<<endl;
 else cout<<"not symmetric"<<endl;
 return 1;
}

bool isSymmetric(TreeNode *root) {
        if(root== NULL) return true;
        return isSym(root->left,root->right);
    }
bool isSym(TreeNode* left, TreeNode* right){
        if(!left) return (!right);
        if(!right) return (!left);
        if(left->val != right->val) return false;
        if(!isSym(left->left,right->right)) return false;
        if(!isSym(left->right,right->left)) return false;
        return true;
 }
