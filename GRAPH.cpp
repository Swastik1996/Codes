int gl = 0;
int u[N],d[N],low[N],par[N];
vi G[N];
void dfs1(int node,int dep){ //find dfs_num and dfs_low
  u[node]=1; 
  d[node]=dep;low[node]=dep;
  for(auto it : G[node]){
    if(!u[it]){
      par[it]=node;
      dfs1(it,dep+1);
      low[node]=min(low[node],low[it]);
      /*if(low[it] > d[node] ){
          node-it is cut edge/bridge
      }*/
      /*
      if(low[it] >= d[node] && (par[node]!=-1 || sz(G[node]) > 2)){
          node is cut vertex/articulation point
      }
      */
    }else if(par[node]!=it) low[node]=min(low[node],low[it]); 
    else par[node]=-1;
  }
}
int cmp2[N],a[N],dep[N];vi Gt[N];
void dfs2(int node,int cid,int h,int k){ //making "Bridge tree"
  u[node]=1; cmp2[node]=cid;
  a[cid] = k;
  for(auto it : G[node]){
    if(!u[it]){
      if(low[it]>d[node]){
        Gt[cid].pb(gl);
        dep[gl]=h+1;
        dfs2(it,gl++,h+1,0);
      }
      else dfs2(it,cid,h,1);
    }
  }
}
int pl[N],path[N];
void dfst(int node){ //Furthest 2 nodes of a node
  if(u[node]) return;
  u[node]=1;
  path[node]=0;
  pl[node]=0;
  int x=0,y=0;
  for(auto it : G[node]){
    dfst(it);
    path[node]=max(path[node],path[it]+1);
    pl[node]=max(pl[it],pl[node]);
    int z=path[it]+1;
    if(z>y&&z>x) {y=x;x=z;} else if(z>y) y=z;
  }
  pl[node]=max(pl[node],x+y);
}
ll dist[N]; // fill it with LLONG_MAX
int par[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dijkstra(int n,int node){ 
    dist[node] = 0;
    q.push({dist[node],node});
    while(!q.empty()){
       int u = q.top().S;q.pop();
       for(auto p : G[u]){
          if(dist[p.F] > dist[u] + p.S){
            dist[p.F] = dist[u] + p.S;
            par[p.F] = u;
            q.push({dist[p.F],p.F});
          }
       }
    }
}

void FORD(int node){
    dist[node] = 0;
    for(int x = 1; x <= n ; ++x){
        for(auto e : E){
          int i = e.S.F;
          int j = e.S.S;
          int w = e.F;
          if(dist[j] > dist[i] + w){
            if(x == n){
              printf("NEG");return;
            }
            dist[j] = dist[i] + w;
          }
        }
    }
}

