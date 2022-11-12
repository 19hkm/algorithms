// 871. Minimum Number of Refueling Stops
// https://leetcode.com/problems/minimum-number-of-refueling-stops/
// not difficult but tricky

class Solution {
public:
    int minRefuelStops(int target, int sF, vector<vector<int>>& st) {
        int currDis = 0, currFuel = sF, n = st.size(), i=0, count=0;
        
        // the last stop can be added with no fuel station
        st.push_back({target, 0});
        n++;
        // select the highest fuel station crossed so far
        priority_queue<int> pq;
        
        while(currDis < target && i<n) {
            int nextDis = st[i][0], nextFuel = st[i][1];
            currFuel -= (nextDis-currDis);
            
            while(!pq.empty() && currFuel < 0) {
                int refuel = pq.top();
                pq.pop();
                currFuel += refuel;
                count++;
            }

            if(currFuel<0) {
                return -1;
            }
            
            currDis = nextDis;
            pq.push(nextFuel);
            i++;
        } 
        return count;
    }
};