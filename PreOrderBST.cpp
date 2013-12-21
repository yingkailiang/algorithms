#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
vector<int> preorderTraversal(TreeNode *root); 
int main(){
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(1);
    TreeNode *c = new TreeNode(2);
    a->left = b;
    a->right= c;
    vector<int> vt = preorderTraversal(a);  
    for(vector<int>::iterator i=vt.begin();i!=vt.end();i++) {
        cout<< *i <<endl; 
    }
    return 1;
}

vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorderlist;
        if(!root) return preorderlist;
        stack<TreeNode*> s;
        TreeNode *prev = NULL;
        s.push(root);
        preorderlist.push_back(root->val);
        while(!s.empty()){
            TreeNode *cur = s.top();
            if(!prev || prev->left==cur || prev->right==cur){
                if(cur->left){
                    s.push(cur->left);
                    preorderlist.push_back(cur->left->val);
                }else if(cur->right){
                    s.push(cur->right);
                    preorderlist.push_back(cur->right->val);
                }
            }else if(cur->left==prev){
                if(cur->right){
                    s.push(cur->right);
                    preorderlist.push_back(cur->right->val);
                }
            }else {
                s.pop(); 
            }
            prev = cur;
        }
      return preorderlist;
    }

