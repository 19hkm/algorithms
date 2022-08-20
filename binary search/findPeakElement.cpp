// From <https://leetcode.com/problems/find-peak-element/discuss/1822762/C%2B%2B-simple-binary-search> 

 int findPeakElement(vector<int>& nums) {
        int mid;
        int left= 0;
        int right= nums.size() - 1;
        
        if(nums.size() == 0)
            return-1;
        if(nums.size() == 1)
            return0;
        while(left< right) {
            mid = (left+ right)/2;
            if(nums[mid] > nums[mid + 1])
                    right= mid;
            else
                left= mid + 1;
        }
        return right;
    }
};
