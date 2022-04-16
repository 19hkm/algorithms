// https://leetcode.com/problems/sort-colors/submissions/


//METHOD 1: worst case two passes, but generalised method to solve any number of colors
class Solution {
public:
    
    void sortByColor(vector<int>& nums, int val, int &beg){
        int curr = beg+1, n = nums.size();
        while(curr!=n){
            if(nums[curr] == val)
                swap(nums[++beg], nums[curr]);
            curr++;
        }
    }
    
    void sortColors(vector<int>& nums) {
        int whiteIndexEnd = -1;
        sortByColor(nums, 0, whiteIndexEnd);
        sortByColor(nums, 1, whiteIndexEnd);
    }
};


//METHOD 2: single pass. Keep 2 indices on either ends for both nums
class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int zeroIndexEnd = -1, twoIndexStart = nums.size(), curr = 0;
        while(curr != twoIndexStart){
            if(nums[curr] == 0)
                swap(nums[++zeroIndexEnd], nums[curr++]);
            else if(nums[curr] == 2)
                swap(nums[--twoIndexStart], nums[curr]);
            else curr++;
        }
    }
};

// IMP: https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions
// 2nd solution in this is the most beautiful clever Solution