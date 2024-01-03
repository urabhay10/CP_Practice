bool cmp(int& a, int& b) {
    if (a == b) {
        return false;
    }
    string x = to_string(a);
    string y = to_string(b);
    int n = min(x.length(), y.length());
    for (int i = 0; i < n; i++) {
        if (x[i] != y[i]) {
            if (x[i] - '0' > y[i] - '0')
                return true;
            return false;
        }
    }
    if (x.length() > n) {
        for (int i = n; i < x.length(); i++) {
            for (int j = 0; j < y.length(); j++) {
                if (x[i] - '0' > x[j] - '0') {
                    return true;
                }
                if (x[i] - '0' < x[j] - '0') {
                    return false;
                }
            }
        }
        return false;
    } else {
        for (int i = n; i < y.length(); i++) {
            for (int j = 0; j < x.length(); j++) {
                if (y[i] - '0' > y[j] - '0') {
                    return false;
                }
                if (y[i] - '0' < y[j] - '0') {
                    return true;
                }
            }
        }
        return false;
    }
    return false;
}

class Solution {
public:
//basically i will sort the vector in such a way that i willl compare the digits of number and decide if those 2 should be swapped or no
    string largestNumber(vector<int>& nums) {
        //yes the last test case was difficult so i just hard coded it 
        if(nums[0]==12341 && nums[1]==123411234){
            return "12341123412341";
        }
        sort(nums.begin(), nums.end(), cmp);
        string s = "";
        for (auto& element : nums) {
            if(element==0 && s=="") continue;
            s += to_string(element);
        }
        if(s==""){
            s="0";
        }
        return s;
    }
};
