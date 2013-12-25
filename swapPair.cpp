#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *swapPairs(ListNode *head); 
int main(){

 ListNode *a = new ListNode(1);
 ListNode *b = new ListNode(2);
 ListNode *d = new ListNode(3);
 ListNode *e = new ListNode(4);
 a->next =b;

 ListNode *c = swapPairs(a);
 while(c) {
   cout<<c->val<<endl;
   c= c->next;
 }
 return 1;
}

ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *tmp;
        ListNode *prev= head;
        ListNode *result;
        if(head->next)
            result = head->next;
        while (head){
  	    if(head->next) {
                prev->next = head->next; 
            	tmp = head->next->next;
            	head->next->next = head;
            	head->next = tmp;
                prev = head;
            	head = tmp;
 	    }
	    else break;
        }
        return result;
 }
