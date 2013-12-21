#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode *root); 
int main()
{
 TreeNode *a = new TreeNode(1);
 TreeNode *b = new TreeNode(2); 
 TreeNode *c = new TreeNode(3);
 a->left= b;
 a->right = c;
 vector<int> vt = inorderTraversal(a);
 for (vector<int>::iterator i = vt.begin();i!=vt.end();i++) {
     cout<< *i <<endl;    
 }
 return 1;
}
//code simple but not effcient 
vector<int> inorderTraversal(TreeNode *root) { //BFS
        vector<int> inorderlist;
        TreeNode *current=root;
        stack<TreeNode*> s;
        while (!s.empty() || current) {
          if (current) {
             s.push(current);
             current = current->left;
           } else {
              current = s.top();
              s.pop();
              inorderlist.push_back(current->val);
              current = current->right;
           }
     }
      return inorderlist;
 }

