#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        bool two=false, three=false, four=false, five=false;
        vector<int> v;
        int modulo=k;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(two && (x%2==0)){
                four=true;
            }
            if(x%2==0){
                two=true;
            }
            if(x%3==0){
                three=true;
            }
            if(x%5==0){
                five=true;
            }
            if(x%4==0){
                four=true;
            }
            modulo=min(modulo,k-x%k);
            v.push_back(x);
        }
        switch (k)
        {
        case 2:
            if(two){
                cout<<0<<endl;
                continue;
            }
            cout<<1<<endl;
            continue;
        case 3:
            if(three){
                cout<<0<<endl;
                continue;
            }
            cout<<modulo<<endl;
            continue; 
        case 5:
            if(five){
                cout<<0<<endl;
                continue;
            }
            cout<<modulo<<endl;
            continue; 
        case 4:
            if(four){
                cout<<0<<endl;
                continue;
            }
            if(two){
                cout<<1<<endl;
                continue;
            }
            cout<<min(modulo,2)<<endl;
            continue;
        default:
            break;
        }
    }
    return 0;
}