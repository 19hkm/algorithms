// 684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    const int N = 1001;
    vector<int> par;
    vector<int> clusterSize;
    
    void prepareNodes(){
        par = vector<int>(N,0);
        clusterSize = vector<int>(N,0);
        
        for(int i=0; i<N; i++){
            par[i] = i;
            clusterSize[i] = 1;
        }
    }
    
    int findPar(int src) {
        while(par[src] != src)  
            src = par[src];
        return src;
    }
    
    void unionNodes(int a, int b){
        if(clusterSize[a] < clusterSize[b]) 
            swap(a,b);
        par[b] = a;
        clusterSize[a] += clusterSize[b];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        prepareNodes();
        for(auto edge: edges){
            int nodeA = edge[0];
            int nodeB = edge[1];
            
            int parA = findPar(nodeA);
            int parB = findPar(nodeB);
            
            if(parA == parB) return edge;
            else unionNodes(parA, parB);
        }
        return vector<int>(2,0);
    }
};