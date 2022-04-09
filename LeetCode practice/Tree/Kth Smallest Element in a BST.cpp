// Use iterative inorder trversal. BST inorder gives elements in sorted order
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// See Binary Tree Inorder Traversal Iterative.cpp for more info

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            } 
            TreeNode* top = st.top();
            st.pop();
            if(k == ++count)    
                return top->val;
        }
        return 0;
    }
};