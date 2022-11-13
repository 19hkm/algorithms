// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// nice problem : done recursively
// O(n) -> max travelling each node twice


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
    vector<int> ans;
    const int MAXI = 1001;
    
    void findAllAtDist(TreeNode* root, TreeNode* target, int k) {
        if(!root) {
            return;
        } else if(!k) {
            ans.push_back(root->val);
        } else {
           findAllAtDist(root->left, target, k-1);
           findAllAtDist(root->right, target, k-1); 
        }
    }
    
    int findNodeDist(TreeNode* root, TreeNode* target, int k) {
        if(!root) {
            return MAXI;
        } else if(root->val == target->val) {
            findAllAtDist(root, target, k);
            return 1;
        } else {
            int lDist = findNodeDist(root->left, target, k);
            int rDist = findNodeDist(root->right, target, k);
            if(lDist<MAXI) {
                int newDist = k-lDist;
                if(!newDist) {
                    ans.push_back(root->val);
                }
                findAllAtDist(root->right, target, newDist-1);
                return lDist+1;
            }
            if(rDist<MAXI) {
                int newDist = k-rDist;
                if(!newDist) {
                    ans.push_back(root->val);
                }
                findAllAtDist(root->left, target, newDist-1);
                return rDist+1;
            }
            return MAXI;  
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        findNodeDist(root, target, k);
        return ans;
    }
};