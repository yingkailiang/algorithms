#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
bool isSameTree(TreeNode *p, TreeNode *q); 
bool isSameTree2(TreeNode *p, TreeNode *q); 

int main(){
 TreeNode *a = new TreeNode(1);
 TreeNode *b = new TreeNode(1);
 TreeNode *a2 = new TreeNode(2);
 TreeNode *b2 = new TreeNode(2);
 TreeNode *a3 = new TreeNode(3);
 TreeNode *b3 = new TreeNode(3);

 a->right=a2;
 a2->left =a3;

 b->right = b2;
 b2->right = b3;

 if(isSameTree2(a,b)) cout<<"Is same tree \n";
 else cout<<"Not same tree\n"; 
 return 1;
}

bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        stack<TreeNode*> s;
        TreeNode *prev1= NULL;
        TreeNode *prev2= NULL;
        s.push(p);
        s.push(q);
        
        while(!s.empty()) {
            TreeNode *cur1 =s.top();
            s.pop();
            TreeNode *cur2 =s.top();
            s.pop();

            if(cur1->val != cur2->val) return false;
            if((!prev1 && !prev2) || (prev1->left == cur1 && prev2->left == cur2) || (prev1->right == cur1 && prev2->right == cur2)){
                if(cur1->left ){
                    if (cur2->left) {
                        s.push(cur1->left);
                        s.push(cur2->left);
                    } else return false;
                } else if(cur1->right){
                     if(cur2->right) {
                        s.push(cur1->right);
                        s.push(cur2->right);
                     } else return false;
                }
            } else if(cur1->left == prev1 && cur2->left == prev2) {
                if(cur1->right){
                    if(cur2->right){
                    s.push(cur1->right);
                    s.push(cur2->right);
                    } else return false;
                 }
            } 
            prev1 = cur1;
            prev2 = cur2;
        }
        return true;
    }
    bool isSameTree2(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL && q != NULL) return false;
        else if(p != NULL && q == NULL) return false;
        else if(p->val == q->val) return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        else return false;
    }

