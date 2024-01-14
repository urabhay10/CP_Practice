//https://leetcode.com/problems/excel-sheet-column-number/description/
//wow i did that in just a 1 or 2 minutes but yeah it was a easy category question i must do it fast 
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long x=1;
            for(int j = 0;j<i;j++){
                x*=26;
            }
            ans+=(columnTitle[n-i-1]-'A'+1)*x;
        }
        return int(ans);
    }
};