#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int score;
    cin >> score;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(),greater<int>());
    int start = 0, end = n - 1;
    int count = 0;
    while (start <= end)
    {
        int num=score/v[start]+1;
        if(num<=end-start+1){
            start++;
            end-=(num-1);
            count++;
        }else{
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}