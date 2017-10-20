#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int mod = 1e9+7;
const int N = 1e6+10; 
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};
int n,m,k;
vector<ii> E;
int f(int t){
	Dinic d(n*t + 2);
	int st = n*t,si = n*t + 1;
	d.AddEdge(st,0,n);
	FOR(i,0,t-1){
		int x = (n-1)*t + i;
		d.AddEdge(x,si,n);
	}
	FOR(i,0,t-2){
		for(auto it : E){
			int u = it.F, v = it.S;
			int x = u*t + i;
			int y = v*t + i + 1;
			d.AddEdge(x,y,1);
		}
	}
	int x = d.MaxFlow(st,si);
	//cout << t << " ";
	//cout << x << "\n";
	if(x >= k)return 1;
	else return 0;
}
int main(){
  fast;
  int t;
  cin >> t;
  while(t--){
  		cin >> n >> m >> k;
  		E.clear();
  		FOR(i,0,m-1){
  			int u,v;cin >> u >> v;
  			u--,v--;
  			E.pb({u,v});
  		}
  		int l = 1,r = n+1;
  		while(l < r){
  			int x = (l + r)/2;
  			if(f(x+1)){
  				r = x;
  			}
  			else{
  				l = x + 1;
  			}
  		}
  		if(l == n + 1)l = -1;
  		cout << l << "\n";
  }
  return 0;
}