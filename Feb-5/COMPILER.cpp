#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
        string s;
        int longestPrefix = 0;
	    cin>>s;
	    int curr = 0;
	    stack<int> st;
	    for(int i=0;i<s.length();i++){
	        if(st.empty()){
	            if(s[i]=='<'){
	                st.push(s[i]);
	            }else{
	                 break;   
	            }
	        }else{
	            if(s[i]=='>'){
	                st.pop();
	                if(st.empty()){
	                    longestPrefix = i+1;
                    }               
                }else{
                    st.push(s[i]);
                }
	        }
	    }
	    cout<<longestPrefix<<endl;
	}
	return 0;
}
