#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
ordered_set<ii> s;
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e3+10; 
const int L = 10;
const double eps = 1e-9;
const int BIG = 1e6;

int main(){
  
  fast;
  int __t = 1;
  //cin >> __t;
  FOR(_t,1,__t){
    	s.insert({1,1});
    	s.insert({3,1});
    	//cout << s.order_of_key(2) << "\n";
    	cout << (*s.find_by_order(1)).S << "\n";  
  }
  //tm = clock()-tm ;
  //cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
}
