// segtree + lazy update(add)
template<typename T>
struct SEGLAZY{
  #define c1 (curr<<1)
  #define c2 ((curr<<1)|1)
  #define mid ((l+r)>>1)
  T seg[4*N],lazy[4*N];
  bool upd[4*N];
  T combine(T x,T y){
    T ret = max(x,y); //lol
    return ret;
  }
  void build(int curr,int l,int r){
    if(l == r){
      seg[curr] = 0 ;// lol
      lazy[curr] = 0; //lol
      upd[curr] = 0;
      return;
    }
    build(c1,l,mid);build(c2,mid+1,r);
    seg[curr] = combine(seg[c1],seg[c2]);
  }
  void push(int curr,int l,int r){
    if(upd[curr]){
      seg[curr] = combine(seg[curr],(r-l+1)*lazy[curr]); //lol
      if(l != r){
        lazy[c1] = combine(lazy[c1],lazy[curr]);//lol
        lazy[c2] = combine(lazy[c2],lazy[curr]);//lol
        upd[c1] = upd[c2] = 1;
      }
      lazy[curr] = 0; //lol
      upd[curr] = 0;
    }
  }
  void update(int curr,int l,int r,int x,int y,T val){
    push(curr,l,r);
    if(l > r || x > r || y < l)return;
    if(x <= l && r <= y){
      lazy[curr] = combine(lazy[curr], val); //lol
      upd[curr] = 1;
      push(curr,l,r);
      return;
    }
    update(c1,l,mid,x,y,val);update(c2,mid+1,r,x,y,val);
    seg[curr] = combine(seg[c1] , seg[c2]);
  }
  T query(int curr,int l,int r,int x,int y){
    push(curr,l,r);
    if(l > r || x > r || y < l)return 0;
    if(x <= l && r <= y)return seg[curr];
    return combine(query(c1,l,mid,x,y) , query(c2,mid+1,r,x,y));
  }
};