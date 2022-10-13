Q - 61. Rotate List. 

code: 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *curr, *tail;
        curr = tail = head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        
        curr = tail->next; 
        tail->next = NULL;
        return curr;
    }
};
// Time complexity = O(n)
// space compexity = O(1)
