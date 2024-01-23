#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(s.empty()){
            s.push(ch);
        }else{
            if(s.top()==ch){
                s.pop();
            }else{
                s.push(ch);
            }
        }
    }
    if(s.empty()){
        cout<<"YES"<<endl;
        return 0;
    }else{
        cout<<"NO"<<endl;

    }
    return 0;
}