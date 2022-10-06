// https://www.interviewbit.com/problems/distribute-candy/
// good editorial
// coming to the solution is tricky

int Solution::candy(vector<int> &A) {
    int n = A.size(), count =0;
    if(n<2){
        return n;
    }
    vector<int> candyCount(n, 1);
    for(int i=1; i<n; i++) {
        if(A[i] > A[i-1]) {
            candyCount[i] = candyCount[i-1] + 1;
        }
    }
    int temp = 0;
    for(int i=n-2; i>=0; i--) {
        if(A[i] > A[i+1] && candyCount[i] <= candyCount[i+1]) {
            candyCount[i] = candyCount[i+1] + 1;
        }
    }
    for(int i=0; i<n; i++) {
        count += candyCount[i];
    }
    return count;
}

// Acc to hint for greedy
// int Solution::candy(vector<int> &A) {
//     priority_queue<pair<int, int>> pq;
//     int n = A.size();
//     for(int i=0; i<n; i++) {
//         pq.push({-A[i], i});
//     }
//     int ans = 0;
//     vector<int> candies(n, 0);
//     while(!pq.empty()) {
//         int val, index;
//         tie(val, index) = pq.top();
//         pq.pop();
        
//         int maxNbd = 1;
//         if(index>0) {
//             int lCandy = A[index]==A[index-1]? candies[index-1]:candies[index-1]+1;
//             maxNbd = max(maxNbd, lCandy);
//         }
//         if(index<n-1) {
//             int rCandy = A[index]==A[index+1]? candies[index+1]:candies[index+1]+1;
//             maxNbd = max(maxNbd, rCandy);
//         }
//         candies[index] = maxNbd;
//         ans += candies[index];
//     }
//     return ans;
// }