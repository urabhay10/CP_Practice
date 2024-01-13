//https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count(10,0);
        for(int i=0;i<secret.length();i++){
            count[secret[i]-'0']++;
        }
        for(auto &element: count){
            cout<<element<<" ";
        }
        int green = 0;
        int yellow = 0;
        for(int i=0;i<guess.length();i++){
            if(guess[i]==secret[i]){
                green++;
                count[guess[i]-'0']--;
            }
        }
        for(int i=0;i<guess.length();i++){
            if(guess[i]!=secret[i]){
                if(count[guess[i]-'0']){
                    count[guess[i]-'0']--;
                    yellow++;
                }
            }
        }
        return (to_string(green)+"A"+to_string(yellow)+"B");
    }
};