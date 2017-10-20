// segtree + lazy update(change + add)
template<typename T>
struct SEGLAZY{
  #define c1 (curr<<1)
  #define c2 ((curr<<1)|1)
  #define mid ((l+r)>>1)
  T seg[4*N],lazy[4*N][2];
  bool upd[4*N][2];
  T combine(T x,T y){
    T ret = x,y; //lol
    return ret;
  }
  void build(int curr,int l,int r){
    if(l == r){
      seg[curr] =  ;// lol
      lazy[curr][0] = lazy[curr][1] =  0; //lol
      upd[curr][0] = upd[curr][1] = 0;
      return;
    }
    build(c1,l,mid);build(c2,mid+1,r);
    seg[curr] = combine(seg[c1],seg[c2]);
  }
  void push(int curr,int l,int r){
    if(upd[curr][1]){
      seg[curr] = (r-l+1)*lazy[curr][1];
      if(l != r){
        upd[c1][1] = upd[c2][1] = 1;
        lazy[c1][1] = lazy[c2][1] = lazy[curr][1];
        lazy[c1][0] = lazy[c2][0] = 0;
        upd[c1][0] = upd[c2][0] = 0;
      }
      lazy[curr][1] = 0; 
      upd[curr][1] = 0;
    }
    if(upd[curr][0]){
      seg[curr] = combine(seg[curr],(r-l+1)*lazy[curr][0]); //lol
      if(l != r){
        lazy[c1][0] = combine(lazy[c1][0],lazy[curr][0]);//lol
        lazy[c2][0] = combine(lazy[c2][0],lazy[curr][0]);//lol
        upd[c1][0] = upd[c2][0] = 1;
      }
      lazy[curr][0] = 0; //lol
      upd[curr][0] = 0;
    }
  }
  void updaterep(int curr,int l,int r,int x,int y,T val){
    push(curr,l,r);
    if(l > r || x > r || y < l)return;
    if(x <= l && r <= y){
      lazy[curr][1] = val; //lol
      upd[curr][1] = 1;
      push(curr,l,r);
      return;
    }
    updaterep(c1,l,mid,x,y,val);updaterep(c2,mid+1,r,x,y,val);
    seg[curr] = combine(seg[c1] , seg[c2]);
  }
  void updateadd(int curr,int l,int r,int x,int y,T val){
    push(curr,l,r);
    if(l > r || x > r || y < l)return;
    if(x <= l && r <= y){
      lazy[curr][0] = combine(lazy[curr][0], val); //lol
      upd[curr][0] = 1;
      push(curr,l,r);
      return;
    }
    updateadd(c1,l,mid,x,y,val);updateadd(c2,mid+1,r,x,y,val);
    seg[curr] = combine(seg[c1] , seg[c2]);
  }
  T query(int curr,int l,int r,int x,int y){
    push(curr,l,r);
    if(l > r || x > r || y < l)return 0;
    if(x <= l && r <= y)return seg[curr];
    return combine(query(c1,l,mid,x,y) , query(c2,mid+1,r,x,y));
  }
}st;