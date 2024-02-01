//https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon
class Solution {
public:
    long long binExp(long long a, long long b, int M){
        long long ans = 1;
        while(b>0){
            if(b&1) ans = (ans*a) % M;
            a=(a*a)%M;
            b>>=1;
        }
        return ans;
    }
    int monkeyMove(int n) {
        return (int(binExp(2,n,1e9+7))+int(1e9+7)-2)%int(1e9+7);
    }
};