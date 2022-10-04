// https://leetcode.com/problems/course-schedule/
// nice prob to detect if cycle in directed graph - verify DAG

class Solution {
public:
    bool wrong;
    vector<bool> vis;
    vector<bool> inSt;
    vector<vector<int> > adj;
    
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
    }
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        wrong=0;
        vis.resize(n);
        inSt.resize(n);
        adj.resize(n);
        int x,y,i,e=pre.size();
        wrong=0;
        for(i=0;i<e;i++)
        {
            x=pre[i][0];
            y=pre[i][1];
            adj[y].push_back(x);            
        }
        for(i=0;i<n;i++)
        {
            if(wrong)   return 0;
            if(!vis[i])
                DFS(i);
        }
        return 1;
    }
};
