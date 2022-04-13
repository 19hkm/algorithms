class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea= 0;
        
        stack< pair<int, int> > st;
        
        for(int h : heights) {
            if(st.empty() ){
                st.push({h,1});
                maxArea = max(maxArea, h);
            } else {
                pair<int, int> topElem = st.top();
                if(h > topElem.first){
                    st.push({h,1});
                    maxArea = max(maxArea, h);
                } 
                else {
                    int count = 0;
                    while(h <= topElem.first){
                        count += topElem.second;
                        maxArea = max(maxArea, count*topElem.first);
                        st.pop();
                        if(st.empty()) break;
                        else topElem = st.top();
                    }
                    count++;
                    maxArea = max(maxArea, count*h);
                    st.push({h, count});
                }
            }
        }
        
        
        int prevCount =0;
        while(!st.empty()) {
            pair<int, int> topElem = st.top();
            prevCount += topElem.second;
            maxArea = max(maxArea, topElem.first * prevCount);
            st.pop();
        }
        return maxArea;
    }
};