class DSU{
  public:
    int par[N],rank[N];
    void init(int n){
      FOR(i,0,n){
        par[i] = i;rank[i] = 1;
      }
    }
    int find(int x){
      if(par[x] == x) return x;
      par[x] = find(par[x]);
      return par[x];
    }
    void unite(int x, int y){
      x=find(x); y=find(y);
      if(x == y) return;
      if(rank[x] > rank[y])swap(x,y);
      par[x] = y;rank[y] += rank[x];
    }
    bool same(int x, int y){
      return find(x) == find(y);
    }
}d;