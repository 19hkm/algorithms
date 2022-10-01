//Good problem. Standard - SPOJ aggressive cows
// https://leetcode.com/problems/koko-eating-bananas/submissions/


#define PB push_back
typedef long long ll;
class Solution {
public:
    
    ll avgPileVal(vector<int>& piles, ll h) {
        int n = piles.size();
        ll sum=0;
        for(int i=0; i<n; i++) {
            sum += piles[i];
        }
        return sum/h;
    }
    
    int maxPileVal(vector<int>& piles) {
        int n = piles.size();
        int maxPile=0;
        for(int i=0; i<n; i++) {
            maxPile = max(maxPile, piles[i]);
        }
        return maxPile;
    }
    
    
    ll hrsToEatWithKVal(vector<int>& piles, int k) {
        int n = piles.size();
        ll hrs=0;
        for(int i=0; i<n; i++) {
           hrs += ((ll)(piles[i])+k-1)/k;
        }
        return hrs;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        ll minK = avgPileVal(piles, h);
        int maxK = maxPileVal(piles);
        int n=piles.size(), ansK=INT_MAX;
        
        ll beg=1, end=maxK;
        
        while(beg<=end) {
            ll mid = (beg+end)/2;
            ll kHrs = hrsToEatWithKVal(piles, mid);
            if(kHrs<=h) {
                ansK = mid;
                end = mid-1;
            } else {
                beg = mid+1;
            }
            
        }
        return ansK;
    }
};