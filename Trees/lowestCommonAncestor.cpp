/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int commonAncestor(TreeNode* A, int B, int C) {
    if (A == NULL) {
        return -1;
    } else if (A -> val == B || A -> val == C) {
        return (A -> val);
    }
    
    int leftVal = commonAncestor(A -> left, B, C);
    int rightVal = commonAncestor(A -> right, B, C);
    
    if (leftVal != -1 && rightVal != -1) {
        return A -> val;
    } else if (leftVal != -1) {
        return leftVal;
    } else if (rightVal != -1) {
        return rightVal;
    } else {
        return -1;
    }
}

bool findNode(TreeNode* A, int B) {
    if (A == NULL) {
        return false;
    } else if (A -> val == B) {
        return true;
    }
    
    return findNode(A -> left, B) || findNode(A -> right, B);
}

int Solution::lca(TreeNode* A, int B, int C) {
    if (A == NULL) {
        return - 1;
    }
    
    bool findB = findNode(A, B);
    bool findC = findNode(A, C);
    
    if (!findB || !findC) {
        return -1;
    }
    
    if (A -> val == B || A -> val == C){
        return A -> val;
    }
    int leftVal = commonAncestor(A -> left, B, C);
    int rightVal = commonAncestor(A -> right, B, C);
    
    if (leftVal != -1 && rightVal != -1) {
        return A -> val;
    } else if (leftVal != -1) {
        return leftVal;
    } else if (rightVal != -1) {
        return rightVal;
    } else {
        return -1;
    }
}

// https://www.interviewbit.com/problems/least-common-ancestor/
// NOTE: Trick here is to find first if B and C both exists, otherwise it becomes challenging to put corner cases.
