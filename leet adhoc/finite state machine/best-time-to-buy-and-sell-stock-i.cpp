https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,n = prices.size();
        int minV=1e4+1, maxV=0, maxP=0;
        for(int val: prices){
            if(val<minV){
                minV = val;
                maxV=0;
            }    
            else if(val>maxV){
                maxV = val;
                maxP = max(maxP, maxV-minV);
            }
        }
        return maxP;
    }
};