// 128. Longest Consecutive Sequence  - Very nice question
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    unordered_set<int> numSet;
    
    int dfs(int val){
        numSet.erase(val);
        int dfsCount=1;
        if(numSet.find(val-1) != numSet.end())
            dfsCount += dfs(val-1);
        if(numSet.find(val+1) != numSet.end())
            dfsCount += dfs(val+1);
        return dfsCount;
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        numSet.clear();
        for(auto val: nums){
            numSet.insert(val);
        }
        int countMax=0;
        while(numSet.size()){
            int val = *numSet.begin();
            int count = dfs(val);
            countMax = count>countMax? count:countMax;
        }
        return countMax;
    }
};