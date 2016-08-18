int mflow[N][N],flow[N][N],p[N],c[N];
vector<int> G[N];
int bfs(int s,int t){
	fill(p,-1);
	fill(c,0);
	queue<int> q;
	q.push(s);
	p[s] = -2;
	c[s] = N;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		tr(G[node],it){
			if(p[*it] == -1){
				//debug(*it);
				if(mflow[node][*it] > flow[node][*it]){
					p[*it] = node;
					c[*it] = min(c[node],mflow[node][*it] - flow[node][*it]);
					if(*it == t){
						return c[*it];
					}
					q.push(*it);
				}
			}
		}
	}
	return 0;
}
int E(int s,int t){
	int maxflow = 0;
	while(1){
		int f = bfs(s,t);
		//debug(f);
		if(!f)break;
		maxflow += f;
		int node = t;
		while(node != s){
			int prev = p[node];
			flow[prev][node] += f;
			flow[node][prev] -= f;
			node = prev;
		}
	}

	return maxflow;
}
int main(){
  	  fill(flow,0);
      int n,m;
      cin >> n >> m;
      FOR(i,0,m-1){
      	int u,v,w;
      	cin >> u >> v >> w;
      	u--,v--;
      	mflow[u][v] = w;
      	G[u].pb(v);
      	G[v].pb(u);
      }
      int s,t;
      cin >> s >> t;
      s--,t--;
      cout << E(s,t) << "\n";
} 
