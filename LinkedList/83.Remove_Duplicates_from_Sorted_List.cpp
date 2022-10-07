Q - 83. Remove Duplicates from Sorted List

/*

*/
code: 
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         // check for empty list 
//         if(head == NULL)
//             return NULL;
        
//         // Check for non empty list 
//         ListNode* curr = head;
//         while(curr != NULL){
//             if((curr -> next = NULL ) && curr -> data == curr -> next -> data){
                
//                 ListNode* next_next = curr -> next -> next;
//                 ListNode* nodeToDelete = curr -> next;
//                 delete(nodeToDelete);
//                 curr -> next = next_next;
//             }
//             else{ // not equal 
//                 curr = curr -> next;
//             }
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur_node = head;
        while (cur_node && cur_node->next) {
            ListNode* next_node = cur_node->next;
            if (cur_node->val == next_node->val)
                cur_node->next = next_node->next;
            else
                cur_node = next_node;
        }
        return head;
    }
};
