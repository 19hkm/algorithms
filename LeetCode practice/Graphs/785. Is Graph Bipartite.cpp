// https://leetcode.com/problems/is-graph-bipartite/
// regular un-directed graph bipartite check

class Solution {
    
    bool isDFSBranchBipartite(int src, vector<vector<int>>& graph, vector<int> &color) {
        int nextColor = (color[src]+1)%2;
        for(auto tar : graph[src]) {
            if(color[tar]==color[src]){
                return false;
            }
            
            if(color[tar]==-1) {
                color[tar] = nextColor;
                if(!isDFSBranchBipartite(tar, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), i;
        
        if(n<2) {
            return true;
        }
        vector<int> color(n,-1);
        
        for(i=0; i<n; i++) {
            if(color[i] == -1) {
                color[i]=0;
                if(!isDFSBranchBipartite(i, graph, color)) {
                    return false;
                }
            }    
        }
        return true;
    }
};
