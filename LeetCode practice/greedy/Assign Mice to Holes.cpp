// https://www.interviewbit.com/problems/assign-mice-to-holes/
// V. easy -> greedy approach
// if moves to wrong hole at dist x, then someone has to walk addn 2*x => think

int Solution::mice(vector<int> &A, vector<int> &B) {
    int mini = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<A.size(); i++) {
        mini = max(mini, abs(A[i]-B[i]));
    }
    return mini;
}
