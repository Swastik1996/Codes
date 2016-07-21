#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define all(x) x.begin(), x.end()
#define tr(x,it) for( auto it = x.begin(); it!=x.end(); ++it)
#define rtr(x,it) for( auto it = x.rbegin(); it!=x.rend(); ++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n" 

const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5+10; 
const double eps = 1e-6;
const int BIG = 1e6;

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
