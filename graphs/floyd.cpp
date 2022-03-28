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

void prepAdj() {
	adj = {{0,100,1,0,0}, {100,0,5,2,0}, {1,5,0,0,0}, {0,2,0,0,3}, {0,0,0,3,0}};
    // sDistAll = vector<vector<int>>(N, vector<int>(N,maxi));
    
    sDistAll = vector<vector<int>>(adj);
    loopi(i,0,N) 
        loopi(j,0,N) 
            if(!sDistAll[i][j])
                sDistAll[i][j]= maxi;
    loopi(i,0,N) sDistAll[i][i]=0;
}

void printAdj() {
	cout<<"\nPrinting adj list\n";
	for(int i=0 ;i<N; i++) {
		for(int j=0; j<adj[i].size(); j++) {
			cout<< sDistAll[i][j]<<" ";
		}
		cout<<endl;
	}
}

void floyd(){
    loopi(k,0,N) 
        loopi(i,0,N) 
            loopi(j,0,N) 
                sDistAll[i][j]=min(sDistAll[i][j], sDistAll[i][k]+sDistAll[k][j]);
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
	
	// vector<bool> isVis(adj.size(), 0);
	// vector<int> sDis(adj.size(), maxi);

    floyd();
    printAdj();
	// dijk(0, isVis, sDis);
	// printBoolVec(isVis);
    // printIntVec(sDis);
	
	return 0;
}