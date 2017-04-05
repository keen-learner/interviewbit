/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

    NOTE : The path has to end on a leaf node. 

Example :

         1
        /
       2

min depth = 2.

LEETCODE: #111: https://leetcode.com/problems/minimum-depth-of-binary-tree/#/description 

// http://www.geeksforgeeks.org/find-minimum-depth-of-a-binary-tree/ 
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Corner case. Should never be hit unless the code is 
        // called on root = NULL
        if (root == NULL)
            return 0;
 
        // Base case : Leaf Node. This accounts for height = 1.
        if (root->left == NULL && root->right == NULL)
           return 1;
 
        // If left subtree is NULL, recur for right subtree
        if (!root->left)
            return minDepth(root->right) + 1;
 
       // If right subtree is NULL, recur for right subtree
        if (!root->right)
            return minDepth(root->left) + 1;
 
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
    public:
        int minDepth(TreeNode *root) {
            if(!root)
                return 0;

            queue<TreeNode *> q;
            int d = 1;
            q.push(root);
            int cnt = q.size();

            // BFS or Level Order Traversal
            while(!q.empty()) {
                TreeNode *n = q.front();
                q.pop();

                if(!n->left && !n->right)
                    return d;
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);

                cnt--;
                if(!cnt) {
                    cnt = q.size();
                    d++;
                }
            }
        }
};

*/

int Solution::minDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A) return 0;
    queue<TreeNode *> q;
    int count = 1;
    q.push(A);
    vector<int> l;
    int depth = 1;
    
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        --count;
        if (!t->left && !t->right) return depth; //leaf node
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
        if(count == 0) { //level complete
            count = q.size();
            ++depth;
        }
    }
}



/*
// official

class Solution {
    public:
        int minDepth(TreeNode *root) {
            // Corner case. Should never be hit unless the code is called on root = NULL
            if (root == NULL) return 0;
            // Base case : Leaf node. This accounts for height = 1.
            if (root->left == NULL && root->right == NULL) return 1;

            if (!root->left) return minDepth(root->right) + 1;
            if (!root->right) return minDepth(root->left) + 1;

            return min(minDepth(root->left), minDepth(root->right)) + 1; 
        }
};

*/
