// https://leetcode.com/problems/delete-leaves-with-a-given-value/

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

#define null NULL;
class Solution {   
    
    bool postOrderLeafFinder(TreeNode* node, int tar) {
        
        if(!node) 
            return false;
        if(node->left)
            if(postOrderLeafFinder(node->left, tar)) 
                node->left = null;
        if(node->right) 
            if(postOrderLeafFinder(node->right, tar)) 
                node->right = null;
        return !node->left && !node->right && node->val==tar;
    }
    
public:    
    TreeNode* removeLeafNodes(TreeNode* root, int tar) {
        if(postOrderLeafFinder(root, tar)) return null;
        return root;
    }
};