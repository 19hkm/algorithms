// Good problem
// https://leetcode.com/problems/maximum-product-subarray/submissions/

// first tried splitting into sub-array and evaluating. VIewed hint -> single iteration

#define PB push_back
typedef long long ll;
class Solution {
public:


    int maxProduct(vector<int>& nums) {
//         vector<int> zeroLoc;
//         zeroLoc.PB(-1);
//         findZeroLocations(nums, zeroLoc);
        
//         int n = nums.size();
//         ll ans = 0;
//         zeroLoc.PB(n);
        
//         for(int i=0; i<zeroLoc.size()-1;i++) {
//             int beg = zeroLoc[i]+1;
//             int end = zeroLoc[i+1]-1;
            
//             ans = max(ans, findMaxPdt(nums, beg, end));
//         }
        int n = nums.size();
        if(!n) {
            return 0;
        }
        
        ll ans=nums[0], maxi=ans, mini=ans;
        
        for(int i=1; i<n ;i++) {
            ll numi = nums[i];
            if(numi<0) {
                swap(maxi, mini);
            }
            maxi = max(numi, maxi*numi);
            mini = min(numi, mini*numi);
            ans = max(ans, maxi);
        }
        return (int)ans;        
    }
};
    
//     int countNegNums(vector<int>& nums, int beg, int end) {
//         int count=0;
//         for(int i=beg; i<=end; i++){
//             if(nums[i]<0)
//                 count++;
//         }
//         return count;
//     }
    
//     void findZeroLocations(vector<int>& nums, vector<int>& zeroLoc) {
//         int n = nums.size();
//         for(int i=0; i<n; i++) {
//             if(!nums[i])
//               zeroLoc.push_back(i);  
//         }
//     }
    
//     ll findTotalPdt(vector<int>& nums, int beg, int end) {
//         ll ans =1;
//         for(int i=beg; i<=end; i++) 
//             ans = ans*nums[i];
//         return ans;
//     }
    
//     ll findLPdt(vector<int>& nums, int beg, int end, ll total) {
//         ll ans = 1;
//         int i=beg;
//         while(nums[i]>0) 
//             ans = ans*nums[i++];
//         return max(ans, (total/ans)/nums[i]);
//     }
    
//     ll findRPdt(vector<int>& nums, int beg, int end, ll total) {
//         ll ans = 1;
//         int i=end;
//         while(nums[i]>0) 
//             ans = ans*nums[i--];
//         return max(ans, (total/ans)/nums[i]);
//     }
    
    
//     ll findMaxPdt(vector<int>& nums, int beg, int end) {
//         ll maxi=nums[beg], mini=nums[beg];
//         ll zero = 0;
//         for(int i= beg+1; i<=end; i++) {
//             if(nums[i]<0) {
//                 swap(maxi, mini);
//             }
//             maxi = maxi*nums[i];
//             mini = mini*nums[i];
//         }
//         return max(maxi, );
//         // ll totalPdt = findTotalPdt(nums, beg, end);
//         // if(totalPdt>0) return totalPdt;
//         // else return max(findLPdt(nums, beg, end, totalPdt), findRPdt(nums, beg, end, totalPdt));
//     }
    
//     int maxProduct(vector<int>& nums, int beg, int end) {
//         int negNums= countNegNums(nums, beg, end);
//         int 
//     }
    