//https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> sle(n,-1);
        vector<int> sre(n,n);
        {
            stack<pair<int,int>> st;
            for(int i=0;i<n;i++){
                while(!st.empty() && st.top().first>arr[i]){
                    pair<int,int> e = st.top();
                    sre[e.second] = i;
                    st.pop();
                }
                st.push({arr[i],i});
            }
        }
        {
            stack<pair<int,int>> st;
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && st.top().first>=arr[i]){
                    pair<int,int> e = st.top();
                    sle[e.second] = i;
                    st.pop();
                }
                st.push({arr[i],i});
            }
        }
        // for(auto e:sre){
        //     cout<<e<<" ";
        // }
        // cout<<"\n";
        // for(auto e:sle){
        //     cout<<e<<" ";
        // }
        // cout<<"\n";
        long long ans = 0;
        for(int i=0;i<n;i++){
            int x1 = sre[i] - i - 1;
            int x2 = i - sle[i] - 1 ;
            ans += (1ll * arr[i] * (x1+1) * (x2+1))%int(1e9+7);
            ans = ans % int(1e9+7);
        }
        return ans;
    }
};