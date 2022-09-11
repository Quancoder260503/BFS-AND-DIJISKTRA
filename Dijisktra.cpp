#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
vector<pair<int,int>>g[100005];
ll n;
ll dis[100005];
void dijisktra(ll n){
    using Q=pair<int,ll>;
    priority_queue<Q,vector<Q>,greater<Q>>q;
    dis[0]=0;
    q.push({n,0});
    while (!q.empty()){
        int node=q.top().first;
        ll value=q.top().second;
        q.pop();
        if (dis[node]!=value) continue;
        for (pair<ll,ll> u:g[node]){
            if (u.second+value<dis[u.first]){
                dis[u.first]=value+u.second;
                q.push({u.first,dis[u.first]});
            }
        }
    }
}
int main() {
    ll m;
    cin>>n>>m;
    for (ll i=0;i<m;i++){
        int u,v;
        ll d;
        cin>>u>>v>>d;
        g[u-1].push_back({v-1,d});
    }
    for (ll i=0;i<n;i++){
        dis[i]=LLONG_MAX;
    } 
    dijisktra(0);
    for (ll i=0;i<n;i++){
        cout <<dis[i]<< " ";
    }
  }
  