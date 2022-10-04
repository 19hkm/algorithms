// nice problem
// https://www.interviewbit.com/problems/max-distance/

int findLowerBound( vector<pair<int, int>> &v, int val) {
    int beg = 0, end = v.size()-1, mid, ans = -1;
    while(beg<=end) {
        mid = (beg+end)/2;
        if(v[mid].first<=val) {
            ans = v[mid].second;
            end = mid-1;
        } else {
            beg = mid+1;
        }
    }
    return ans;
}

int Solution::maximumGap(const vector<int> &A) {
    
    vector<pair<int, int>> decVec;
    int count=0, maxDist = 0;
    for(int i=0; i<A.size(); i++) {
        if(!count || decVec[count-1].first>A[i]) {
            decVec.push_back({A[i], i});
            count++;
        } else {
            int smallIndex = findLowerBound(decVec, A[i]);
            if(smallIndex != -1){
                maxDist = max(maxDist, i-smallIndex);
            }
        } 
    }
    return maxDist;
}




Soln : 2
int Solution::maximumGap(const vector<int> &A) 
{
    int n,i,j,ans=-1;
    n=A.size();
   vector<pair<int,int>> arr;
    for(i=0;i<n;i++)
        arr.push_back(make_pair(A[i],i));
        //{arr[i].first=A[i];arr[i].second=i;}
    sort(arr.begin(),arr.end());
    int maxi[n], mini[n];
    mini[0]=arr[0].second;
    maxi[n-1]=arr[n-1].second;
    for(i=1;i<n;i++)
        mini[i]=min(arr[i].second,mini[i-1]);
    for(i=n-2;i>=0;i--)
        maxi[i]=max(arr[i].second,maxi[i+1]);
    for(i=0;i<n;i++)
        ans=max(ans,maxi[i]-mini[i]);
    return ans;
}