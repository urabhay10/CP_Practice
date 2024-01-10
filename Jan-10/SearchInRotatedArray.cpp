//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//found pivot point, made new vector and implemented binary search
//new to binary search so i was having a address problem so i just watched 10 second of a binary search video again and then i was able to solve this problem
class Solution {
public:
    int returnIndex(vector<int>& nums){
        //returns the index till where the array is in non decreasing way 
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                return i;
            }
        }
        return 0;
    }
    bool search(vector<int>& nums, int target) {
        int pivot=returnIndex(nums);
        vector<int> numbers(nums.begin()+pivot,nums.end());
        for(int i=0;i<pivot;i++){
            numbers.push_back(nums[i]);
        }
        int start=0,end=numbers.size()-1;
        int mid;
        while(end-start>1){
            mid = (start+end)/2;
            if(numbers[mid]<target){
                start=mid+1;
            }else {
                end=mid;
            }
        }
        if(numbers[start]==target || numbers[end]==target){
            return true;
        }else {
            return false;
        }
    }
};