#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
vector<pair<pair<int,ll>,ll>>g[100005];
vector<ll>flow;
const ll inf =1e18;
int n,m;
int dijisktra(int minf){
    vector<ll>dis(n+1,inf);
    vector<bool>visit(n+1,false);
    using T=pair<int,ll>;
    priority_queue<T>pq;
    dis[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        int u=pq.top().first;
        ll val=pq.top().second;
        pq.pop();
        if (dis[u]!=val or visit[u]) continue;
        for (auto v:g[u]){
            int node=v.first.first;
            ll alt=v.first.second+val;
            ll rate=v.second;
            if (visit[node] or minf>rate) continue;
            else if (dis[node]>alt){
                dis[node]=alt;
                pq.push({node,alt});    
            }
        }
    } if (dis[n]!=inf){
        return dis[n];
    }else{
        return  -1;
    }
}
int main() {
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int u,v;
        ll d,t;
        cin >>u>>v>>d>>t;
        flow.push_back(t);
        g[u].push_back({{v,d},t});
        g[v].push_back({{u,d},t});
    } int ans=-1; 
    int M=1e6; 
    for (int fl:flow){
        ll cur =dijisktra(fl);
        if (cur==-1) continue; 
        double temp=double (fl)/double(cur);
        ans=max(ans,(int)(M*temp));
  } cout<<ans;
}