//I just counted how many times a closed bracket comes where it cannot come and it magically worked i didnt even run it once in my mind one of the fastest i have solved a C question on codeforces
#include <bits/stdc++.h>
using namespace std;

inline bool isOpen(char ch){
    if(ch=='('){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> vec;
        int count =0;
        int maxhigh=0;
        int opened=0,closed=0;
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            vec.push_back(x);
            if(isOpen(x)){
                opened++;
            }else {
                closed++;
            }
            if(closed>maxhigh+opened){
                count++;
                maxhigh = closed - opened;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}