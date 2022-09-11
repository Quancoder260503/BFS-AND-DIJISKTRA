#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
typedef long long ll;
using namespace std;
vector<pair<ll,ll>>g[100005];
vector<ll>dis[100005];
int n,m,k;
void dijisktra(int src){
    using T=pair<ll,ll>;
    priority_queue<T,vector<T>,greater<T>>pq;
    pq.push({0,src});
    while (!pq.empty()){
        int node=pq.top().second;
        ll value=pq.top().first;
        pq.pop();
        if (dis[node].size()>=k) continue;
        dis[node].push_back(value);
        for (auto u:g[node]){
                 ll v=u.first;
                 ll val=u.second;
                 pq.push({val+value,v});            
             }
        }
}
int main(){
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
         int u,v,d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
    } dijisktra(1);
    for (ll i:dis[n]){
        cout << i <<" ";
    }
}