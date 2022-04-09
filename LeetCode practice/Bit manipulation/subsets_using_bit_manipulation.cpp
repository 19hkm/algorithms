// https://leetcode.com/problems/subsets/

class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> vec;
        int n = nums.size();
        for(int i=0; i<(1<<n); i++){
            vec.clear();
            for(int j=0;j<n;j++){
                if(1<<j & i)
                    vec.push_back(nums[j]);
            }
            allSubsets.push_back(vec);
        }
        return allSubsets;
    }
};