// https://www.interviewbit.com/problems/2sum-binary-tree/

//Method 1: Very good and difficult problem if used threading concept 
// O(1) extra space and O(n) time




// Method 2 : O(n) space and time 
void inOrder(TreeNode* A, vector<int> &v) {
    if(!A)  {
        return;
    } else {
        inOrder(A->left, v);
        v.push_back(A->val);
        inOrder(A->right, v);
    }
}

bool findInVec(vector<int> &v, int &tar) {
    int n = v.size(), beg = 0, end = n-1;
    while(beg<end) {
        if(v[beg]+v[end]==tar) {
            return true;
        } else if(v[beg]+v[end]<tar) {
            beg++;
        } else {
            end--;
        }
    }
    return false;
}

int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> v;
    inOrder(A, v);
    return findInVec(v, B);
}