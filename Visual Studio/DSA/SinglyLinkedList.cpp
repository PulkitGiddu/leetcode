#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

//  Constructor.  
    Node(int data){
        this -> data = data;
        this -> next = NULL; 
    }
//  Destructor.
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout <<"Memory is free for node and data: "<< value << endl; 
    }    

};

// For inserting into any node 
void insertAtHead(Node* &head, int d){
    // create new node before existing node 
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
// Now we are writing a print function which will print this linked list 
// And also we will be learning how to triverse the ll.
void print(Node* &head){
    Node* temp = head;
    while (temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp -> next; 
    }
    cout<<endl;
}

void insertAtTail(Node* &tail, int d){
    // new node create kro
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

// for inserting at any soecific place 

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    
    // Insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }
    //Creating a node for d middle case.
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp->next = nodeToInsert;

    // inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
}

// for deletion of node. 
void deleteNode(int position, Node* &head){
    // take care while deleting the first node because first node points to NULL. 
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        // Memory free start node 
        temp -> next = NULL;
        delete temp;
    }
    else {
        // deleting any middle node or last node 
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head; // for triversing  

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout<< "present on element "<< endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;



        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head){
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head; 
    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection-> next;
    }
}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}
 // if one node is there pointing towards itself  


// main function 
 int main(){

    //creating a new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    // Head pointed to node1
    Node* head = node1;
    Node* tail = node1;
   // print(head);
    
    // insertAtHead(head, 12);
    insertAtTail(tail, 12);
    
    //print(head); 

    insertAtTail(tail, 15);
    
    //print(head);

    insertAtPosition(tail, head, 4, 22);
    // for middle case add 3 ,22 
    //  for inserting in first add (1, 22)
   // print(head);


    tail -> next = head -> next;

    cout<<"head: "<< head -> data <<endl;
    cout<<"tail: "<< tail -> data <<endl;

    cout<<"Strating at "<< getStartingNode(head) -> data << endl;
    // deleteNode(4, head);
    // print(head);

    removeLoop(head);
    print(head);

    if(detectLoop(head)){
        cout<< "Cycle is present " << endl;
    }
    else{
        cout<< "No cycle "<<endl;
    }
    return 0;

}
