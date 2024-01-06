class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int curr = INT_MIN;
        vector<int> indexes;
        int i = 0;
        int count=0;
        for (auto& num : nums) {
            if (num < curr) {
                count++;
                indexes.push_back(i);
                if (count > 2) {
                    return false;
                }
            }
            curr = num;
            i++;
        }
        if (count == 0) {
            return true;
        } else {
            if(count==1){
                if(indexes[0]!=nums.size()-1){
                    if(nums[indexes[0]-1]<=nums[indexes[0]+1]){
                        return true;
                    }else if(indexes[0]>=2){
                        if(nums[indexes[0]-2]<=nums[indexes[0]]) return true;
                    }else{
                        return true;
                    }
                }else{
                    return true;
                }
            }else{
                return false;
            }
        }
        return false;
    }
};