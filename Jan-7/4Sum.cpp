//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    long toFind = target*1l-nums[i]*1l-nums[j]*1l-nums[k]*1l;
                    if(toFind<=1e9 && toFind>=0-1e9){
                    auto it = m.find(int(toFind));
                    if(it!=m.end()){
                        if(it->second!=k && it->second!=j && it->second!=i){
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        vec.push_back(nums[it->second]);
                        sort(vec.begin(),vec.end());
                        ans.insert(vec);}
                    }}
                }
            }
        }
        vector<vector<int>> res;
        for(auto &e: ans){
            res.push_back(e);
        }
        return res;
    }
};