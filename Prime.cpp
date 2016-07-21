vector<bool> isprime;
vector<int> primes;
void sieve(int n){
  if((int)isprime.size() >= n+1) return;
  isprime.assign(n+1, true);
  isprime[0] = isprime[1] = false;
  int sqrtn = (int)(sqrt(n * 1.) + .5);
  for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
    for(int j = i * i; j <= n; j += i)
      isprime[j] = false;
  }
  primes.clear();
  for(int i = 2; i <= n; i ++) if(isprime[i])
    primes.push_back(i);
}
 
vector<int> mobiusMu;
void calcMobiusMu() {
  int n = (int)isprime.size() - 1;
  mobiusMu.assign(n+1, 1);
  for(int i = 2; i <= n; i ++) if(isprime[i]) {
    if((ll)i * i <= n) {
      for(int j = i * i; j <= n; j += i * i)
        mobiusMu[j] = 0;
    }
    for(int j = i; j <= n; j += i)
      mobiusMu[j] *= -1;
  }
}