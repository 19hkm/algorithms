public int binarySearchIndex(int[] arr, int target) {
	Int b=0, e= arr.length, mid;
	While(b<=e) {
		Mid = (b+e)/2;
		If(arr[mid]==target) return mid;
		Else if(arr[mid] > target) e= mid-1;
		Else b=mid+1;
	}
	Return arr[mid]==target? Mid:-1;
}