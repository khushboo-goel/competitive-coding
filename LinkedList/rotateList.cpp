// https://leetcode.com/problems/rotate-list/description/

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 1;
    int val = k;
    if (temp == NULL || k == 0) {
        return head;
    }
    while(temp -> next != NULL) {
        count ++;
        temp = temp -> next;
    }

    if (count == 0) {
        return head;
    }
    if (count <= k) {
        val = k % count;
    }

    count = count - val - 1;
    ListNode* last = head;
    while(count > 0) {
        last = last -> next;
        count--;
    }

    temp -> next = head;
    head = last -> next;
    last -> next = NULL;

    return head;
}
