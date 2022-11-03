// https://leetcode.com/problems/maximal-square/
// 221. Maximal Square


// Method 1: for a row find the max height for each col. Then do max square/rectangle in histogram


// Mehtod 2: editorial -> python poictorial solution for logic 
class Solution {
    bool isValid(int i, int j, int n, int m) {
        return i<n && i>=0 && j<m && j>=0;
    }
    
    int dirX[3]= {-1, -1, 0}; // related to j, m
    int dirY[3]= {0, -1, -1}; // related to i, n
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), maxLen = 0; // rows -> i
        if(!n) {
            return maxLen;
        }
        int m = matrix[0].size();   //columns -> j
        if(!m) {
            return maxLen;
        }
        vector<vector<int>> sqLen(n, vector<int>(m, n));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') {
                    for(int k=0; k<3; k++) {
                        int nbdX = j+dirX[k];
                        int nbdY = i+dirY[k];
                        if(!isValid(nbdY, nbdX, n, m)) {
                            sqLen[i][j] = 0;
                        } else {
                            sqLen[i][j] = min(sqLen[i][j], sqLen[nbdY][nbdX]);
                        }
                    }
                    sqLen[i][j]++;
                    maxLen = max(maxLen, sqLen[i][j]);
                } else {
                    sqLen[i][j] = 0;
                }
            }
        }
        
        return maxLen*maxLen;
    }
};