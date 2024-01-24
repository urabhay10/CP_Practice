//https://leetcode.com/problems/beautiful-towers-i/
class Solution {
public:
    long long solve(vector<int> & maxHeights, int index){
        int prevMin = maxHeights[index];
        long long ans = 0;
        for(int i=index;i<maxHeights.size();i++){
            prevMin = min(prevMin, maxHeights[i]);
            ans += prevMin;
        }
        prevMin = maxHeights[index];
        for(int i=index;i>=0;i--){
            prevMin = min(prevMin, maxHeights[i]);
            ans += prevMin;
        }
        return (ans-maxHeights[index]);
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto pivot = max_element(maxHeights.begin(),maxHeights.end());
        long long ans = *pivot;
        for(int i=0;i<maxHeights.size();i++){
            ans = max(ans, solve(maxHeights, i ));
        }
        return ans;
    }
};