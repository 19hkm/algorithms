// https://leetcode.com/problems/word-search/submissions/
// DFS + back-tracking

class Solution {
public:
    
    // m = num of rows. i dirY related
    // n = num of col. j dirX related
    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,1,-1};
    
    bool isFound = false;
    
    bool isValidCell(int i, int j, int m, int n) {
        return i<m && j<n && i>=0 && j>=0;
    }
    
        
    void findWordDFS(vector<vector<char>>& board, vector<vector<bool>>& isVisited, int i, int j, int m, int n, string &word, int cursorIndex) {
        if(isFound || isVisited[i][j] || board[i][j]!=word[cursorIndex]){
            return;
        }
        if(cursorIndex==word.length()-1){
            isFound = true;
            return;
        }
        isVisited[i][j]=1;
        for(int k=0 ; k<4 && !isFound; k++) {
            int nextI = i+dirY[k];
            int nextJ = j+dirX[k];
            if(isValidCell(nextI, nextJ, m, n)) {
                findWordDFS(board, isVisited, nextI, nextJ, m, n, word, cursorIndex+1);
            }
        }
        isVisited[i][j]=0;
    } 
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n;
        if(!m || board.empty()){
            return false;
        }
        n = board[0].size();
        if(!n){ 
            return false;
        }
        
        vector<vector<bool>> isVisited(m, vector<bool>(n,0));
        
        for(int i=0; i<m; i++) {
            for(int j=0;j<n;j++) {
                if(!isFound && board[i][j]==word[0]) {
                    findWordDFS(board, isVisited, i, j, m , n, word, 0);
                }
            }
        }
        
        return isFound;
    }
};