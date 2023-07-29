ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) {
        return head;
    }
    ListNode* headOdd = head;
    ListNode* headEven = head -> next;
    ListNode* tmpOdd = head;
    ListNode* tmpEven = head -> next;

    while (tmpOdd != NULL && tmpEven != NULL) {
        tmpOdd -> next = tmpEven -> next;
        tmpOdd = tmpEven -> next;
        if (tmpOdd != NULL) {
            tmpEven -> next = tmpOdd -> next;
            tmpEven = tmpOdd -> next;
        }
    }

    tmpOdd = headOdd;
    while(tmpOdd -> next != NULL){
        tmpOdd = tmpOdd -> next;
    }
    tmpOdd -> next = headEven;
    return head;
}

// https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
// Note: Do not confuse this question with sorting odd numbers and even nos. It wants to just sort indices.
