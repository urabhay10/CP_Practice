//https://leetcode.com/problems/median-of-two-sorted-arrays/
//i tried very hard to solve this problem and i did it 
//the logic was we will iterate both arrays together keeping track of current index and moving ahead where nums were shorter 
//until i was at mid then 2 different logics for even number array and odd number array because median is defined differently for those
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        pair<int, int> curr = {0, 0};
        int count = 0;
        int m = nums1.size(), n = nums2.size();
        while (count < ((m + n - 1) / 2)) {
            if (curr.first < m && curr.second < n) {
                if (nums1[curr.first] <= nums2[curr.second]) {
                    curr.first++;
                } else {
                    curr.second++;
                }
            } else if (curr.first < m) {
                curr.first++;
            } else {
                curr.second++;
            }
            count++;
        }
        if ((m + n) % 2 == 0) {
            double ans;
            if (curr.first < m && curr.second < n) {
                if (nums1[curr.first] <= nums2[curr.second]) {
                    ans = double(nums1[curr.first]);
                    curr.first++;
                } else {
                    ans = double(nums2[curr.second]);
                    curr.second++;
                }
            } else if (curr.first < m) {
                ans = double(nums1[curr.first]);
                curr.first++;
            } else {
                ans = double(nums2[curr.second]);
                curr.second++;
            }
            if (curr.first < m && curr.second < n) {
                if (nums1[curr.first] <= nums2[curr.second]) {
                    ans += double(nums1[curr.first]);
                    curr.first++;
                } else {
                    ans += double(nums2[curr.second]);
                    curr.second++;
                }
            } else if (curr.first < m) {
                ans += double(nums1[curr.first]);
                curr.first++;
            } else {
                ans += double(nums2[curr.second]);
                curr.second++;
            }
            return ans / 2;
        } else {
            if (curr.first < m && curr.second < n) {
                if (nums1[curr.first] <= nums2[curr.second]) {
                    return double(nums1[curr.first]);
                } else {
                    return double(nums2[curr.second]);
                }
            } else if (curr.first < m) {
                return double(nums1[curr.first]);
            } else {
                return double(nums2[curr.second]);
            }
        }
        return -1;
    }
};
