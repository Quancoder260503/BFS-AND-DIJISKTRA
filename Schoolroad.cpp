#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
vector<pair<int,int>>g[100005];
ll dis[100005];
ll cnt[100005];
void dijisktra(int src){
    using Q=pair<ll,int>;
    priority_queue<Q,vector<Q>,greater<Q>>q;
    dis[src]=0;
    cnt[src]=1;
    q.push({0,src});
    while (!q.empty()){
        int node=q.top().second;
        ll value=q.top().first;
        q.pop();
        if (dis[node]!=value) continue;
        for (pair<int,ll> u:g[node]){
             int v=u.first;
             ll val=u.second+value;
             if (val==dis[v]){
                 cnt[v]+=cnt[node];
             } if (val<dis[v]){
                 dis[v]=val;
                 cnt[v]=cnt[node];
                 q.push({val,v});
             }
        }
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    for (ll i=0;i<m;i++){
        int k,u,v;
        ll d;
        cin>>k>>u>>v>>d;
        if (k==1){
        g[u].push_back({v,d});
        } else{
            g[u].push_back({v,d});
            g[v].push_back({u,d});
        }  
    }
    for (ll i=1;i<=n;i++){
        dis[i]=LLONG_MAX;
    } 
    dijisktra(1);
    cout <<dis[n]<<" "<<cnt[n];
}