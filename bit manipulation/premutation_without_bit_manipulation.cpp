// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> allPerm;
    
    void swapi(int &a, int &b){
        int c = a;
        a=b;
        b=c;
    }
    
    void processVec(vector<int>& nums, int i, int n) {
        if(i==n-1)    allPerm.push_back(nums);
        else {
            for(int j=i; j<n; j++){
                swapi(nums[i], nums[j]);
                processVec(nums, i+1, n);
                swapi(nums[i], nums[j]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        allPerm.clear();
        processVec(nums, 0, nums.size());
        return allPerm;
    }
};