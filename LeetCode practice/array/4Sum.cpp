// https://leetcode.com/problems/4sum/submissions/
// See generic soln for kSum in editorial

// my backtracking soln - Does not pass time constraints
#define PB push_back
#define POPB pop_back
#define I insert
class Solution {
public:
    set<vector<int>> vecSet;
    
    void populateAllSubsetsOfLength(vector<int>& nums, int len, int marker, vector<int> &vec) {
        if(!len) {
            vecSet.I(vec);
            return;
        }
        if(marker>=nums.size()){
            return;
        }
        vec.PB(nums[marker]);
        populateAllSubsetsOfLength(nums, len-1, marker+1, vec);
        vec.POPB();
        populateAllSubsetsOfLength(nums, len, marker+1, vec);
    }
    
    
    vector<vector<int>> validTargetSumVectors(int target) {
        vector<vector<int>> reqVec;
        for(auto vec : vecSet) {
            int sum = 0;
            for(auto num : vec) {
                sum+= num;
            }
            if(sum==target) {
                reqVec.PB(vec);
            }
        }
        return reqVec;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<int> v;
        v.clear();
        vecSet.clear();
        populateAllSubsetsOfLength(nums, 4, 0, v);
        
        return validTargetSumVectors(target);
    }
};