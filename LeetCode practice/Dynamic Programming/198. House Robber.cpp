// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> maxMoney(n,0);
        
        for(int i=0; i<n; i++) {
            if(i==0) maxMoney[i] = nums[i];
            else if(i==1) maxMoney[i] = max(maxMoney[0], nums[i]);
            else maxMoney[i] = max(nums[i]+maxMoney[i-2], maxMoney[i-1]);
        }
        
        return maxMoney[n-1];
    }
};