//DFS
#include <iostream>
using namespace std;

#define MAXI = 1e9+1;
#define MINI = 0;

void dfs(int adj[][4], bool isVisited[], int src) {
	if(!isVisited[src]) {
		isVisited[src]= true;
		for(int i=0; i<4 ; i++){
			if(adj[src][i] && !isVisited[i]){
				dfs(adj, isVisited, i);
			}
		}
	}
}

void printArray(bool *array, int n) {
	for(int i=0; i<n; i++){
		cout<<*(array+i)<<" ";
	}
	cout<<endl;
}

int main() {
	int arr[][4] = {{0,1,1,0}, {1,0,1,0}, {1,1,0,0}, {0,0,0,0}};
	bool isVisited[4]={0};
	
	printArray(isVisited, 4);
	
	for(int i=0 ;i<4; i++) {
		cout<<isVisited[i]<<" ";
	} cout<<endl;
	
	dfs(arr, isVisited, 0);
	
	printArray(isVisited, 4);
	
	for(int i=0 ;i<4; i++) {
		cout<<isVisited[i]<<" ";
	} 
	cout<<endl;
	
	return 0;
}