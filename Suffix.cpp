vector<vi> P;
vector<pair<ii,int> > M;
int n;
void Suffix(string s){
  n = sz(s);
  P.pb(vi(n,0));M.resize(n);
  FOR(i,0,n-1)P[0][i] = s[i]-'a';
  for(int s = 1,l = 1; s < n ; s*=2,l++){
    P.pb(vi(n,0));
    FOR(i,0,n-1)M[i] = {{P[l-1][i],(i+s<n?P[l-1][i+s]:-1)},i};
    sort(M.begin(), M.end());
    FOR(i,0,n-1){
      P[l][M[i].S] = ((i>0 && M[i].F == M[i-1].F) ? P[l][M[i-1].S] : i);
    }
  }
}
int LCP(int i,int j){
  int len = 0;
  if(i == j)return n-i;
  for(int k = sz(P)-1; k >=0 && i < n && j < n; k--){
    if(P[k][i] == P[k][j]){
      i += (1<<k);j += (1<<k);len += (1<<k);
    }
  }
  return len;
}