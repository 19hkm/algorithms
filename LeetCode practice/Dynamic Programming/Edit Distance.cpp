// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) 
{
    int n1=A.length(),n2=B.length(),i,j;
    int dp[n1+1][n2+1];
    for(i=0;i<n1+1;i++)
    {
        for(j=0;j<n2+1;j++)
        {
            if(!i){
                dp[i][j]=j;
            } else if(!j) {
                dp[i][j]=i;
            } else if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1;
                dp[i][j] += min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    return dp[n1][n2];
}
