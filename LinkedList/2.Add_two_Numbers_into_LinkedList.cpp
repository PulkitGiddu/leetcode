Q - Add two numbers into linked list 
code: 
class Solution {
private: 
        Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val){
        Node* temp  = new Node(val);
        //empty list
        if(head == NULL){
            head = temp;
            tail = temp;
            return; 
        }
        else{
            tail -> next = temp; 
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(fisrt != NULL || second != NULL || carry != 0){
           
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
            
            int val2 = 0;
            if(second != NULL)
                val2 = second -> data; 
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            
            // creating new node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;   
    }
    
    
public:
   struct Node* addTwoLists(struct Node* first, struct Node* second){
    // Step1 : reverse Input LL
       first = reverse(first);
       second = reverse(second);
       
    // Step 2: add 2 LL
       Node* ans = add(first, second);
       
    // Step 3: reverse the list
       ans = reverse(ans);
       return ans;
   }
};
