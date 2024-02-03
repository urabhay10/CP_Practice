#include <bits/stdc++.h>
using namespace std;

void execute(string &cmd, string &ans){
    // cout<<"executing cmd: "<<cmd<<endl;
    if(cmd==".."){
        for(int i=ans.length()-2;i>=0;i--){
            if(ans[i]=='/'){
                ans = ans.substr(0,i+1);
                return;
            }
        }
    }else{
        ans = ans+cmd+"/";
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    string ans = "/";
    while (t--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "pwd")
        {
            cout << ans << endl;
        }
        else
        {
            string dirs;
            cin >> dirs;
            if(dirs[0]=='/'){
                ans="/";
            }
            vector<string> directories;
            string curr = "";
            for (int i = 0; i < dirs.length(); i++)
            {
                if (dirs[i] == '/')
                {
                    if (curr != "")
                    {
                        directories.push_back(curr);
                        curr = "";
                    }
                    continue;
                }
                curr += dirs[i];
            }
            if (curr != "")
            {
                directories.push_back(curr);
                curr = "";
            }
            for(auto &element:directories){
                execute(element,ans);
            }
        }
    }
    return 0;
}