/*
Max Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

LEETCODE : # 104: https://leetcode.com/problems/maximum-depth-of-binary-tree

// Level Order Traversal solution

int maxDepth(TreeNode *root) {
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i) {
            TreeNode *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    
    return res;
}

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
int Solution::maxDepth(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!root) return 0;
    auto left_depth = maxDepth(root->left);
    auto right_depth = maxDepth(root->right);
    return 1 + max(left_depth, right_depth);
}

/*
// official

class Solution {
    public:
        int maxDepth(TreeNode *root) {
            // Corner case. Should never be hit unless the code is called on root = NULL
            if (root == NULL) return 0;
            // Base case : Leaf node. This accounts for height = 1.
            if (root->left == NULL && root->right == NULL) return 1;

            if (!root->left) return maxDepth(root->right) + 1;
            if (!root->right) return maxDepth(root->left) + 1;

            return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
        }
};

*/
