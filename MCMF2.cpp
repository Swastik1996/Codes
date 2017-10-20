struct MCMF {
	typedef int ctype;
	struct Edge { int x, y; ctype cap, cost; };
	vector<Edge> E;vector<int> adj[N];
	int n, prev[N];ctype dist[N],phi[N];

	MCMF(int size) : n(size) {}

	void add(int x, int y, ctype cap, ctype cost) {  
		adj[x].pb(sz(E)); E.push_back({x,y,cap,cost});
		adj[y].pb(sz(E)); E.push_back({y,x,0,-cost});
	}

	void mcmf(int s, int t, ctype &flowVal, ctype &flowCost) {
		flowVal = flowCost = 0; fill(phi,0);
		while (true) {
			fill(prev,-1);
			FOR(i,0,n-1) dist[i] = 1e9;
			dist[s] = prev[s] = 0;

			set<pair<ctype,int> > Q;
			Q.insert({dist[s],s});
			while (!Q.empty()){
				int x = Q.begin()->S;
				Q.erase(Q.begin());
				for(it : adj[x]) {
					const Edge &e = E[it];
					if (e.cap <= 0) continue;
					ctype cc = e.cost + phi[x] - phi[e.y];                    // ***
					if (dist[x] + cc < dist[e.y]) {
						Q.erase({dist[e.y], e.y});
						dist[e.y] = dist[x] + cc;
						prev[e.y] = it;
						Q.insert({dist[e.y], e.y});
					}
				}
			}
			if (prev[t] == -1) break;

			ctype z = 1e9;
			for (x = t; x != s; x = E[prev[x]].x) z = min(z, E[prev[x]].cap);
			for (x = t; x != s; x = E[prev[x]].x)
				{ E[prev[x]].cap -= z; E[prev[x]^1].cap += z; }
			flowVal += z;
			flowCost += z * (dist[t] - phi[s] + phi[t]);
			FOR(i,0,n-1) if (prev[x] != -1) phi[x] += dist[x];     // ***
		}
	}
};
int main(){
  
  clock_t tm = clock();
  fast;
  int __t = 1;
  //cin >> __t;
  FOR(_t,1,__t){
      	int n;
      	cin >> n;
      	FOR(i,0,n-1){
      		cin >> a[i].F >> a[i].S;
      	}
      	FOR(i,0,n-1){
      		cin >> b[i].F >> b[i].S;
      	}
      	MCMF *mc = new MCMF(2*n+10);
      	FOR(i,0,n-1){
      		FOR(j,0,n-1){
      			int dist = abs(a[i].F - b[j].F) + abs(a[i].S - b[j].S);
      			mc->add(i,j+n,100,dist);
      		}
      	}
      	FOR(i,0,n-1){
      		mc->add(2*n,i,1,0);
      	}
      	FOR(i,n,2*n-1){
      		mc->add(i,2*n+1,1,0);
      	}
      	int a1,a2;
      	mc->mcmf(2*n,2*n+1,a1,a2);
      	assert(a1 == n);
      	cout << a2 << "\n";
  }
  tm = clock()-tm ;
  cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
}