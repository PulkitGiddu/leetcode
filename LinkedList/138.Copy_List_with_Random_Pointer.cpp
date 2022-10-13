138. Q - Clone a linked list with next and random pointer

Code: 
class Solution{
    private: 
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    public: 
    Node* copyList(Node* head){
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
       
        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }

        // Step2: craate a map
        unordered_map<Node*, Node*> oldToNewNode;
        Node* orignalNode = head;
        Node* cloneNode = cloneHead;
        while(orignalNode != NULL){
            oldToNewNode[orignalNode] = cloneNode;
            orignalNode = orignalNode -> next;
            cloneNode = cloneNode -> next;
        }

        orignalNode = head;
        cloneNode = cloneHead;

        while(orignalNode != NULL){
            cloneNode -> arb = oldToNewNode[orignalNode -> arb];
            orignalNode = orignalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};

Code 2: 
class Solution{
    public: 
Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        // temporary (copied) head node
        Node* temp=head;
        
        // 1st Pass
        
        while(temp!=NULL)
        {
             // Cloned node with same val as head
            Node* newnode= new Node(temp->val);
            
            // Insert the cloned node next to the original node
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        
        temp=head;
        
        // Link random pointers of the newly created nodes
        // and iterate through the newly created list and
        // use original node's random pointers
        
        // 2nd Pass
        
        while(temp!=NULL)
        {
            temp->next->random=(temp->random)?(temp->random->next):NULL;       
            temp=temp->next->next;
        }
        
         // Unweave the current linked list to get back the 
        // original linked list and the cloned one.
        
		// A->B->C
        Node* original=head;
        
        // A'->B'->C'
        Node* clone=head->next;
        
        // Result is used for returning
        Node* result=head->next;
        // 3rd Pass
        
        while(original!=NULL)
        {
            original->next=original->next->next;
            clone->next= (clone->next)?(clone->next->next):NULL;
            
            original=original->next;
            clone=clone->next;
        }
        
        return result;
}
};

// Solution 2: Constant Space without Hashmap
// Time: O(N)
// Space: O(1)
