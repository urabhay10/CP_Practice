class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int ans=citations.size();
        for(int i=0;i<ans;i++){
            if(citations[i]<i+1){
                ans=i;
                break;
            }
        }
    return ans;
    }
};
