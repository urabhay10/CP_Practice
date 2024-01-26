//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int end = m*n-1;
        while(end-start>1){
            int mid = (start+end)/2;
            if(matrix[mid/n][mid%n]>target){
                end = mid -1;
            }else{
                start = mid;
            }
        }
        if(matrix[end/n][end%n]==target || matrix[start/n][start%n]==target){
            return true;
        }
        return false;
    }
};