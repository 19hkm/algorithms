#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

// #define vector<bool> vBool 
// #define vector<int> vInt 

const int maxi = 1e9+1;

vector<vector<int>> adj;

void prepAdj() {
	adj = {{0,1,1,0,0}, {1,0,1,1,0}, {1,1,0,0,0}, {0,1,0,0,1}, {0,0,0,1,0}};
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

void bfs(int k, vector<bool> &isVis, vector<int> &sDist) {
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(k);
    int n = isVis.size();
    sDist[k]=0;
    isVis[k]=1;

    while(!q.empty()) {
        int src  = q.front(); 
        q.pop();
        for(int j=0; j<n; j++) {
            if(adj[src][j] && !isVis[j]) {
                sDist[j] = sDist[src]+1;
                isVis[j] = 1;
                q.push(j);
            }
        }
    }
}

void printBoolVec(vector<bool> &v) {
	cout<<"printing visited nodes\n";
	for(int i=0; i<v.size(); i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void printIntVec(vector<int> &v) {
	cout<<"printing distance nodes\n";
	for(auto a: v){
        cout<<a<<" ";
    }
	cout<<endl;
}

int main() {
	prepAdj();
	printAdj();
	
	vector<bool> isVis(adj.size(), 0);
	// printBoolVec(isVis);
	
	vector<int> sDis(adj.size(), maxi);
	// printIntVec(sDis);

	bfs(0, isVis, sDis);
	printBoolVec(isVis);
    printIntVec(sDis);
	
	// bfs(4, isVis, sDis);
	// printBoolVec(isVis);
    // printIntVec(sDis);
	
	return 0;
}