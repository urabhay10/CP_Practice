#include <bits/stdc++.h>
#define ll long long
#define printyes cout<<"YES"<<endl
#define printno cout<<"NO"<<endl
#define endl '\n'
#define M 1000000007
void __print(auto x){
    std::cerr << x;
}
void __print(std::pair<auto,auto> p){
    std::cerr << "{" << p.first <<","<<p.second<<"}";
}
void _print() {std::cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...);}
#define debug(x...) std::cerr << "[" << #x << "] = ["; _print(x)
template<typename T>
void __print_auto(const T &x) {
    int f = 0;
    std::cerr << '{'; for (auto &i: x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}";
}
#define debugmul(v...) std::cerr<< "[" << #v <<"] = ["; __print_auto(v) 
#define precision(x, p) std::cout << std::fixed << std::setprecision(p) << x << std::endl;
#define pb push_back
#define mp make_pair
#define get_bit(x,r) (x&(1<<r))
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define srt(v) sort(all(v))
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
using namespace std;

void solve(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    queue<int> req,aval;
    vector<pii> ans;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        req.push(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        aval.push(x);
    }
    while(!aval.empty()){
        // debugmul(ans);
        while(!req.empty() && req.front()+y<aval.front()) req.pop();
        if(!req.empty() && req.front()-x<=aval.front() && req.front()+y>=aval.front()){
            ans.pb({n-req.size()+1,m-aval.size()+1});
            req.pop();
        }
        aval.pop();
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}