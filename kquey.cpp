#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
//#define ONLINE
#define CASE(t) cout << "Case " << t << ": ";

#ifdef ONLINE
 FILE *fin = freopen("cubes.in","r",stdin);
 //FILE *fout = freopen("out.txt","w",stdout);
#endif

const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 3e4+10; 
const int L = 10;
const double eps = 1e-9;
const int BIG = 1e6;

vi v[6*N];
int a[N];
int n;
void update(int curr,int i,int j){
	if( i > j || j < 0 || i >= n ){
		return;
	}
	if( i == j ){
		v[curr].pb(a[i]);
		return;
	}
	int c1 = curr << 1,c2 = c1 | 1 , mid = (i + j)/2;
	update(c1,i,mid);
	update(c2,mid+1,j);
	merge(all(v[c1]),all(v[c2]),back_inserter(v[curr]));
}
int query(int curr,int i,int j,int x,int y,int k){

	if( i > j || j < x || i > y){
		return 0;
	}
	if( x <= i && j <= y){
		
		return ((sz(v[curr])) - (upper_bound(all(v[curr]),k)-v[curr].begin()));
	}
	int c1 = curr << 1,c2 = c1 | 1 , mid = (i + j)/2;
	return query(c1,i,mid,x,y,k) + query(c2,mid+1,j,x,y,k);
}
int main(){
  
  clock_t tm = clock();
  fast;
  int __t = 1;
  //cin >> __t;
  FOR(_t,1,__t){
      cin >> n;
      FOR(i,0,n-1){
      	cin >> a[i];
      }
      update(1,0,n-1);
      int q;
      cin >> q;
      int ans = 0;
      while(q--){
      	int a,b,c;
      	cin >> a >> b >> c;
      	int i = ans^a;
      	int j = ans^b;
      	int k = ans^c;
      	i--,j--;
      	if( i < 0)i = 0;
      	if( j > n - 1)j = n -1;
      	//cout << i << " " << j << " " << k << "\n"; 
      	ans = query(1,0,n-1,i,j,k);
      	cout << ans << "\n";
      }

  }
  tm = clock()-tm ;
  cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
}