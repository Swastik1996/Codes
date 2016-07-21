struct FEN{
  vector<int> T;
  int n;
  FEN(){n=0;T.clear();}
  FEN(int sz){n=sz;T.clear();T.resize(sz+1);}
  void clear(int sz){n=sz;T.clear();T.resize(sz+1);}
  void update(int i, int val){
    while(i<=n){
      T[i]+=val;
      i+=i&-i;
    }
  }
  int query(int i){
    ll ans=0;
    while(i>0){
      ans+=T[i];
      i-=i&-i;
    }
    return ans;
  }
}