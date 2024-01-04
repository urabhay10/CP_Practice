#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n,m,count=0;
  cin>>n>>m;
  long long sum_a=0, sum_b=0;
  vector<int> diff;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    diff.push_back(y-x);
    sum_a+=x;
    sum_b+=y;
  }
  if(sum_b>m){
    cout<<-1<<endl;
    return 0;
  }
  sort(diff.begin(),diff.end());
  for(auto element: diff){
    if(sum_a<=m){
      break;
    }
    sum_a+=element;
    count++;
  }
  if(sum_a<=m){
    cout<<count<<endl;
  }
  return 0;
}
