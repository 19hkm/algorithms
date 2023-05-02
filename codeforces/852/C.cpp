#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define PB push_back

int main() {
    int t;
    cin>>t;
    while(t--) {

        int n, mini=INT_MAX, maxi=INT_MIN, l=0,r,x; 
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            cin>>x;
            v.PB(x);
            if(mini>x)  mini = x;
            if(maxi<x)  maxi = x;
        }
        r=n-1;
        while(l<n && (v[l]==mini || v[l]==maxi)) l++;
        while(r>=0 && (v[r]==mini || v[r]==maxi)) r--;
        if(l<r) {
            cout<<l+1<<" "<<r+1<<endl;
        } else {
            cout<<"-1\n";
        }
    } 
    return 0; 
}