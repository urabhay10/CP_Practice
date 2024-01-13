//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n-2;
        int mid;
        while(end-start>0){
            mid = (start+end)/2;
            if(arr[mid+1]>arr[mid]){
                start = mid+1;
            }else {
                end = mid;
            }
        }
        return start;
    }
};