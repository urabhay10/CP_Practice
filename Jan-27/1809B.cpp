#include <bits/stdc++.h>
using namespace std;

long long round_off(double d){
    if(d-int(d)>=0.51){
        return int(d)+1;
    }
    return int(d);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        double x = sqrt(n);
        if((1ll*round_off(x)*round_off(x))==n){
            cout<< int(x) - 1<<endl;
            continue;
        }else{
            cout<< int((x)) <<endl;
            continue;
        }
    }
    return 0;
}