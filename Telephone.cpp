#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;
typedef long long ll;
int n,k;
const int sz=5e4+1;
pair<ll,ll>p[sz];
bool visited[sz];
bool ex[sz];
ll d[51][sz];
bool adj[51][51];
ll a[sz];
void bfs(){
    deque<pair<int,int>>q;
    q.push_back({a[1],1});
    d[a[1]][1]=0;
    while (q.size()){
        int b,v;
        tie(b,v)=q.front();
        q.pop_front();
        if (v>1 and d[b][v-1]==-1){
            d[b][v-1]=d[b][v]+1;
            q.push_back({b,v-1});
        } if(v<n and d[b][v+1]==-1){
            d[b][v+1]=d[b][v]+1;
            q.push_back({b,v+1});
        }  if (adj[b][a[v]] and d[a[v]][v]==-1){
            d[a[v]][v]=d[b][v];
            q.push_front({a[v],v});
        }
    }    
}     
int main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   char c;
   for(int i=1;i<=k;i++){
       for (int j=1;j<=k;j++){
           cin>>c;
           if (c=='1'){
             adj[i][j]=1;
          }      
       } adj[i][0]=adj[i][a[n]];
   } 
    a[n]=0;
    for (int i=0;i<=k;i++){
       for (int j=0;j<=n;j++){
           d[i][j]=-1;
         } 
     }
    bfs();
    cout <<d[0][n];
} 