map<int,vector<pair<pair<int,int>,long long>>>adj[sz];
void dijsktra(int src){
     using T = pair<long long,pair<int,int>>;
     priority_queue<T,vector<T>,greater<T>>pq; 
     pq.push({0,{src,0}});
     for(int i = 1; i <= n; i++) dp[i] = bignum;
     dp[src] = 0;
     while(pq.size()){
            long long x; pair<int,int>v;
            tie(x,v) = pq.top(); pq.pop();
            if(v.second){
                if(dpx[v.first][v.second] != x) continue;
                for(int i = 0; i < adj[v.first][v.second].size(); i++){
                     pair<pair<int,int>,long long>cur = adj[v.first][v.second][i];
                     long long cost = x + col[v.first][v.second] - cur.second;
                     if(dp[cur.first.first] > cost){
                          dp[cur.first.first] = cost;
                          pq.push({dp[cur.first.first],{cur.first.first,v.second}});
                     }
                }
            }
            else{
              if(dp[v.first] != x ) continue;
              for(auto it: col[v.first]){
                   cout<<it<<endl;
                   pair<pair<int,int>,long long> cur = it;
                   int des = cur.first.first;
                   int color = cur.first.second;
                   if(dp[des] > dp[v.first] + cur.second){
                         dp[des] = dp[v.first] + cur.second;
                         pq.push({dp[des],{des,0}});
                   }
                   if(dp[des] > dp[v.first]+col[v.first][color] - cur.second){
                          dp[des] = dp[v.first] + col[v.first][color] - cur.second;
                          pq.push(dp[des],{des,color});
                   }
                   long long val = dp[v.first] + col[v.first][color] - cur.second ;
                   if(!dpx[des].count(color) or dpx[des][color] > val){
                           dpx[des][color] = val; 
                           pq.push({dpx[des][color],{des,color}});
                       }  
                   }
                }
          }
     }
}
