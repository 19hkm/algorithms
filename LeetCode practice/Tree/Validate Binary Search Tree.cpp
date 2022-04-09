// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isInRange(TreeNode* root, long long l, long long r){
        if(!root)   return true;
        else if( root->val >= r || root->val <= l) return false;
        return isInRange(root->left, l, root->val) && isInRange(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        return isInRange(root, (long long)INT_MIN -1, (long long)INT_MAX+1);
    }
};