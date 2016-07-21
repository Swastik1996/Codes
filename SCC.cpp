#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define all(x) x.begin(), x.end()
#define tr(x,it) for( auto it = x.begin(); it!=x.end(); ++it)
#define rtr(x,it) for( auto it = x.rbegin(); it!=x.rend(); ++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n" 

const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5+10; 
const double eps = 1e-6;
const int BIG = 1e6;
vi G[N],_G[N];
int vis[N],n,m,comp[N],ans[N];
stack<int> s;
void dfs(int node){
	vis[node] = 1;
	tr(G[node],it){
		if(!vis[*it]){
			dfs(*it);
		}
	}
	s.push(node);
}
void scc(int node,int c){
	vis[node] = 1;
	comp[node] = c;
	tr(_G[node],it){
		if(!vis[*it]){
			scc(*it,c);
		}
	}
}
int main(){
  clock_t tm = clock();
  fast;
  int __t = 1;
  //cin >> __t;
  FOR(_t,1,__t){
  	  _t--;
      cin >> n;
      if( n == 0 )break;
      FOR(i,0,n-1){
      	G[i].clear();
      	_G[i].clear();
      }
      cin >> m;
      fill(ans,0);
      fill(comp,0);
      FOR(i,0,m-1){
      	int u,v;
      	cin >> u >> v;
      	u--,v--;
      	G[u].pb(v);
      	_G[v].pb(u);
      }
      fill(vis,0);

      FOR(i,0,n-1){
      	if(!vis[i]){
      		dfs(i);
      	}
      }
      fill(vis,0);
      int c = 0;
      while(!s.empty()){
      	int _top = s.top();
      	s.pop();
      	if(!vis[_top]){
      		scc(_top,c++);
      		ans[c-1] = 1;
      	}
      }
      FOR(i,0,n-1){
      	tr(G[i],it){
      		//cout << i+1 << " " << *it+1 << "\n";
      		if(comp[*it] != comp[i]){
      			ans[comp[i]] = 0;
      		}
      	}
      }
      FOR(i,0,n-1){
      	if(ans[comp[i]]){
      		cout << i + 1 << " ";
      	}
      }
      cout << "\n";
  }
  tm = clock()-tm ;
  cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
} 
