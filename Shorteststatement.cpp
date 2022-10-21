#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=1e5+1;
const int sz1=1e6+1;
const int inf=1e18;
int n,m,q;
vector<array<ll,3>>edge;
vector<array<ll,3>>redge;
vector<array<ll,2>>adj[sz];
vector<pair<ll,ll>>adj1[sz];
ll dp[18][sz];
ll up[18][sz];
ll ds[sz][22];
ll d[sz];
int par[sz];
int co[sz];
ll ans[sz1];
ll bit[sz];
int find(int u){
    if(u==par[u]) return u;
    else return find(par[u]);
}
void unite(int u,int v){
    u=find(u); v=find(v);
    if(co[u]>co[v]) swap(u,v);
    co[v]+=co[u];
    par[u]=v;
}
void dfs(int u){
    for(int i=1;i<18;i++){
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(auto v:adj[u]){
        if(v[0]==up[0][u]) continue;
        dp[0][v[0]]=v[1];
        d[v[0]]=d[up[0][v[0]]=u]+1;
        dfs(v[0]);
    }
}
int lca(int a,int b){
     if(d[a]<d[b]) swap(a,b);
     int ds=d[a]-d[b];
     for(int i=0;i<=17;i++){
         if(ds&(1<<i)) a=up[i][a];
     }
     if(a==b) return a;
     for(int i=17;i>=0;i--){
          int ta=up[i][a];
          int tb=up[i][b];
          if(ta!=tb){
              a=ta; 
              b=tb;
          }
     }
     return up[0][a];
}
ll calc_dis(int x,int d){
     ll acc=0;
     for(int i=0;i<18;i++){
          if(d&(1<<i)){
               acc+=dp[i][x];
               x=up[i][x];
          }
     }
     return acc; 
}
void dijktra(int src,int ord){
    using Q=pair<ll,int>;
    priority_queue<Q,vector<Q>,greater<Q>>q;
    for(int i=1;i<=n;i++) ds[i][ord]=1e18;
    ds[src][ord]=0;
    q.push({0,src});
    while (!q.empty()){
        ll node=q.top().second;
        ll value=q.top().first;
        q.pop();
        if (ds[node][ord]!=value) continue;
        for (pair<ll,ll> u:adj1[node]){
            if (u.second+value<ds[u.first][ord]){
                ds[u.first][ord]=value+u.second;
                q.push({ds[u.first][ord],u.first});
            }
        }
    }
}
ll dis(int a,int b){
     int anc=lca(a,b);
     ll dis0=calc_dis(a,d[a]-d[anc]);
     ll dis1=calc_dis(b,d[b]-d[anc]);
     return dis0+dis1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        co[i]=1;
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj1[u].push_back({v,w});
        adj1[v].push_back({u,w});
        edge.push_back({w,u,v});
    } 
    sort(edge.begin(),edge.end());
    for(auto e:edge){
        if(find(e[1])==find(e[2])){
            redge.push_back({e[1],e[2],e[0]});
            continue;
        }
        unite(e[1],e[2]);
        adj[e[1]].push_back({e[2],e[0]});
        adj[e[2]].push_back({e[1],e[0]});
    }
    dfs(1);
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
              dp[i][j]=dp[i-1][j]+dp[i-1][up[i-1][j]];
         }
    }
    int cnt=0; 
    sort(redge.begin(),redge.end());
    for(auto e:redge){
         dijktra(e[0],cnt++);
    }
    cin>>q;
    for(int i=0;i<q;i++){
         int u,v; cin>>u>>v;
         ll cur_dis=dis(u,v);
         for(int i=0;i<redge.size();i++){
              cur_dis=min(cur_dis,ds[u][i]+ds[v][i]);
         }
         cout<<cur_dis<<endl;
    }
}
