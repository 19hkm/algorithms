// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    vector<int> dirY;
    vector<int> dirX;
    int maxArea;
    
    void prepare(){
        dirY = {1, -1, 0, 0};
        dirX = {0, 0, 1, -1};
        maxArea = 0;
    }
    
    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void dfs(vector<vector<int>>& grid, int &m, int &n, int i, int j, int &count){
        count++;
        maxArea = max(maxArea, count);
        grid[i][j]=0;
        for(int k=0; k<4; k++){
            int newi = i + dirY[k];
            int newj = j + dirX[k];
            if(isValid(newi, newj, m, n) && grid[newi][newj]){
                dfs(grid, m, n, newi, newj, count);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size(), count=0;
        if(!n) return 0;
        
        prepare();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                count = 0;
                if(grid[i][j]){
                    dfs(grid, m, n, i, j, count);
                }
            }
        }
        return maxArea;
    }
};