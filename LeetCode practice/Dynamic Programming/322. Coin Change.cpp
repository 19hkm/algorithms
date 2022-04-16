// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> diffCoin(amount+1, INT_MAX);
        diffCoin[0]=0;
        for(int i=1; i<amount+1; ++i){
            for(int coinVal : coins){
                if(coinVal <= i && diffCoin[i-coinVal]!=INT_MAX) {
                    diffCoin[i] = min(diffCoin[i], diffCoin[i-coinVal]+1);
                }
            }
        }
        return diffCoin[amount] != INT_MAX? diffCoin[amount]:-1;
    }
};