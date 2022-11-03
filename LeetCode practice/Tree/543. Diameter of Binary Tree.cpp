// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

// M1: recursive soln
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
    
    int nodesInLongestPath(TreeNode* root, int &maxDiameter) {
        if(!root){
            return 0;
        } else {
            int lNodeCount = nodesInLongestPath(root->left, maxDiameter);
            int rNodeCount = nodesInLongestPath(root->right, maxDiameter);
            maxDiameter = max(maxDiameter, lNodeCount + rNodeCount);
            return max(lNodeCount, rNodeCount) + 1;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        nodesInLongestPath(root, maxDiameter);
        return maxDiameter;
    }
};