/*

Identical Binary Trees

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

LEETCODE: #100 : https://leetcode.com/problems/same-tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if((!p && q) || (p && !q)) return false;
        if(p->val != q->val) return false;
        if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) return false;
        return true;
    }
};

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* p, TreeNode* q) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (p == NULL && q == NULL) return 1;
    if((!p && q) || (p && !q)) return 0;
    if(p->val != q->val) return false;
    if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) return 0;
    return 1;
}

/*
// official

class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == NULL && q == NULL) return true;
            if (p == NULL || q == NULL) return false;
            return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
        }
};

*/
