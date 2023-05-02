https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

typedef long long ll;
const ll maxi = 1e9+7;

int Solution::chordCnt(int A) { 
    ll ans = 0;
    vector<ll> dp(A+1, 1);
    for(int i=1; i<=A; i++) {
        ll num = 0;
        for(int j=0; j<i; j++) {
            int k = i-1-j;
            num = (num + (dp[j]*dp[k]) % maxi) % maxi;        
        }
        dp[i]=num;
    }   
    return dp[A];
}