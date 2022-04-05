// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// good soln: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n)-time-complexity-O(1)-space-complexity

class Solution {
public:
        
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int s1=INT_MIN,s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;

        int n = prices.size();
        for(int i=0;i<n;++i) {            
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1+prices[i]);
            s3 = max(s3, s2-prices[i]);
            s4 = max(s4, s3+prices[i]);
        }
        return max(0,s4);
    }
};