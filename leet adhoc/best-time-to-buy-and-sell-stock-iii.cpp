class Solution {
public:
    
    inline void prepLeftSell(vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size(), mini =1e5+1, maxi =0, maxP=0;
        for(int i=0; i<n; i++){
            if(prices[i]<mini){
                mini = prices[i];
                maxi = 0;
            } else if(prices[i]>maxi){
                maxi = prices[i];
                maxP = maxi - mini;
            }
            dp[0][i] = maxP;
        }
        return;
    }
        
    inline void prepRightSell(vector<int> &prices, vector<vector<int>> &dp) {
        int n = prices.size(), mini =1e5+1, maxi =0, maxP=0;
        for(int i=n-1; i>=0; i--){
            if(prices[i]>maxi){
               maxi = prices[i];
               mini = 1e5+1;   
            } else if(prices[i]<mini){
                mini = prices[i];
                maxP = maxi - mini;
            }
            dp[1][i] = maxP;
        }
        return;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini =1e5+1, maxi =0, maxP=0;
        vector<vector<int>> dp(2, vector<int>(n,0));
        
        prepLeftSell(prices, dp);
        prepRightSell(prices, dp);
        
        // printVec(dp);
        
        for(int i=0;i<n;i++)    
            maxP = max(maxP, dp[0][i]+dp[1][i]);
        
        return maxP;
    }
};