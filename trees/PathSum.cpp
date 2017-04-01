/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LEETCODE : #112: https://leetcode.com/problems/path-sum/#/description 

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
int Solution::hasPathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // 0 -false, 1- true
    if(!root) return 0;
    if (!root->left && !root->right) { //leaf node
        if(root->val == sum) return 1;
        else return 0;
    }
    auto left_result = hasPathSum(root->left, sum-root->val);
    auto right_result = hasPathSum(root->right, sum-root->val);
    if(left_result  == 0 && right_result == 0) return 0;
    return 1;
}

/*
// official

class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == NULL) return false;
            if (root->left == NULL && root->right == NULL) {
                return sum == root->val;
            }
            int remainingSum = sum - root->val;
            return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
        }
};

*/
