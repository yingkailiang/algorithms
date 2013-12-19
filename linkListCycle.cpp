#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
bool hasCycle(ListNode *head); 

int main() {
 ListNode *a = new ListNode(0);
 ListNode *b = new ListNode(1);
 ListNode *c = new ListNode(2);
 ListNode *d = new ListNode(3);
 
 a->next =b;
 b->next =c;
 c->next =d;
 d->next =b;

 if(hasCycle(a)) cout<<"has cycle\n";
 else cout<<"no cycle\n";

 return 1;
}
bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;
        ListNode *first = head;
        ListNode *second = head;
        while(first && first->next && second && second->next){
               first = first->next;
               second = second->next->next;
            if(first == second) return true;
        }
        return false;
  }
