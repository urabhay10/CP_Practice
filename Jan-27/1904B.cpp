	#include <bits/stdc++.h>
	using namespace std;

	bool cmp(pair<int,int> &a, pair<int,int> &b){
		return (a.first<b.first);
	}

	int main(){
		int t;
		cin>>t;
		while(t--){
			int n;
			cin>>n;
			vector<pair<int,int>> v;
			vector<long long> prefix;
			vector<bool> stop(1,true);
			vector<int> stops;
			for(int i=0;i<n;i++){
				int x;
				cin>>x;
				v.push_back({x,i});
			}
			sort(v.begin(),v.end(),cmp);
			long long prevSum = 0;
			for(int i=0;i<n;i++){
				prevSum+=v[i].first;
				prefix.push_back(prevSum);
				if(i){
					stop.push_back((prefix[i-1]<v[i].first));
				}
				if(stop[i]){
					stops.push_back(i);
				}
			}	
			int index = 1;
			vector<int> ans(n);
			for(int i=0;i<n;i++){
				int res = i ;
				if(index<stops.size() && stops[index]==i){
					index++;
				}
				if(index<stops.size()){
					res += stops[index]-i-1;
				}else{
					res = n - 1;
				}
				ans[v[i].second]=res;
			}
			for(auto &e:ans){
				cout<<e<<" ";
			}
			cout<<"\n";
		}
		return 0;
	}