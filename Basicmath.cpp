int phi[N];
void PHI(int n){
  for(int i = 1; i < n; ++i)phi[i] = i;
  for(int i = 2; i < n; ++i)
    if(phi[i] == i)
      for(int j = i;j < N;j+=i)
        phi[j] -= phi[j]/i;
}
int pf[N];
void PRIMES(int n){
  for(int i = 1; i< n ; ++i)pf[i] = i;
  for(int i = 2; i*i < N; i++){
    if(pf[i] == i){
      for(int j = i*i ; j < N; j+=i ){
        pf[j] = i; 
      }
    }
  }
}
int mob[N];
void MOB(int n){
  for(int i = 1; i < n ; ++i)mob[i] = 1;
  for(int i = 2; i < N ; i++){
    if(pf[i] == i){
      if(1LL * i * i < N){
        for(int j = i*i ; j < N ; j += (i*i) ){
          mob[j] = 0;
        }
      }
      for(int j = i ; j < N ; j+=i){
        mob[j] *= -1;
      }
    }
  }
}
int fac[N],ifac[N],inv[N];
void FAC(int n){
  fac[0] = ifac[0] = inv[1] = 1;
  for(int i = 1; i < n; ++i)fac[i] = 1LL*i*fac[i-1] % mod;
  for(int i = 2; i < n; ++i)inv[i] = mod - ((mod/i)*1LL*inv[mod%i]) % mod;
  for(int i = 1; i < n; ++i)ifac[i] = 1LL*ifac[i-1]*inv[i] % mod;
}
inline int C(int n,int k){
  if(k > n)return 0;
  return  1LL * ifac[n-k]*( (1LL*fac[n]*ifac[k]) % mod ) % mod; 
}