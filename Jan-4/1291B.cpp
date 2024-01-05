#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    bool ans=true;
    cin>>n;
    int arr[n];
    int maximum=0;
    vector<int> maxindex;
    for (int i = 0; i < n; i++) {
      cin>>arr[i];
      if(arr[i]>maximum){
        maxindex.clear();
        maxindex.push_back(i);
      }else if(arr[i]==maximum){
        maxindex.push_back(i);
      }
      maximum=max(maximum,arr[i]);
    }
    for(auto index:maxindex){
      ans=true;
      for(int i=0;i<index;i++){
        if(arr[i]<i){
          ans=false;
          break;
        }
      }
      if(ans){
      for(int i=index+1;i<n;i++){
        if(arr[i]<n-i-1){
          ans=false;
          break;
        }
      }}
      if(ans){
        if(maximum<index || maximum<n-index-1){
          ans=false;
        }else{
        break;}
      }
    }
    if(ans){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
