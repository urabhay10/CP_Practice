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
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    ll y;
    cin>>y;
    ll a = x*y/__gcd(x,y);
    ll divofx = n/x;
    ll divofy = n/y;
    divofx-=n/a;
    divofy-=n/a;
    ll sum1 = divofx*n-divofx*(divofx-1)/2;
    ll sum2 = divofy*(divofy+1)/2;
    // debug(divofx,divofy,sum1,sum2);
    cout<<sum1-sum2<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}