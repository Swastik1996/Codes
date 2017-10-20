template<typename T>
struct BIT 
{
  vector<T> t;
  int n;
  BIT(int nn) { n = nn;t.assign(n,0);}
  void update(int i, T val){for(;i <= n;i += i & -i)t[i] += val;}
  T query(int i) {T ans = 0; for(;i > 0; i -= i & -i) ans += t[i]; return ans;}
};
