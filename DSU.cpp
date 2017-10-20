class DSU{
  public:
    vector<int> par,rank;
    void init(int n){
      par.assign(n,0);
      rank.assign(n,1);
      for(int i = 0; i < n ; ++i)par[i] = i;
    }
    int find(int x){
      return  ( (par[x] == x) ? x : par[x] = find(par[x]) );
    }
    int unite(int x, int y){
      x=find(x); y=find(y);
      if(x == y) return 0;
      if(rank[x] > rank[y])swap(x,y);
      par[x] = y;rank[y] += rank[x];
      return 1;
    }
}d;