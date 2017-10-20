const int SZ = 3;
struct matrix{
  int a[SZ][SZ];
};
matrix operator * (const matrix &m1,const matrix &m2){
  matrix m = {{}};
  FOR(i,0,SZ-1)FOR(j,0,SZ-1)FOR(k,0,SZ-1)m.a[i][k] = (m.a[i][k] + 1LL*m1.a[i][j]*m2.a[j][k]) % mod;
  return m;
}
matrix operator + (const matrix &m1,const matrix &m2){
  matrix m = {{}};
  FOR(i,0,SZ-1)FOR(j,0,SZ-1)m.a[i][j] = (m1.a[i][j]+m2.a[i][j])%mod;
  return m;
}
void makeid(matrix &m){
  FOR(i,0,SZ-1){
    FOR(j,0,SZ-1){
      m.a[i][j] = i==j;
    }
  }
}
matrix expo(matrix a,ll b){
  if(b == 0){
    matrix ret;
    makeid(ret);return ret;
  }
  matrix ret = expo(a,b/2);
  ret = ret*ret;
  if(b&1)ret = ret*a;
  return ret;
}
