#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a ;
        cin>>a ;
        int b ;
        cin>>b ;
        vector<int> v;
        long long sum = 0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            sum+=x;
        }
        sort(v.begin(),v.end());
        int negstart = max(0,n-b-a);
        int negsum = 0;
        for(int i=negstart;i<negstart+b && i<n-a;i++){
            negsum+=v[i];
        }
        int possum = 0;
        for(int i = 0;i<negstart;i++){
            possum+=v[i];
        }
        //distance in start to end is limited to the value of b
        //calculate negstart to negend here its just zero
        //sum is zero cuz a==n and whole array is deleted at first
        //now alice will start undeleting things 
        //we assumed alice will first think of what will happen on deleting all elements
        int bestsum = possum-negsum;
        for(int i=n-a;i<n;i++){
            negsum+=v[i];
            if(i-negstart==b){
                possum+=v[negstart];
                negsum-=v[negstart];
                negstart++;
            }
            bestsum=max(possum-negsum,bestsum);
        }
        cout<<bestsum<<endl;
    }
    return 0;
}