/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) 
{
    vector<int> beg;
    vector<int> end;
    
    for(auto slot : A) {
        beg.push_back(slot.start);
        beg.push_back(slot.end);
    }
    
    sort(beg.begin(), beg.end());
    sort(end.begin(), end.end());
    
    int count=0, beginTime, endTime, begi=0, endi=0, n=A.size();
    vector<Interval> mergedInterval;
    
    while(begi<n && endi<n) {
        if(beg[begi] <= end[endi]) {
            if(!count) {
                beginTime = beg[begi];
            }
            count++;
            begi++;
        } else {
            count--;
            if(!count) {
                endTime = end[endi];
                Interval currMergedInterval = {beginTime, endTime};
                mergedInterval.push_back(currMergedInterval);
            }
            endi++;
        }
    }