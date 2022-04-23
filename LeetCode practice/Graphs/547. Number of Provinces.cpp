// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<bool> &isVisited, int &n, int src) {
        isVisited[src] = true;
        for(int i=0; i<n; i++){
            if(isConnected[src][i] && !isVisited[i]){
                dfs(isConnected, isVisited, n, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),  count = 0;
        vector<bool> isVisited(n, false);
        for(int i=0; i<n ; i++){
            if(!isVisited[i]){
                count++;
                dfs(isConnected, isVisited, n, i);
            }
        }
        return count;
    }
};