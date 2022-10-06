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



// method 2: union-find disjoint sets
// poor solution - more space and time complexity
class Solution {
    int findPar(int src, vector<int> &par) {
        while(par[src] != src) {
            src = par[src];
        }
        return src;
    }
    
    void unionNodes(int a, int b, vector<int> &par, vector<int> &cSize) {
        if(cSize[a]>=cSize[b]){
            par[b] = a;
            cSize[a] += cSize[b];
        } else {
            par[a] = b;
            cSize[b] += cSize[a];
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        if(n<2) {
            return n;
        }
        vector<int> par(n);
        vector<int> cSize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j]) {
                    int parI = findPar(i, par);
                    int parJ = findPar(j, par);
                    if(parI != parJ) {
                        unionNodes(parI, parJ, par, cSize);
                    }
                }
            }
        }
        
        set<int> distPars;
        for(int i=0; i<n; i++){
            int parentI = findPar(i, par);
            distPars.insert(parentI);
        }
        return distPars.size();
    }
};