// nice -prob
// https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    vector<int> v;
    int maxZero=0, currZero=0, currOne=0, n=A.length(), i;
    for(i=0; i<n; i++) {
        if(A[i]=='1') {
            currOne++;
        } else {
            currZero++;
        }
    
        if(currZero<currOne) {
            currZero=0;
            currOne=0;
        } else if(currZero-currOne>maxZero) {
            v = {i-currZero-currOne+2, i+1};
            maxZero = currZero-currOne;
        }
    }
    return v;
}
