// Easy
// https://leetcode.com/problems/minimum-path-sum/

class Solution {
    int minPar(vector<int> &mSum, int i, int j) {
        if(!j){
            return mSum[j];
        } else if(!i) {
            return mSum[j-1];
        } else {
            return min(mSum[j], mSum[j-1]);
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        
        vector<int> minSum(n, 0);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                minSum[j] = grid[i][j] + minPar(minSum, i, j);
            }
        }
        return minSum[n-1];
    }
};