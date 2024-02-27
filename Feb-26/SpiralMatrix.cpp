// https://leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int>(n,-1));
        int start1 = 0;
        int end1 = n;
        int start2= 0;
        int end2 = n;
        int curr = 1;
        int t = (n+1)/2;
        while(t--){
            for(int i=start1;i<end1;i++){
                vec[start2][i]=curr;
                curr++;
            }
            for(int i=start2+1;i<end2;i++){
                vec[i][end1-1]=curr;
                curr++;
            }
            for(int i=end1-2;i>=start1;i--){
                vec[end2-1][i]=curr;
                curr++;
            }
            for(int i=end2-2;i>start2;i--){
                vec[i][start1]=curr;
                curr++;
            }
            start1++,start2++,end1--,end2--;
        }
        return vec;
    }
};