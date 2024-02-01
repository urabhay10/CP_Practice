#include <bits/stdc++.h>
using namespace std;

void make_tree(int v,int tl, int tr, vector<int> &t,vector<int> &arr){
	if(tl==tr){
		t[v]=arr[tl];
	}else{
		int tm = (tl+tr)/2;
		make_tree(2*v,tl, tm, t, arr);
		make_tree(2*v+1,tm+1, tr, t, arr);
		t[v]= max(t[2*v],t[2*v+1]);
	}
}

int get_max(int v,int l, int r, int tl, int tr, vector<int> &t, vector<int>&arr){
	// cout<<"getting max from v:"<<v<<" "<<l<<" "<<r<<" "<<tl<<" "<<tr<<" "<<(tl+tr)/2<<endl;
	// int x;
	// cin>>x;
	if(r<l || tl>tr) return 0;
	if(tl==l && tr==r){
		return t[v];
	}else{
		int tm = (tl+tr)/2;
		int ans = 0;
		if(l<=tm){
			ans = max(ans, get_max(2*v,l,min(r,tm),tl,tm,t,arr));
		}
		if(r>tm){
			ans = max(ans, get_max(2*v+1,max(l,tm+1),r,tm+1,tr,t,arr));
		}
		return ans;
	}
}

void fill_tree(int depth,int l,int r,vector<int> &vec,int hash_map[],vector<int> &t,int hash_of_tree[],int n){
	// cout<<"filling tree at: "<<v<<" "<<l<<" "<<r<<" "<<endl;

	if(r<l) return;
	if(l==r){
		hash_of_tree[hash_map[vec[l]]]=depth;
		return;
	}else{
		int val=get_max(1,l,r,0,n-1,t,vec);
		hash_of_tree[hash_map[val]]=depth;
		fill_tree(depth+1,l,hash_map[val]-1,vec,hash_map,t,hash_of_tree,n);
		fill_tree(depth+1,hash_map[val]+1,r,vec,hash_map,t,hash_of_tree,n);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		int hash_of_tree[n];
		int hash_map[n+1];
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v.push_back(x);
			hash_map[x]=i;
		}
		vector<int> t(4*n+4);
		make_tree(1,0,n-1,t,v);
		fill_tree(0,0,n-1,v,hash_map,t,hash_of_tree,n);
		for(int i=0;i<n;i++){
			cout<<hash_of_tree[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}   