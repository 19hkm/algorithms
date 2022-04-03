// https://leetcode.com/problems/subsets/

class Solution {
public:
    
    vector<vector<int>> allSubsets;
    
    void findSubsetFromIndex(vector<int>& nums, int i, vector<int> &v){
        if(i==nums.size()) {
            allSubsets.push_back(v);
        } else {
            vector<int> vWithI(v);
            v.push_back(nums[i]);
            findSubsetFromIndex(nums, i+1, vWithI);
                
            vector<int> vWithoutI(v);
            findSubsetFromIndex(nums, i+1, vWithoutI);
        }
    }
    
    //can solve this using bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        findSubsetFromIndex(nums, 0, vec);
        return allSubsets;
    }
};