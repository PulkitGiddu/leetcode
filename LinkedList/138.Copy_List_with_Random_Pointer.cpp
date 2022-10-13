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
