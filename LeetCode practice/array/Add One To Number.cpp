// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    
    int n = A.size(), i;
    if(!n) return A;
    
    stack<int> reverseAdded;
    
    int carry = (A[n-1]+1)/10;
    reverseAdded.push((A[n-1]+1)%10);
    
    for(int i=n-2; i>=0; i--) {
        int sum  = carry + A[i];
        reverseAdded.push((sum)%10);
        carry = sum/10;
    }
    
    if(carry) {
        reverseAdded.push(carry);
    }
    
    while(!reverseAdded.empty() && reverseAdded.top()==0) {
        reverseAdded.pop();
    }
    
    vector<int> ans;
    while(!reverseAdded.empty()) {
        ans.push_back(reverseAdded.top());
        reverseAdded.pop();
    }
    
    return ans;
}
