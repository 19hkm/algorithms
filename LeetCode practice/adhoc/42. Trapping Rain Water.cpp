// https://leetcode.com/problems/trapping-rain-water/
// Good problem - multiple ways to do it

// METHOD 1:  O(n) time and O(n) space
class Solution {
public:
    
    int trap(vector<int>& height) {
        int n = height.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int totalWaterStored=0;
        for(int i=1; i<n; i++) {
            dp[0][i] = max(dp[0][i-1], height[i-1]);
            dp[1][n-1-i] = max(dp[1][n-i], height[n-i]);
        }
        for(int i=0; i<n; i++) {
            int bucketWater = min(dp[0][i], dp[1][i]) - height[i];
            totalWaterStored += bucketWater>0 ? bucketWater : 0;
        }
        return totalWaterStored;
    }
};

// METHOD 2: O(N) time and O(1) space. - 2ptr logic
// see discussion: https://leetcode.com/problems/trapping-rain-water/discuss/2679351/C%2B%2B-Solution-using-two-pointers
// logic keep 2 maxPtrs on both side. If currLeft>currRight then currLeft will be bounded by right
// if on left its lesser than lMax then it can hold water or else it will update lMax
// same logic for right
class Solution {
public:
    
    int trap(vector<int>& height) {
        int n = height.size(); 
        if(n<2) return 0;
        int totalWaterStored=0, lMax=0, rMax=0,  beg=0, end=n-1;
        while(beg<=end) {
            int *index;
            if(height[beg]<=height[end]) {
                index = &beg;
            } else {
                index = &end;
            }
            int possibleWater;
            if(*index==beg) {
                possibleWater = lMax-height[*index];
                lMax = max(lMax, height[beg++]);
            } else {
                possibleWater = rMax-height[*index];
                rMax = max(rMax, height[end--]);
            }
            totalWaterStored += possibleWater>0? possibleWater:0;
        }
        return totalWaterStored;
    }
};

// METHOD 3: O(N) time and O(n) space. - stack logic
