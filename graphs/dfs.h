void dfs(int src, vector<bool> &isVis) {
	if(!isVis[src]) {
		isVis[src] = 1;
		for(int i=0 ;i<adj[src].size(); i++) {
			if(!isVis[i] && adj[src][i]) {
				dfs(i, isVis);
			}
		}
	}	
}
