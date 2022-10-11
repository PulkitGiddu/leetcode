Q - 19. Remove Nth Node From End of List 

code :
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* start = new ListNode();// dummy node created 
      start -> next = head;
      
      ListNode* fast = start;
      ListNode* slow = start;
      
      for(int i = 1; i<=n; ++i)
        fast = fast -> next;
      
      while(fast -> next != NULL){
      fast  = fast -> next;
      slow  = slow -> next;
      }
      slow -> next = slow -> next -> next;
    }
};

// T.C = O(N)
// S.C = O(1)
