// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define PB push_back

bool isS(TreeNode* A, TreeNode* B) {
    if(!A && !B) {
        return true;
    } else if (!A || !B) {
        return false;
    } else {
        return A->val == B->val && isS(A->left, B->right) && isS(A->right, B->left);
    }
}

int Solution::isSymmetric(TreeNode* A) 
{
    return isS(A,A);
}
