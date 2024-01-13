//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/1145028590/
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> brackets;
        int ans = 0;
        if(s.length()>0 && s[0]=='('){
            brackets.push('(');
        }else{
            if(s.length())ans++;
        }
        for(int i=1;i<s.length();i++){
            if(s[i]=='('){
                brackets.push('(');
            }else{
                if(!brackets.empty()){
                    brackets.pop();
                }else{
                    ans++;
                }
            }
        }
        return (brackets.size()+ans);
    }
};