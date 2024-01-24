//https://www.codechef.com/problems/CTEAMS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int total_sum = 0;
	int young_sum = 0;
	multiset<pair<int,int>> young,old;
	int a,b;
	cin>>a>>b;
	young.insert({a,b});
	young_sum+=b;
	total_sum+=b;
	n--;
	    cout<<abs(young_sum-(total_sum-young_sum))<<endl;    
	while(n--){
    	cin>>a>>b;
    // 	for(auto &e:young){
    // 	    cout<<e.first<<" "<<e.second<<endl;
    // 	}
    // 	cout<<young_sum<<endl;
    // 	for(auto &e:old){
    // 	    cout<<e.first<<" "<<e.second<<endl;
    // 	}
    // 	cout<<total_sum-young_sum<<endl;
    	
    	if(young.size()==old.size()){
    	    if(a>(old.begin()->first)){
    	        pair<int,int> o = (*old.begin());
    	        old.erase(old.begin());
    	        young.insert(o);
    	        young_sum+=o.second;
    	        total_sum+=b;
    	        old.insert({a,b});
    	    }else{
    	        young.insert({a,b});
    	        young_sum+=b;
    	        total_sum+=b;
    	    }
    	}else{
    	    if(a<(--young.end())->first){
    	        pair<int,int> y = (*(--young.end()));
    	        young.erase(--young.end());
    	        old.insert(y);
    	        young_sum-=y.second;
    	        young_sum+=b;
    	        total_sum+=b;
    	        young.insert({a,b});
    	    }else{
    	        old.insert({a,b});
    	        total_sum+=b;
    	    }
    	}
	    cout<<abs(young_sum-(total_sum-young_sum))<<endl;    
	}
	return 0;
}
