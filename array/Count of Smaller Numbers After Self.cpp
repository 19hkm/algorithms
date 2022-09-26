// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#define PB push_back
class Solution {
public:
    
    void merge(vector<pair<int, int>>& numsAndCountVec)
    
    void mergeSortAndCountInversions(vector<pair<int, int>>& numsAndCountVec, int beg, int end) {
        if(beg!=end){
            int mid = (beg+end)/2;
            mergeSortAndCountInversions(numsAndCountVec, beg, mid);
            mergeSortAndCountInversions(numsAndCountVec, mid+1, end);
            merge(numsAndCountVec, beg, end, mid);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> numsAndCountVec;
        for(auto num : nums) {
            numsCountVec.PB({num, 0});
        }
        mergeSortAndCountInversions(numsAndCountVec, 0, nums.size());
        
    }
};