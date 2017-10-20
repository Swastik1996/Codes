#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define pb push_back
#define all(x) x.begin(),x.end() 
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a)) 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5 + 10; 
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
int a[N];
vi seg[30 * N], cnt[30 * N];
void build(int curr){
	assert(curr < 30 * N);
	assert(sz(seg[curr]) > 0);
	int mn = seg[curr][0];
	int mx = seg[curr][0];
	for(auto it : seg[curr]){
		mx = max(mx, it);
		mn = min(mn, it);
	}
	if(mn == mx)return;
	cnt[curr] = vi(sz(seg[curr]), 0);
	int md = (mn + mx) >> 1;
	int c1 = curr << 1;
	int c2 = c1 | 1;
	int last = 0;
	FOR(i, 0, sz(seg[curr]) - 1){
		int it = seg[curr][i];
		if(it <= md){
			seg[c1].pb(it);
			cnt[curr][i] = last + 1;
			last += 1;
		}
		else{
			seg[c2].pb(it);
			cnt[curr][i] = last;
		}
	}

	build(c1);
	build(c2);
}
void print(int curr){
	if(sz(seg[curr]) == 0)return;
	for(auto it : seg[curr]){
		cout << it << " ";
	}
	cout << "\n";
	print(curr << 1);
	print((curr << 1) | 1);
}
int query(int curr,int l,int r,int k){
	//cout << curr << " " << l << " " << r << " " << k << "\n";
	assert(sz(seg[curr]) > 0);
	if(sz(seg[curr << 1]) == 0){
		return seg[curr][0];
	}
	assert(r < sz(cnt[curr]));
	int nl = (l ? cnt[curr][l-1] : 0);
	int nr = cnt[curr][r];
	int x = nr - nl;
	if(k <= x){
		return query(curr << 1, nl, nr - 1, k);
	}
	else{
		return query((curr << 1) | 1, l - nl, r - nr, k - x);
	}
}
int main(){
  fast;
  int n,m; cin >> n >> m;
  FOR(i,1,n){
  	cin >> a[i];
  	seg[1].pb(a[i]);
  }
  build(1);
  //print(1);
  FOR(i,1,m){
  	int l,r,k;cin >> l >> r >> k;
  	l--,r--;
  	cout << query(1, l, r, k) << "\n";
  }
  return 0;
}