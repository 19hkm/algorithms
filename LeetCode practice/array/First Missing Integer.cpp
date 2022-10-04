// very nice to learn manipulation of array
// store result in same array to minimise new space 
// great corner cases
// first See if 1 !exists -> means result. If exists then can be used to replace outliers

// https://www.interviewbit.com/problems/first-missing-integer/

bool isOneExists(vector<int> &A) {
    for(auto a : A) {
        if(a==1)
            return true;
    }
    return false;
}

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    if(!n || (n==1 && A[0]==0) || !isOneExists(A)) {
        return 1;
    }
    
    //clean the vector
    for(int i=0; i<n; i++) {
        if(A[i]<=0 || A[i]>n) {
            A[i]=1;
        }
    }
    
    for(int i=0; i<n; i++) {
        int j = A[i]%n;
        A[j]+=n;
    }
    
    for(int i=1; i<n; i++) {
        if(A[i]/n==0)
            return i;
    }
    if(A[0]/n==0){
        return n;
    }
    return n+1;
}


