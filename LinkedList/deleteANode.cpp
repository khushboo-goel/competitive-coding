// https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(ListNode* node) {
    ListNode* head = node;
    ListNode* next = node -> next;

    while(next -> next != NULL) {
        head -> val = next -> val;
        head = head -> next;
        next = next -> next;
    }

    head -> val = next -> val;
    head -> next = NULL;
}
