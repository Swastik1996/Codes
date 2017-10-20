const int N = 820; 
//Mincost code start
#define M N*N
int last[N], tlast[N], d[N], v[N];
int ver[M*2], nexxt[M*2], c[M*2], cost[M*2];
int S,T,ptr;

void addEdge(int from, int to, int cap, int co) {
    // cout << from << " " << to << endl;
    ver[ptr] = to; c[ptr] = cap; cost[ptr] = co; nexxt[ptr] = last[from]; last[from] = ptr++;
    ver[ptr] = from; c[ptr] = 0; cost[ptr] = -co; nexxt[ptr] = last[to]; last[to] = ptr++;
}
int opp(int n) { return (n&1)?n+1:n-1; }
bool relable() {
    int add = 0x7fffffff;
    FOR(i,0,T) if(v[i]) for(int j=tlast[i]; j; j = nexxt[j]) if(v[ver[j]]==0 && c[j] && (add > (d[ver[j]]+cost[j]-d[i])))
            add = d[ver[j]] + cost[j] - d[i];
    if(add == 0x7fffffff) return false;
    FOR(i,0,T) if(v[i]) {
        v[i] = false;
        d[i] += add;
        last[i] = tlast[i];
    } 
    return true;
}
int dfs(int cur, int flow) {
    if(cur == T) return flow;
    v[cur] = 1;
    int t;
    for(int &i=last[cur]; i; i = nexxt[i]) if(c[i] && v[ver[i]]==0 && d[cur] == d[ver[i]]+cost[i] && (t = dfs(ver[i], (flow < c[i]?flow:c[i])))) {
        c[i] -= t;
        c[opp(i)] += t;
        v[cur] = 0;
        return t;
    }
    return 0;
}
int MCMF(int _S, int _T) {
    S = _S;
    T = _T;
    int ans = 0;
    FOR(i,0,T) d[i] = 0, tlast[i] = last[i], v[i] = 0;
    do {
        int t;
        while(t=dfs(S,0x7fffffff)) {
            ans += t*d[S];
        }
    } while(relable());
    return ans;
}
//Mincost code end
int main(){
  fast;
  int S = 0, T = 2*n + 1;ptr = 1;
  int offset = 1e6;
  FOR(i,0,n-1)addEdge(S,i+1,1,0);
  MCMF(S,T);
  FOR(i,0,n-1){
    int x = -1;
    for(int j = tlast[i+1] ; j ; j = nexxt[j]){
        if(ver[j] != 0 && c[j] == 0)x = ver[j] - n - 1;
    }
    cout << x + 1 << " ";
  }
  return 0;
}