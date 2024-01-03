#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int one=1,two=2;
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  //v[0] is the only number in set A
  //0 is the only number in set C 
  //if(v[1]) is also negative then set B is v[0],v[1] else if it is 0 then iterate from v[2] to v[n-1] to get the next non zero number and if that number is positive set B is just that number
  cout<<one<<" "<<v[0]<<endl;
  if(v[n-1]>0){
    cout<<one<<" "<<v[n-1]<<endl;
    cout<<n-2<<" ";
    for(int i=1;i<n-1;i++){
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }else{
    cout<<two<<" "<<v[1]<<" "<<v[2]<<endl;
    cout<<n-3<<" ";
    for(int i=3;i<n;i++){
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }
}
