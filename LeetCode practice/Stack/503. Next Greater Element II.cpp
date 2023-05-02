// 503. Next Greater Element II - easy
// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int i=0, n=nums.size();
        
        vector<int> ans(n, -1);
        for(int j=0; j<2; j++) {
            for(int i=n-1; i>=0; i--) {
                if(st.empty()) {
                    st.push(nums[i]);
                } else if(nums[i]<st.top()) {
                    ans[i] = st.top();
                    st.push(nums[i]);
                } else {
                    while(!st.empty() && st.top()<=nums[i])
                        st.pop();
                    if(!st.empty()) {
                        ans[i] = st.top();
                    }
                    st.push(nums[i]);
                }
            }
        }
        
        return ans;
    }
};
