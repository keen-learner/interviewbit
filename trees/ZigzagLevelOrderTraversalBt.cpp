/*
ZigZag Level Order Traversal BT
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

LEETCODE: # 102: https://leetcode.com/problems/binary-tree-level-order-traversal/#/description
LEETCODE: # 103: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description 


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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int>> res;
    if(!A) return res;
    queue<TreeNode *> q;
    int count = 1;
    bool dir = true;
    q.push(A);
    vector<int> l;
    
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        --count;
        l.push_back(t->val);
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
        if(count == 0) { //level complete
            if(dir) {
                res.push_back(l);
            }
            else {
                reverse(l.begin(), l.end());
                res.push_back(l);
            }
            // l.clear();
            l.erase(l.begin(), l.begin()+l.size());
            count = q.size();
            dir = !dir;
        }
    }
    return res;
}

/*
// official solution

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > output;
        if (root == NULL) return output;
        stack<TreeNode*> cur_layer;
        cur_layer.push(root);
        stack<TreeNode*> next_layer;
        vector<int> layer_output;
        int d = 0; // 0: left to right; 1: right to left.

        while (!cur_layer.empty()) {
            TreeNode* node = cur_layer.top();
            cur_layer.pop();
            layer_output.push_back(node->val);
            if (d == 0) {
                if (node->left != NULL) next_layer.push(node->left);
                if (node->right != NULL) next_layer.push(node->right);
            } else {
                if (node->right != NULL) next_layer.push(node->right);
                if (node->left != NULL) next_layer.push(node->left);
            }

            if (cur_layer.empty()) {
                output.push_back(layer_output);
                layer_output.clear();
                cur_layer.swap(next_layer);
                if (d == 1) d = 0;
                else d = 1;
            }
        }
        return output;
        
    }
};

*/
