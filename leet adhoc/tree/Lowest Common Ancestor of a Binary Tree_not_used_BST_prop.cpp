// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
// this solution is for in geeral any binary tree. Not specific to BST.
//  Haven't used the benefit of tree being BST 

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
        else if(root == p) return p;
        else if(root == q) return q;
        else {
            TreeNode* leftA = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightA = lowestCommonAncestor(root->right, p, q);
            if(leftA!=NULL && rightA!=NULL) return root;
            else if (leftA) return leftA;
            else if (rightA) return rightA;
            else return NULL;
        }
    }
};