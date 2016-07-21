int f[N];
int main(){
  clock_t tm = clock();
  fast;
  int __t = 1;
  //cin >> __t;
  FOR(_t,1,__t){
      string t,p;
      cin >> p;
      int m = sz(p);
      //int n = sz(t);
      p = "$" + p;
      f[0] = 0;
      FOR(i,2,m+1){
      	int j = f[i-1];
      	while(j>0 && p[j] != p[i-1] )j = f[j];
        f[i] = j +1;
      }
      FOR(i,0,m){
        cout << f[i] << " " ;
      }
      cout << "\n";
      /*int j = 1;
      FOR(i,0,n-1){
        while( j>0 && t[i] != p[j])j = f[j];
        if(j == m){
          cout << i - j + 1 << "\n";
          j = f[j];
        }
        j++;
      }*/
  }
  tm = clock()-tm ;
  cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
} 
