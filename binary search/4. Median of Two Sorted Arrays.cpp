// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// V. Difficult if to be done in O(log(m+n)) time. Only half test cases passing

class Solution {
    const double MAXI = 1e6+7;
public:

    int smallerCount(vector<int>& nums, int num) {
        int n=nums.size(), beg=0, end=n-1, mid, count = 0;
        while(beg<=end) {
            mid = (beg+end)/2;
            if(nums[mid] <= num) {
                count = mid+1;
                beg = mid+1;
            } else {
                end = mid-1;
            }
        }
        return count;
    }

    double findMedian(vector<int>& nums1, vector<int>& nums2, int tarSmallCount) {
        int n1=nums1.size(), beg=0, end=n1-1, mid;
        int n2 = nums2.size(), currCount=0;
        while(tarSmallCount != currCount && beg <= end) {
            mid = (beg+end)/2;
            currCount = mid;
            currCount += smallerCount(nums2, nums1[mid]);
            if(tarSmallCount == currCount) {
                return nums1[mid];
            } else if(currCount<tarSmallCount) {
                beg = mid+1;
            } else {
                end = mid-1;
            }
        }
        return MAXI;
    }

    double findForOdd(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2 = nums2.size();
        int tarSmallCount = (n1+n2)/2;

        double nums1Med = findMedian(nums1, nums2, tarSmallCount);
        if(nums1Med==tarSmallCount) {
            return nums1Med;
        }
        double nums2Med = findMedian(nums2, nums1, tarSmallCount);
        return nums2Med;
    }

    double findForEven(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2 = nums2.size();
        int tarSmallCount = (n1+n2)/2;

        double nums1Med = findMedian(nums1, nums2, tarSmallCount);
        double nums2Med = findMedian(nums2, nums1, tarSmallCount-1);
        if(nums2Med != MAXI && nums1Med != MAXI) {
            return (nums1Med + nums2Med)/2;
        } else {
            return (findMedian(nums1, nums2, tarSmallCount-1) + findMedian(nums2, nums1, tarSmallCount))/2;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2 = nums2.size();

        if((n1+n2)%2) {
            return findForOdd(nums1, nums2);
        } else {
            return findForEven(nums1, nums2);
        }
    }
};