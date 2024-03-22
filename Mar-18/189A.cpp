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
    std::cerr << '{'; for (auto &i: x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}"<<endl;
}
#define debugmul(v...) std::cerr<< "[" << #v <<"] = "; __print_auto(v) 
#define precision(x, p) std::cout << std::fixed << std::setprecision(p) << x << std::endl;
#define pb push_back
#define get_bit(x,r) (x&(1<<r))
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define srt(v) sort(all(v))
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define pii pair<int,int>
#define hashmap unordered_map<int,int>
using namespace std;
int dp[4001];

int solveit(int n,int a,int b,int c){
    if(dp[n]!=-1) return dp[n];
    if(n==0){
        return dp[n]=0;
    }
    if(n<0){
        return dp[n]=INT_MIN;
    }
    int ans = INT_MIN;
    if(a<=n){
        ans = max(1+solveit(n-a,a,b,c),ans);
    }
    if(b<=n){
        ans = max(1+solveit(n-b,a,b,c),ans);
    }
    if(c<=n){
        ans = max(1+solveit(n-c,a,b,c),ans);
    }
    return dp[n]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<solveit(n,a,b,c)<<endl;
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