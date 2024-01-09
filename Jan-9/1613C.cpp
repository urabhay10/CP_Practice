#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long k;
        cin >> k;
        long long ans = k/(n*1ll);
        if(k%n){
            ans++;
        }
        vector<int> v;
        int count = 0;
        long int req = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if(i){
                if(x-v[i-1]<ans){
                    count++;
                    req+=(x-v[i-1]-ans);
                }
            }
        }
        long long damage_dealt = ans*n+req;
        if(k<=damage_dealt){
            cout<<ans<<endl;
            break;
        }else{
            long int extras = -1*req/(n*1l);
            if((-1*req)%n){
                extras++;
            }
            ans+=extras;
            damage_dealt=ans*n+req;
            if(k<=damage_dealt){
                cout<<ans<<endl;
                break;
            }else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}