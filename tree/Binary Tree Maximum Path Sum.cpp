// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans;
    
    int findPathSum(TreeNode* root){
        if(!root)   return 0;
        int lSum = findPathSum(root->left);
        int rSum = findPathSum(root->right);
        int tempMax = root->val;
        if(lSum>0)  tempMax += lSum;
        if(rSum>0)  tempMax += rSum;
        ans = max(ans, tempMax);
        return max(0, max(root->val, max(root->val+lSum, root->val+rSum)));
    }
    
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        findPathSum(root);
        return ans;
    }
};