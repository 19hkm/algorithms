public int findPivot(int[] arr) {
        int n=arr.length, b=1, e=n-1, mid=0;
        if(n==1 || arr[0]<arr[e]) return arr[0];
        while(b<=e) {
            mid = b + (e-b)/2;
            if(arr[mid-1]>arr[mid]) break;
            else if(arr[mid]>arr[0]) b=mid+1;
            else e=mid-1;
        }
        return mid;
    }