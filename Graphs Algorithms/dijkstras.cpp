#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second

const int maxi = 1e9+1;

// vector<vector<pair<int, int>>> adj;
vector<vector<int>> adj;

void prepAdj() {
	adj = {{0,100,1,0,0}, {100,0,5,2,0}, {1,5,0,0,0}, {0,2,0,0,3}, {0,0,0,3,0}};
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

void dijk(int k, vector<bool> &isVis, vector<int> &sDist) {
    int n = isVis.size();
    priority_queue<pair<int, int>> pq;
    while(!pq.empty()) pq.pop();

    pq.push({0,k});
    sDist[k]=0;

    while(!pq.empty()) {
        int srcW  = -pq.top().F;
        int srcIndex =  pq.top().S;
        pq.pop();
        isVis[srcIndex]=1;

        for(int j=0; j<n; j++) {
            if(adj[srcIndex][j]!=0 && !isVis[j]) {
                int wt = srcW + adj[srcIndex][j];
                if(wt < sDist[j]) {
                    sDist[j] = wt;
                    pq.push({-wt, j});
                }
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
	vector<int> sDis(adj.size(), maxi);

	dijk(0, isVis, sDis);
	printBoolVec(isVis);
    printIntVec(sDis);
	
	return 0;
}