// https://leetcode.com/problems/candy/

class Solution {
    void populateLVec(vector<int>& rate, vector<int>& dirVec, int n) {
        for(int i=1; i<n; i++) {
            if(rate[i]>rate[i-1]) {
                dirVec[i] = dirVec[i-1]+1;
            }
        }
    }
    
    void populateRVec(vector<int>& rate, vector<int>& dirVec, int n) {
        for(int i=n-2; i>=0; i--) {
            if(rate[i]>rate[i+1]) {
                dirVec[i] = dirVec[i+1]+1;
            }
        }
    }
    
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), reqdCandies=0;
        
        vector<int> lVec(n, 1);
        vector<int> rVec(n, 1);
        
        populateLVec(ratings, lVec, n);
        populateRVec(ratings, rVec, n);
        
        for(int i=0; i<n; i++) {
            reqdCandies += max(lVec[i], rVec[i]);
        }
        
        return reqdCandies;
    }
};