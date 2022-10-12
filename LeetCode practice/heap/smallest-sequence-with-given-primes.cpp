// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/


// Time complexity : O(D), space: O(3^D)
// not the best soln
// Method 1: heap
#define PB push
#define PBK push_back

vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int> unique_nums;
    priority_queue<int> pq;
    pq.PB(-A);
    pq.PB(-B);
    pq.PB(-C);
    int count=0;
    while(count != D) {
        int topElem = pq.top();
        pq.pop();
        if(unique_nums.find(-topElem) == unique_nums.end()) {
            pq.PB(topElem*A);
            pq.PB(topElem*B);
            pq.PB(topElem*C);
            unique_nums.insert(-topElem);
            count++;  
        }
    }
    vector<int> nums(unique_nums.begin(), unique_nums.end());
    return nums;
}



// Time complexity : O(D), space: O(1)
// not the best soln
// Method 1: dynamic prog
