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
vector<tuple<int, int, int>> edges;
vector<int> par;
vector<int> parSize;

void prepAdj() {
	adj = {{0,100,1,0,0}, {100,0,5,2,0}, {1,5,0,0,0}, {0,2,0,0,3}, {0,0,0,3,0}};

    loopi(i,0,N)
        loopi(j,0,N)
            if(adj[i][j])
                edges.PB({adj[i][j],i,j});

    par = vector<int>(N, 0);
    loopi(i, 0, N) 
        par[i] = i;

    parSize = vector<int>(N,1);
}


// void printIntVec(vector<int> &v) {
// 	cout<<"printing distance nodes\n";
// 	for(auto a: v){
//         cout<<a<<" ";
//     }
// 	cout<<endl;
// }

int find( int src ) {
    cout<<"find: "<<src<<endl;
    loopi(i,0,N) cout<<par[i]<<" ";
    cout<<endl;

    loopi(i,0,N) cout<<parSize[i]<<" ";
    cout<<endl;

    while( par[src] != src){
        src = par[src];
    }
    return src;
}

void swap(int &i, int &j){
    i = i+j;
    j = i-j;
    i = i-j;
}

void unionNodes( int i, int j ) {
    cout<<"union: "<< i<< " "<< j<<endl;
    //prepare size of i>j 
    if(parSize[i] < parSize[j])
        swap(i,j);
    par[j] = i;
    parSize[i] = parSize[i]+parSize[j];
    return;
}


bool edgeComparator(auto a, auto b) {
    int w1 = std::get<0>(a);
    int w2 = std::get<0>(b);

    return w1<w2;
}

int main() {
	prepAdj();

    int ans=0;
    cout<<ans<<endl;
    sort(edges.begin(), edges.end(), edgeComparator);

    for(auto e: edges) {
        int a,b,w;
        tie(w,a,b) = e;
        int parA = find(a);
        int parB = find(b);
        if(parA != parB){
            ans += w;
            unionNodes(parA, parB);
        }
    }

    cout<<ans<<endl;
	return 0;
}