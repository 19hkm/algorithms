//https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    
    void inOrderTrav(TreeNode* root, int &preVal, int &ans){
        if(!root) return;
        inOrderTrav(root->left, preVal, ans);
        ans = min(ans, root->val - preVal);
        preVal = root->val;
        inOrderTrav(root->right, preVal, ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, preVal = -1e5-1;
        inOrderTrav(root, preVal, ans);
        return ans;
    }
};