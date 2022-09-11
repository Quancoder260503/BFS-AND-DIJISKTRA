#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+1;
const int inf=1e6+1;
typedef long long ll;
int n,m,res;
vector<array<int,2>>adj[sz];
int L[sz*3];
int R[sz*3];
int dp[sz];
vector<int>co;
void dijisktra(int mn){
    using T=array<int,2>;
    priority_queue<T,vector<T>,greater<T>>pq;
    memset(dp,0,sizeof(dp));
    dp[1]=inf;
    pq.push({inf,1});
    while(pq.size()){
        array<int,2>t=pq.top();
        pq.pop();
        if(dp[t[1]]!=t[0]) continue;
        for(auto v:adj[t[1]]){
            if(L[v[1]]<=mn & mn<=R[v[1]] && L[v[1]]<=dp[t[1]]){
                  int p=min(dp[t[1]],R[v[1]]);
                  if(p>dp[v[0]]) pq.push({dp[v[0]]=p,v[0]});
            }
        }
    }
    res=max(res,dp[n]-mn+1);
}
int main(){
      cin>>n>>m;
      for(int i=1;i<=m;i++){
          int u,v,l,r;
          cin>>u>>v>>l>>r;
          adj[u].push_back({v,i}); adj[v].push_back({u,i});
          co.push_back(l); co.push_back(r);
          L[i]=l; R[i]=r;
      }
       res=0;
       sort(co.begin(),co.end());
       co.resize(unique(co.begin(),co.end())-co.begin());
       for(auto c:co) dijisktra(c);
       if(res<=0) cout<<"Nice work, Dima!"<<endl;
       else cout<<res<<endl;
}