#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v,int l, int r){
    for(int i=l+1;i<=r;i++){
        if(v[i]<v[i-1]){
            return false;
        }
    }
    return true;
}

bool sort_tree(vector<int> &v, int l, int r,int &cnt){
    // cout<<"sorting from l: "<<l<<" r: "<<r<<endl;
    // for(auto &element:v){
    //     cout<<element<<" ";
    // }
    // cout<<endl;
    if(l>=r){ 
        return true;
    }else if(r-l==1){
        if(v[r]<v[l]){
            swap(v[l],v[r]);
            cnt++;
        }
        return true;
    }else{
        int m = (l+r)/2;
        if(sort_tree(v,l,m,cnt)){
            if(sort_tree(v,m+1,r,cnt)){
                if(v[m+1]<v[m]){
                    for(int i=l,j=m+1;i<=m;i++,j++){
                        swap(v[i],v[j]);
                    }
                    cnt++;
                    return isSorted(v,l,r);
                }else{
                    return isSorted(v,l,r);
                }
            }else{
                // cout<<"couldnt sort for "<<m+1<<" "<<r<<endl;
                return false;
            }
        }else{
            // cout<<"couldnt sort for "<<l<<" "<<m<<endl;
            return false;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        int cnt = 0;
        if(sort_tree(v,0,n-1,cnt)){
            cout<<cnt<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}