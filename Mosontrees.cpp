#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define pb push_back
#define all(x) x.begin(),x.end() 
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a)) 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 2e5 + 10;
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
const int ROOT = 420;
struct node{
  int l,r,e,i;
}Q[N];

bool cmp(node x,node y){
  if(x.l/ROOT!=y.l/ROOT){
    return x.l/ROOT < y.l/ROOT;
  }
  return x.r<y.r;
}
int T = 1;
vector<int> G[N];
int dep[N];
int _n = 0;
int pos[N],LCA[20][2*N];
void dfslca(int v,int p = 0,int d = 0){
  pos[v] = _n;
  dep[v] = d;
  LCA[0][_n] = v;
  _n++;
  for(int it : G[v]){
    if(it != p){
      dfslca(it,v,d+1);
    }
  }
  if(p != 0){
    LCA[0][_n] = p;
    _n++;
  }
}
void LCApre(){
  for(int i = 1; i < 20 ; ++i){
    for(int j = 0 ; j  + (1<<(i-1)) < _n; ++j){
      if(dep[LCA[i-1][j]] < dep[LCA[i-1][j+(1<<(i-1))]])LCA[i][j] = LCA[i-1][j];
      else LCA[i][j] = LCA[i-1][j+(1<<(i-1))];
    }
  }
}
int lca(int u,int v){
  u = pos[u];
  v = pos[v];
  if(u > v)swap(u,v);
  int lg2 = 31 - __builtin_clz(v-u+1);
  int c1 = LCA[lg2][u];
  int c2 = LCA[lg2][v - (1<<lg2) + 1];
  if(dep[c1] < dep[c2])return c1;
  return c2;
}
int st[N],en[N],val[N];
void dfs(int u,int p = 0){
  st[u] = T++;
  val[T - 1] = u;
  for(auto it : G[u]){
    if(it == p)continue;
    dfs(it,u);
  }
  en[u] = T++;
  val[T - 1] = u;
}
int fr[N],bg[N],f[N],freq[2][N];
ll ans[N];
ll ANS = 0;
void add(int pos){
  if(pos == -1)return; 
  int v = val[pos];
  fr[v] ^= 1;
  if(fr[v] == 1){
    ANS += freq[bg[v]^1][f[v]];
    freq[bg[v]][f[v]] += 1;
  }
  else{
    ANS -= freq[bg[v]^1][f[v]];
    freq[bg[v]][f[v]] -= 1;
  }
} 
int main(){
    fast;
    fill(dep, 0);
    fill(freq, 0);
    fill(fr, 0);
    int n;cin >> n;
    FOR(i,1,n)cin >> bg[i];
    vi com;
    FOR(i,1,n){
      cin >> f[i];
      com.pb(f[i]);
    }
    sort(all(com));
    com.erase(unique(all(com)),com.end()); 
    FOR(i,1,n){
      f[i] = lower_bound(all(com), f[i]) - com.begin();
    }
    FOR(i,1,n-1){
      int u,v;cin >> u >> v;
      G[u].pb(v);
      G[v].pb(u);
    }
    dfs(1);
    dfslca(1);
    LCApre();
    int q;cin >> q;
    FOR(i,0,q-1){
      int l,r;cin >> l >> r;
      if(st[l] > st[r])swap(l,r);
      int p = lca(l,r);
      if(p == l){
        Q[i].l = st[l];
        Q[i].r = st[r];
        Q[i].e = -1;
      }
      else{
        Q[i].l = en[l];
        Q[i].r = st[r];
        Q[i].e = st[p];
      }
      Q[i].i = i;
    }
    sort(Q,Q + q, cmp);
    int L = 1,R = 0;
    FOR(i,0,q-1){
      int x = Q[i].l,y = Q[i].r;
      while(L > x)add(--L);
      while(R < y)add(++R);
      while(L < x)add(L++);
      while(R > y)add(R--);
      add(Q[i].e);
      ans[Q[i].i] = ANS;
      add(Q[i].e);
    }
    FOR(i,0,q-1){
      cout << ans[i] << "\n";
    }
    return 0; 
}
