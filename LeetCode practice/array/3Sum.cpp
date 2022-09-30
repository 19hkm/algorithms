// https://leetcode.com/problems/3sum/

class Solution {
public:
    
    set<vector<int>> findTripletsSet(vector<int>& sortedNums, int &anchor, int beg, int end) {
        set<vector<int>> uniqueTriplets;
        uniqueTriplets.clear();
        while(beg<end) {
            int tempSum = sortedNums[anchor] + sortedNums[beg]+ sortedNums[end];
            if(!tempSum) {
                uniqueTriplets.insert({sortedNums[anchor], sortedNums[beg], sortedNums[end]});
            }
            if(tempSum<=0) {
                beg++;
            } else {
                end--;
            }
        }
        return uniqueTriplets;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> threeSumRes;
        for(i=0; i<len-2; i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            auto tripletsSet = findTripletsSet(nums, i, i+1, len-1);
            for(auto vec : tripletsSet) {
                threeSumRes.push_back(vec);
            }
        }
        return threeSumRes;
    }
};