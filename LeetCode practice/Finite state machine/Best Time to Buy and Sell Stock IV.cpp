// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Based in FSA learnt from type 3 prob

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans=0, i, j, n = prices.size();
        vector<int> maxP(2*k, INT_MIN);
        
        for(i=0; i<n; i++){
            int sign = 1;
            int prev = 0;
            for(j=0; j<2*k; j++) {
                sign *= -1;
                maxP[j]= max(maxP[j], prev + sign*prices[i]);
                prev = maxP[j];
            }
        }
        
        for(i=0; i<2*k; i++)
            ans = max(ans, maxP[i]);
        
        return ans;
    }
};