class Solution {
public:
  //using maps we can have the count of each distinct number in the vector, and using this, i iterated through vector and stored the counts in a map and returned the key of the element with highest count 
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                m[nums[i]]++;
            }else{
                m[nums[i]]=1;
            }
        }
        for(auto &element: m){
            if(element.second>(nums.size()/2)){
                return element.first;
            }
        }
        return -1;
    }
};
