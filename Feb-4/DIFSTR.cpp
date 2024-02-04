//https://www.codechef.com/practice/course/3-star-difficulty-problems/DIFF1700/problems/DIFSTR?tab=statement
#include <bits/stdc++.h>
using namespace std;

int binToInt(string s){
    int ans = 0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]-'0'){
        ans+=(1<<s.length()-1-i);}
    }
    return ans;
}

string intToBin(int n,int digits){
    string s="";
    while(n>0){
        if(n&1){
            s="1"+s;
        }else{
            s="0"+s;
        }
        n>>=1;
    }
    while(s.length()<digits){
        s="0"+s;
    }
    return s;
}

string stringOfSize(int n){
    string s="";
    while(n--){
        s+="1";
    }
    return s;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<string> v(n,stringOfSize(n));
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        v[i]=s;
	    }
	    string ans = "";
	    for(int i=0;i<n;i++){
	        if(v[i][i]=='1')ans+="0";
	        else ans+="1";
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
