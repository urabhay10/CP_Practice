class Solution {
public:
    short int dp[104][104][203];
    bool recur(string &s1, string &s2, string &s3,int a=0,int b=0,int c=0){
        if(dp[a][b][c]!=-1) return dp[a][b][c];
        if(s3.length()<=c) return dp[a][b][c]=true;
        if(s1.length()>a && s3[c]==s1[a] && s2.length()>b && s3[c]==s2[b]){
            return dp[a][b][c]=(recur(s1,s2,s3,a+1,b,c+1)?true:recur(s1,s2,s3,a,b+1,c+1)); 
        }
        if(s1.length()>a && s3[c]==s1[a]){
            return dp[a][b][c]=recur(s1,s2,s3,a+1,b,c+1);
        }
        if(s2.length()>b && s3[c]==s2[b]){
            return dp[a][b][c]=recur(s1,s2,s3,a,b+1,c+1);
        }
        return dp[a][b][c]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        memset(dp,-1,sizeof(dp));
        return recur(s1,s2,s3);
    }
};