// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root=root->left;
            }
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top->val);
            root = top->right;
        }
        return ans;
    }
};

/* 
    Logic: a node once entered into the stack means its 
    left side has been fully processed. if root!=null means 
    the node needs to be processed for its left children.

    Each time a node is popped out of stack means. Its fully 
    processed in its left children. So print and move to its
    right children
*/