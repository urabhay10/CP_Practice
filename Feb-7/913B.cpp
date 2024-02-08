#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];

int main(){
	int n;
	cin>>n;
	for(int i=2;i<n+1;i++){
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	bool ans = true;
	for(int i=1;i<=n;i++){
		int count = 0;
		if(v[i].size()==0){
			continue;
		}
		for(auto e:v[i]){
			if(v[e].size()==0){
				count++;
			}
		}
		if(count<3){
			ans=false;
			break;
		}
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}