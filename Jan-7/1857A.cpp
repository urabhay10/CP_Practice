#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        int oddCount = 0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            if(x%2){
                oddCount++;
            }
        }
        if(oddCount%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}