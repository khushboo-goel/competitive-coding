ListNode* deleteMiddle(ListNode* head) {
    ListNode* tmp = head;
    int count = 0;

    while(tmp != NULL) {
        count ++;
        tmp = tmp -> next;
    }

    if (count == 1) {
        return NULL;
    }
    int mid = count / 2;
    ListNode* middle = head;
    ListNode* prevMiddle = NULL;

    while(mid > 0) {
        middle = middle -> next;
        prevMiddle = (prevMiddle == NULL) ? head: prevMiddle -> next;
        mid --;
    }

    prevMiddle -> next = middle -> next;
    delete(middle);

    return head;
}

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
