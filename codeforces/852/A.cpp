#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,b,n,m,ans1,ans2,ans3;
        cin>>a>>b>>n>>m;

        ans1 = b*n;
        ans2 = (n/(m+1))*a*m + (n%(m+1))*a;
        ans3 = (n/(m+1))*a*m + (n%(m+1))*b;

        cout<<min(ans1, min(ans2, ans3))<<endl;
    }
    return 0;
}