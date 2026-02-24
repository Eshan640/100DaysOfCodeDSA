/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to handle edge cases (like removing head)
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* current = &dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Remove the node
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);  // free memory (important in C)
        } else {
            current = current->next;
        }
    }
    
    return dummy.next;
}