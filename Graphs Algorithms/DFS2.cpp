#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

vector<vector<int>> adj;

void prepAdj() {
	adj = {{0,1,1,0,0}, {1,0,1,0,0}, {1,1,0,0,0}, {0,0,0,0,1},{0,0,0,1,0}};
}

void printAdj() {
	cout<<"printing adj list\n";
	for(int i=0 ;i<adj.size(); i++) {
		for(int j=0; j<adj[i].size(); j++) {
			cout<< adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

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

 
void printVec(vector<bool> &v) {
	cout<<"printing visited nodes\n";
	for(int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}


int main() {
	prepAdj();
	printAdj();
	
	vector<bool> isVis(adj.size(), 0);
	printVec(isVis);
	
	dfs(0, isVis);
	printVec(isVis);
	
	dfs(3, isVis);
	printVec(isVis);
	
	return 0;
}