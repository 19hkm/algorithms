// https://leetcode.com/problems/rotting-oranges/
// good problem

// Method 1: do BFS from each node - O((numOf2s)*(m*n))


// Method 2 : create adj matrix for each of the m*n elements and do floyd-warshall
// Extra space : m*n = N total num of nodes. So O(N*N) space
// O(N^3) time

// Method 3: multiple source BFS
// O(n.m) - total node time

class Solution {
    const int INF_TIME= 1e5+1;
    const int dirY[4] = {1, -1, 0, 0};
    const int dirX[4] = {0, 0, 1, -1};
    
public:

    bool isValidCell(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j<m ;
    }


    void minDisForEachPair(vector<vector<int>>& grid, vector<vector<int>> &rotTime, int n, int m) {
        
        priority_queue<tuple<int, int, int>> pq;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) {
                    pq.push({0, i, j});
                    // rotTime[i][j] = 0;
                } else {
                    // rotTime[i][j] = INF_TIME;
                }
                rotTime[i][j] = INF_TIME;
            }
        }

        while(!pq.empty()) {
            int w, i, j;
            tie(w,i,j) = pq.top();
            pq.pop();

            if(-w >= rotTime[i][j]) {
                continue;
            }
            rotTime[i][j] = -w;
            
            for(int k=0; k<4; k++) {
                int nextI = i + dirY[k];
                int nextJ = j + dirX[k];

                if(isValidCell(nextI, nextJ, n, m) && grid[nextI][nextJ]==1 && rotTime[nextI][nextJ] > rotTime[i][j]+1) {
                    int nextW = rotTime[i][j]+1;
                    // rotTime[nextI][nextJ] = nextW;
                    pq.push({-nextW, nextI, nextJ});
                }
            }
        } 
    }
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // rows
        if(!n) {
            return -1;
        }
        int m = grid[0].size(); // columns
        vector<vector<int>> rotTime(n, vector<int>(m));
        minDisForEachPair(grid, rotTime, n, m);
        
        int maxTimeAns = 0;
        
        for(int i=0 ;i<n ;i++) {
            for(int j=0; j<m ;j++) {
                if(grid[i][j]==1) {
                    if(rotTime[i][j] == INF_TIME){
                        return -1;
                    } else {
                        maxTimeAns = max(maxTimeAns, rotTime[i][j]);
                    }
                } 
            }
        }
        
        return maxTimeAns;
    }
};

