// https://leetcode.com/problems/cousins-in-binary-tree/submissions/
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
    void findNodeDepths(TreeNode* root,int &x, int &y, int &depX, int &depY, int k){
        if(!root)   return;
        if(root->val ==x)   depX = k;
        else if(root->val == y) depY = k;
        else if(root->left && root->right && (root->left->val + root->right->val == x+y)){
            depX=-1; return;
        }
        findNodeDepths(root->left, x, y, depX, depY, k+1);
        findNodeDepths(root->right, x, y, depX, depY, k+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int depX = -1, depY = -1;
        findNodeDepths(root, x, y, depX, depY, 0);
        return (depX==depY) && depX!=-1;
    }
};