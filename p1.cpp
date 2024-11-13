#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<pair<int,string>> v;
    for(int i=0;i<n;i++){
        string s;
        int t;
        cin>>s; cin>>t;
        v.push_back(make_pair(t,s));
    }
    sort(v.begin(),v.end());
    cout<<v[n-1].second<<'\n';
    return 0;
}