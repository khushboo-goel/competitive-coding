/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    int count = 0;
    ListNode* temp = A;
    
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    if (count == 1) {
        TreeNode* node = new TreeNode(A -> val);
        return node;
    }
    if (count == 2) {
        TreeNode* node = new TreeNode(A -> next -> val);
        node -> left = new TreeNode(A -> val);
        return node;
    }
    temp = A;
    ListNode* preTmp = NULL;
    int mid = count / 2;
    while(mid > 0){
        temp = temp -> next;
        preTmp = (preTmp == NULL) ? A : preTmp -> next; 
        mid --;
    }
    
    TreeNode* root = new TreeNode(temp -> val);
    preTmp -> next = NULL;
    root -> left = sortedListToBST(A);
    root -> right = sortedListToBST(temp-> next);

    return root;
}

// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
