Q - merge two sorted linked list 

code: 
Q - Merge Two sorted Linked List 

Code: 

Node<int>* solve(Node<int>* first, Node<int>* second){

    // if only one element is present in the list
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    
   Node<int>* curr1 = first;
   Node<int>* next1 = curr1 -> next;
   Node<int>* curr2 = second;
   Node<int>* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
        
        // add node in between the first list
         curr1 -> next = curr2; 
         next2 = curr2 -> next;
         curr2 -> next = next1;

        // Update pointer
         curr1 = curr2;
         curr2 = next2;    
        }
        else{ // curr1 and next1 ko aage bada do

        curr1 = next1;
        next1 = next1 -> next;

        if(next1 == NULL){
            curr1 -> next = curr2;
            return first;
            }

        }
    }
    return first;

}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second ){
    if(first == NULL)
    return second;
    
    if(second == NULL)
    return first;

    if(first -> data <= second -> data){
        solve(first, second);
    }
    else{
        solve(second, first);
    }
}

// recursive approch 
// class Solution {
// public:
// 	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
//   {
// 		// if list1 happen to be NULL
// 		// we will simply return list2.
// 		if(l1 == NULL)
//         {
// 			return l2;
// 		}
		
// 		// if list2 happen to be NULL
// 		// we will simply return list1.
// 		if(l2 == NULL)
//         {
// 			return l1;
// 		} 
		
// 		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
// 		// we wall call recursively l1 -> next and whole l2 list.
// 		if(l1 -> val <= l2 -> val)
//         {
// 			l1 -> next = mergeTwoLists(l1 -> next, l2);
// 			return l1;
// 		}
// 		// we will call recursive l1 whole list and l2 -> next
// 		else
//         {
// 			l2 -> next = mergeTwoLists(l1, l2 -> next);
// 			return l2;            
// 		}
// 	}
// };	

// iterative approch
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
	    // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        ListNode *curr = ptr;
        
		// till one of the list doesn't reaches NULL
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
		
		// adding remaining elements of bigger list.
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
       
    }
};
