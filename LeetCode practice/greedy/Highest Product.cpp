// https://www.interviewbit.com/problems/highest-product/
// Good prob: when talking about max pdt -> always think of negative nos too
// -1 * -1  = pos

// method 1 - sort and handle the last 3 and first2 elements
// O(nlogn) time and O(n) space

// method 2. Use2 pqs 
//  O(nlog4) -> o(n) time and O(7) -> O(1) addn space
int Solution::maxp3(vector<int> &A) {
    priority_queue<int> ipq;
    priority_queue<int> dpq;
    for(auto num : A) {
        ipq.push(-num);
        dpq.push(num);
        if(ipq.size()>3) {
            ipq.pop();
        }
        if(dpq.size()>2) {
            dpq.pop();
        }
    }
    int last3pdt=1, first2pdt=1, lastElem;
    for(int i=0; i<3; i++) {
        int num = -1* ipq.top();
        ipq.pop();
        
        last3pdt *= num;
        if(i==2) {
            lastElem = num;
        }
    }
    while(!dpq.empty()) {
        first2pdt *= dpq.top();
        dpq.pop();
    }
    first2pdt *= lastElem;
    
    return max(first2pdt, last3pdt);
}
