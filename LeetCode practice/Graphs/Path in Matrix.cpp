// https://www.interviewbit.com/problems/path-in-matrix/

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
 
bool isValidNode(int i, int j, int n) {
    return i>=0 && j>=0 && i<n && j<n;
}

tuple<int, int> findNode(vector<vector<int> > &A, int n, int nodeNum) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] == nodeNum) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void dfs(vector<vector<int>> &A, vector<vector<int>> &isVis, const int n, int x, int y) {
    // valid cell, not a wall, not already visited
    if (isValidNode(x, y, n) && A[x][y] != 0 && isVis[x][y] == 0) {
        isVis[x][y] = 1;
        for (int i=0; i<4; i++) {
            int nextX = x + dirX[i];
            int nextY = y + dirY[i];
            dfs(A, isVis, n, nextX, nextY);
        }
    }
}

int Solution::checkPath(vector<vector<int> > &A) {
    
    int n = A.size();
    
    // find 1
    auto srcNode = findNode(A, n, 1);
    int srcX, srcY, destX, destY;
    tie(srcX, srcY) = srcNode;
    
    // find 2
    auto destNode = findNode(A, n, 2);
    
    // dfs from 1 -> travel full
    vector<vector<int>> isVis(n, vector<int>(n, 0));
    dfs(A, isVis, n, srcX, srcY);
    
    // see if 2 is visitable
    tie(destX, destY) = destNode;
    return isVis[destX][destY];
}
