#include <bits/stdc++.h>
using namespace std;

#define loopi(i,a,b) for(int i=a; i<b; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int maxi = 1e9+1;
const int N = 5;

vector<vector<int>> adj;
vector<vector<int>> sDistAll;
vector<int> sdist;
vector<tuple<int, int, int>> edges;

void prepAdj() {
	adj = {{0,100,1,0,0}, {100,0,5,2,0}, {1,5,0,0,0}, {0,2,0,0,3}, {0,0,0,3,0}};
    
    loopi(i,0,N) 
        sdist.PB(maxi);

    loopi(i,0,N)
        loopi(j,0,N)
            if(adj[i][j])
                edges.PB({-adj[i][j],i,j});
}

void bford(int src) {
    sdist[src]=0;
    sort(edges.begin(), edges.end());
    loopi(i,0,N)
        for(auto e: edges) {
            int a,b,w;
            tie(w,a,b) = e;
            sdist[b] = min(sdist[b], sdist[a]-w);
        }
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
    bford(0);
    printIntVec(sdist);
	return 0;
}