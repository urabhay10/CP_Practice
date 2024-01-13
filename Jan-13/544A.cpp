#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    bool ans = true;
    vector<bool> isused(26, false);
    vector<int> indexes(k);
    int prev = -1;
    for (int i = 0; i < k; i++)
    {
        int checkat = prev + 1;
        while (checkat < s.length())
        {
            if (isused[s[checkat] - 'a'])
            {
                checkat++;
            }
            else
            {
                indexes[i] = checkat;
                isused[s[checkat] - 'a'] = true;
                prev = checkat;
                break;
            }
        }
        if (checkat >= s.length())
        {
            ans = false;
            break;
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
        {
            cout << s.substr(indexes[i], indexes[i + 1] - indexes[i]) << endl;
        }
        cout << s.substr(indexes[k-1]) << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}