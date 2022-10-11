Q - Intersection of two linked list 

Code: 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    
    ListNode* a = headA;
    ListNode* b = headB;
    while(a != b){
     a = a == NULL? headB : a -> next;
     b = b == NULL? headA : b -> next; 
       } 
      return a;
    }
};

// T.C = O(2M)
// S.C = O(1)
