template<typename T>
struct SEGTREE{
  #define c1 (curr<<1)
  #define c2 ((curr<<1)|1)
  #define mid ((l+r)>>1)
  T seg[4*N];
  T combine(T x,T y){
    T ret;
    ret = max(x , y); // lol
    return ret;
  }
  void build(int curr,int l,int r){
    if(l == r)return void(seg[curr] = 0); // lol
    build(c1,l,mid);build(c2,mid+1,r);
    seg[curr] = combine(seg[c1],seg[c2]);
  }
  void update(int curr,int l,int r,int x,int y,T val){
    if(x > r || y < l)return;
    if(x <= l && r <= y)return void(seg[curr] = val); // lol
    update(c1,l,mid,x,y,val);update(c2,mid+1,r,x,y,val);
    seg[curr] = combine(seg[c1],seg[c2]);
  }
  T query(int curr,int l,int r,int x,int y){
    if(x > r || y < l)return 0; // lol
    if(x <= l && r <= y)return seg[curr];
    return combine(query(c1,l,mid,x,y),query(c2,mid+1,r,x,y));
  }
};
