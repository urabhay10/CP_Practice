#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int b;
        cin >> b;
        int c;
        cin >> c;
        int teams = (a+b+c)/3;
        int m = min(a,b);
        if(m<teams){
            teams = m;
        }
        cout<<teams<<endl;
        
    }
    return 0;
}