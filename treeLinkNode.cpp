#include <iostream>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

void connect(TreeLinkNode *root); 
int main()
{
 TreeLinkNode *a = new TreeLinkNode(1);   
 connect(a);
 return 1;
}
void connect(TreeLinkNode *root) {
        if(root) {
            if(root->left){
                root->left->next = root->right;
                if(root->left->right)
                    root->left->right->next = root->right->left;
            }
            if(root->left)
                connect(root->left);
            if(root->right)
                connect(root->right);
        }
    }
