// https://leetcode.com/problems/course-schedule-ii/
// nice prob - Topo sort and find order
// extension of 207. // https://leetcode.com/problems/course-schedule/
// topo logic from tushar Roy. Code logic from geeks. impl self
// do DFS search -> once node is vis and processed for children -> push to stack -> pop correct order

class Solution {
public:
    
    bool wrong;
    vector<bool> vis;
    vector<bool> inSt;
    vector<vector<int> > adj;
    vector<int> topo;
    
    void DFS(int par)   //vector<vector<int> > &adj, 
    {
        vis[par]=1;
        inSt[par]=1;
        int i,n=adj[par].size(),ind;
        for(i=0;i<n;i++)
        {
            ind=adj[par][i];
            if(vis[ind] && inSt[ind]) 
                wrong=1;
            if(!vis[ind])
                DFS(ind);
        }
        inSt[par]=0;
        topo.push_back(par);
    }
    
    void reverseTopo(){
        int n = topo.size();
        for(int i=0; i<n/2; i++) {
            swap(topo[i], topo[n-1-i]);
        }
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        wrong=0;
        vis.resize(n);
        inSt.resize(n);
        adj.resize(n);
        topo.clear();
        
        int x,y,i,e=pre.size();
        for(i=0;i<e;i++)
        {
            x=pre[i][0];
            y=pre[i][1];
            adj[y].push_back(x);            
        }
        
        for(i=0;i<n;i++)
        {
            if(wrong)   break;
            if(!vis[i])
                DFS(i);
        }
        
        if(wrong){
            return {};
        }   
        else {
            reverseTopo();
            return topo;
        }
    }
};