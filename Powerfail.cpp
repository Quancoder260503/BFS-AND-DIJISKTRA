#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<utility>                                                                                                   
using namespace std;
typedef long long ll;
vector<int>g[100005];
ll corx[1001];ll cory[1001];
double dp[1001][1001];
const double inf =1e19; 
int main(){
    int n,m;
    double k;
    cin>>n>>m;
    cin>>k;
    for (int i=1;i<=n;i++){
        ll x;ll y;
        cin>>x>>y;
        corx[i]=x;
        cory[i]=y;
    }   
     for (int i=1;i<=n;i++){
         for (int j=1;j<=n;j++){
             dp[i][j]=hypot(corx[i]-corx[j],cory[i]-cory[j]);
         }
     }for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dp[u][v]=0;
        dp[v][u]=0;
     } double d[1001]; 
    const double inf=1e18;
      for (int i=2;i<=n;i++){
          d[i]=inf;
      }
     vector<bool>visit(n+1,false);
      using T=pair<double,int>;
      priority_queue<T,vector<T>,greater<T>>pq;
      d[1]=0.00;
      pq.push({0,1});
      while(!pq.empty()){
          int node;double val;
          tie(val,node)=pq.top();
          pq.pop();
          if (d[node]!=val or visit[node]) continue;
          visit[node]=true;
          for (int v=1;v<=n;v++){
              if (v==node or visit[v] or dp[node][v]>k) continue;
              if (d[node]+dp[node][v]<d[v]){
                  pq.push({d[v]=dp[node][v]+d[node],v});
            }
        }
   } if (d[n]==inf) cout <<-1;
    else{
        int M=1e3;
        ll ans=(int) M*d[n];
        cout <<ans;
    }
}