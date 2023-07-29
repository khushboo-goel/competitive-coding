ListNode* mergeList(ListNode* left, ListNode* right) {
    ListNode* headLeft = left;
    ListNode* headRight = right;
    ListNode* tmp = NULL;
    ListNode* head = NULL;
     
    while(left != NULL && right != NULL) {
        if (left -> val <= right -> val) {
            if (head == NULL) {
                head = left;
                tmp = left;
                left = left -> next;
            } else {
                tmp -> next = left;
                tmp = tmp -> next;
                left = left -> next;
            }
        } else {
            if (head == NULL) {
                head = right;
                tmp = right;
                right = right -> next;
            } else {
                tmp -> next = right;
                tmp = tmp -> next;
                right = right -> next;
            }
        }
    }
    
    while (left != NULL) {
        tmp -> next = left;
        tmp = tmp -> next;
        left = left -> next;
    }
    
    while (right != NULL) {
        tmp -> next = right;
        tmp = tmp -> next;
        right = right -> next;
    }
    
    return head;
}
ListNode* sortLinkedList(ListNode* head, int start, int end) {
    // only one node
    if (end - start == 0) {
        return head;
    }
    
    int mid = (end - start) / 2;
    
    int count = 0;
    ListNode* tmp = head;
    while(count < mid) {
        count ++;
        tmp = tmp -> next;
    }
    
    ListNode* right = sortLinkedList(tmp -> next, 0, end - (mid + 1));
    tmp -> next = NULL;
    ListNode* left = sortLinkedList(head, 0, mid);
    
    return mergeList(left, right);
    return head;
}

ListNode* Solution::sortList(ListNode* A) {
    // this will be merge sort
    int length = 0;
    ListNode* tmp = A;
    while(tmp != NULL) {
        length ++;
        tmp = tmp -> next;
    }
    
    return sortLinkedList(A, 0, length - 1);
}

// https://www.interviewbit.com/problems/sort-list/
// Note: Please take care the lengths passed properly in line 60 and 62. Also nullify the string before the sort subtree (line 61).
