#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode *deleteDuplicates(ListNode *head); 
int main()
{
 ListNode *a = new ListNode(1);
 ListNode *b = new ListNode(1);
 ListNode *c = new ListNode(1);
 a->next=b;
 deleteDuplicates(a);
 ListNode *ptr = a;
 while(ptr) {
  cout<<ptr->val;
  ptr=ptr->next;
 }
 cout<<"\n";
return 1;
}
 ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast) {
            if(slow->val != fast->val) {
                fast = fast->next;
                slow = slow->next;
            } else {
                ListNode *t = fast;
                fast=fast->next;
                slow->next=fast;
                delete t;
            }
        }
        return head;
    }
