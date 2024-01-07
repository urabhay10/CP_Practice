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
        vector<int> v;
        int totalGCD = n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if (i == 1)
            {
                totalGCD = __gcd(abs(v[i]-1-i), abs(v[0]-1));
            }
            else if (i > 1)
            {
                totalGCD = __gcd(abs(v[i]-1-i), totalGCD);
            }
        }
        cout<<totalGCD<<endl;
    }
    return 0;
}