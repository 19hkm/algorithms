// https://leetcode.com/problems/climbing-stairs/

// RunTime O(n)
// Space O(n)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2) return n; 
        vector<int> waysToClimb(n+1, 0);        
        waysToClimb[1] = 1;
        waysToClimb[2] = 2;
        
        for(int i=3; i<=n; i++) {
            waysToClimb[i] = waysToClimb[i-1] + waysToClimb[i-2];
        }
        return waysToClimb[n];
    }
};

// Space O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2) return n;
        
        int waysToClimbMin1=2, waysToClimbMin2=1, waysToClimb;
        for(int i=3; i<=n; i++) {
            waysToClimb = waysToClimbMin1 + waysToClimbMin2;
            waysToClimbMin2 = waysToClimbMin1;
            waysToClimbMin1 = waysToClimb;
        }
        return waysToClimb;
    }
};