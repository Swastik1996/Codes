struct node{
	int a,la,ra,le;
};
int root[N];
template<typename T>
struct PST{
  #define mid ((l+r)>>1)
  T seg[100*N];
  int L[100*N],R[100*N];
  int ctr = 1;
  T combine(T x,T y){
    T ret;
    ... // something 
    return ret;
  }
  void build(int curr,int l,int r){
    if(l == r){
    	... // something
    	return;
    } // lol
    L[curr] = ctr++;
    R[curr] = ctr++;
    build(L[curr],l,mid);build(R[curr],mid+1,r);
    seg[curr] = combine(seg[L[curr]],seg[R[curr]]);
  }
  int update(int curr,int l,int r,int pos){
    int ncurr = ctr++;
    if(l == r){
    	seg[ncurr] = ... 
    	return ncurr;
    }
    L[ncurr] = L[curr];
    R[ncurr] = R[curr];
    if(pos <= mid)L[ncurr] = update(L[ncurr],l,mid,pos);
    else R[ncurr] = update(R[ncurr],mid+1,r,pos);
    curr = ncurr;
    seg[curr] = combine(seg[L[curr]],seg[R[curr]]);
    return curr;
  }
  T query(int curr,int l,int r,int x,int y){
    if(x <= l && r <= y)return seg[curr];
    if(x > mid)return query(R[curr],mid + 1,r,x,y);
    if(y <= mid)return query(L[curr],l,mid,x,y);
    return combine(query(L[curr],l,mid,x,y),query(R[curr],mid+1,r,x,y));
  }
};
PST<node> st;