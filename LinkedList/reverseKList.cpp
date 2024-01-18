// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

ListNode* reverseList(ListNode* head) {
    ListNode* rev = head;
    ListNode* curr = head;

    if (head == NULL || head -> next == NULL) {
        return head;
    }

    rev = reverseList(head -> next);
    curr -> next -> next = curr;
    curr -> next = NULL;
    return rev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 1;
    if (head == NULL) {
        return head;
    }
    while(temp -> next != NULL && count < k) {
        count ++;
        temp = temp -> next;
    }

    if (count < k) {
        return head;
    } else {
        ListNode* rev = reverseKGroup(temp -> next, k);
        temp -> next = NULL;
        ListNode* currRev = reverseList(head);
        head -> next = rev;
        return currRev;
    }
}
