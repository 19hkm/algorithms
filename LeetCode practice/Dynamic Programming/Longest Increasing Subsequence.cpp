https://www.interviewbit.com/problems/longest-increasing-subsequence/
// trivial problem

int Solution::lis(const vector<int> &A) 
{
    int n=A.size(),i,j,maxi=1;  
    if(!n) return n;
    
    vector<int> lis(n, 1);
    for(i=1; i<n; i++) {
        for(j=i-1; j>=0; j--) {
            if(A[j]<A[i] && lis[i]<=lis[j]) {
                lis[i] = lis[j]+1;
                maxi = max(maxi, lis[i]);
            }
        }
    }
    return maxi;
}
