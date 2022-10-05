// https://leetcode.com/problems/distinct-subsequences/
// med-hard prob: keep in mind for any data overflow
// always estimate the max size if doing binary operations - good in that terms

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n1 = s.length(), n2=t.length();
        if(!n2) return 1;
        if(!n1) return 0;
        
        vector<vector<unsigned long long>> dp(1+n1, vector<unsigned long long>(1+n2, 0));
        
        for(int i=0; i<=n1; i++) {
            for(int j=0; j<=n2; j++) {
                if(!j) {
                    dp[i][j]=1;
                } else if(!i) {
                    dp[i][j]=0;
                } else {
                    dp[i][j] = dp[i-1][j];
                    if(s[i-1]==t[j-1]){
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};