// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> nodeQ;
        // nodeQ.clear();
        nodeQ.push(root);
        nodeQ.push(NULL);
        vector<int> rightViewVec;
        while(!nodeQ.empty()) {
            TreeNode* topElem = nodeQ.front();
            nodeQ.pop();
            if(!topElem) {
                if(nodeQ.empty())
                    break;
                else 
                    nodeQ.push(topElem);
            } else {
                if(topElem->left) nodeQ.push(topElem->left);
                if(topElem->right) nodeQ.push(topElem->right);
                if(!nodeQ.front())  rightViewVec.push_back(topElem->val);
            } 
        }
        return rightViewVec;
    }
};