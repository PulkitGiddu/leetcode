Q - 203. Remove Linked List Elements 
code: 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return NULL;
    ListNode* dummy = new ListNode(-1);
    dummy -> next = head; 
    ListNode* tail = dummy; 
    while(tail != NULL && tail -> next != NULL){
        if(tail -> next -> val == val){
            ListNode* temp = tail -> next; 
            tail -> next = temp -> next;
            delete(temp);
        }
        else{
            tail = tail -> next;
        }
    } 
    return dummy -> next;     
    }
};

// T.C = O(n)
// S.C = O(1)

Code2: 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return NULL;
         head -> next = removeElements(head -> next, val);
         if(head -> val == val){
            ListNode* ans = head -> next;
            delete head;
            return ans;
         }
         else{
            return head;
         }
         
    }
};

Code3: 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return NULL;
         head -> next = removeElements(head -> next, val);
        return head -> val == val? head -> next: head;
    }
};
