// https://leetcode.com/problems/4sum/

#define PB push_back
#define POPB pop_back
#define I insert
typedef long long ll;
class Solution {
public:
    set<vector<int>> vecSet;
    vector<vector<int>> reqVec;
    
    void populateAllSubsetsOfLength(vector<int>& nums, int len, int marker, vector<int> &vec, ll &sum, ll &target) {
        if(len==2) {
            populateUsing2Sum(nums, marker, nums.size()-1, vec, target-sum);
            return;
        }
        if(marker>=nums.size()){
            return;
        }
        vec.PB(nums[marker]);
        sum += nums[marker];
        populateAllSubsetsOfLength(nums, len-1, marker+1, vec, sum, target);
        vec.POPB();
        sum -= nums[marker];
        populateAllSubsetsOfLength(nums, len, marker+1, vec, sum, target);
    }
    
    void populateUsing2Sum(vector<int>& nums, int beg, int end, vector<int> &vec, ll tar) {
        while(beg<end) {
            ll tempSum = nums[beg];
            tempSum+= nums[end];
            if(tempSum==tar){
                vector<int> v(vec);
                v.PB(nums[beg]);
                v.PB(nums[end]);
                vecSet.I(v);
            }
            if(tempSum<=tar) {
                beg++;
            } else {
                end--;
            }
        }
    }
    
    
    void putToVec() {
        for(auto vec: vecSet)
            reqVec.PB(vec);
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<int> v;
        ll sum =0;
        v.clear();
        vecSet.clear();
        reqVec.clear();
        if(nums.size()>=4){
            ll longTarget = target;
            populateAllSubsetsOfLength(nums, 4, 0, v, sum, longTarget);
            putToVec();
        }
        return reqVec;
    }
};