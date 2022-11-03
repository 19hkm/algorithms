// 1094. Car Pooling
// https://leetcode.com/problems/car-pooling/

// Method 1: contagious array sum 
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> usedSeatsAtDist(1001, 0);
        for(int i=0; i<n; i++) {
            int w=trips[i][0], beg=trips[i][1], end=trips[i][2];
            usedSeatsAtDist[beg]+=w;
            usedSeatsAtDist[end]-=w;
        }
        int count=0;
        for(int i=0;i<1001;i++){
            count += usedSeatsAtDist[i];
            if(count>capacity){
                return false;
            }
        }
        return true;
    }
};