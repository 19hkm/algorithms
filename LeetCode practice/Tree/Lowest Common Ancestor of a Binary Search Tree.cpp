// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
        if(!root)   return NULL;
        int pCalc = (root->val - p->val);
        int cCalc = (root->val - q->val);
        if(!pCalc || !cCalc || pCalc*cCalc <0) return root;
        else if(pCalc>0) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};