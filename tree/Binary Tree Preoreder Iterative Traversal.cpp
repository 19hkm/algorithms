//https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()) {
            TreeNode* topElem = st.top();
            ans.push_back(topElem->val);
            st.pop();
            if(topElem->right)  st.push(topElem->right);
            if(topElem->left)  st.push(topElem->left);
        }
        return ans;
    }
};