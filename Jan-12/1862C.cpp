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
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int element = vec[i];
            if (element > n || element < 1)
            {
                ans = false;
                break;
            }
            else
            {
                if (vec[element - 1] <= i)
                {
                    ans = false;
                    break;
                }
                if(element!=n && vec[element]>i){
                    ans = false;
                    break;
                }
            }
        }
        if(ans){
            cout<<"YES"<<endl;
            
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}