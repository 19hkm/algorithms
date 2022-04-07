https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP =0, minP = 1e4+1;
        for(int val: prices){
            if(val>minP) maxP += val-minP;
            minP = val;
        }
        return maxP;
    }
};