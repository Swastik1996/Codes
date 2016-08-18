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
//#define ONLINE
#define CASE(t) cout << "Case " << t << ": ";

#ifdef ONLINE
 FILE *fin = freopen("cubes.in","r",stdin);
 //FILE *fout = freopen("out.txt","w",stdout);
#endif

const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e3+10; 
const int L = 10;
const double eps = 1e-9;
const int BIG = 1e6;

ii T[12*N];
int count;
int bit = 30;
int new_node(){
	++count;
	T[count].F = T[count].S = 0;
	return count;
}

int rev(int val, int it = bit){
	int ret = 0;
	while(it--){
		res <<= 1;
		res |= val&1;
		val >>=1;
	}
	return res;
}

int add(int t,int val,int it = bit){
	if(!t){
		t = new_node();
	}
	if(it){
		if(val&1){
			T[t].S = add(T[t].S,val >> 1,it - 1);
		}
		else{
			T[t].F = add(T[t].F,val >> 1,it - 1);
		}
	}
	return t;
}
int get(int i,int val,int it = bit ,int st = 0){
	if(it){
		int son = val&1 ? T[t].F : T[t].S;
		if(son){
			return get(son,val>>1,it - 1,(st << 1)|1);
		}
		else{
			son = val&1 ? T[t].S : T[t].F;
			return get(son,val>>1,it - 1,(st << 1));
		}
	}
	else{
		return st;
	}
}
int main(){
  
  clock_t tm = clock();
  fast;
  int __t = 1;
  cin >> __t;
  FOR(_t,1,__t){
      
  }
  tm = clock()-tm ;
  cerr << (float)(tm)/CLOCKS_PER_SEC << "\n";
  return 0;
}