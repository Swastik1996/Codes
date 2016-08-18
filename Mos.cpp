#include <bits/stdc++.h>
 
using namespace std;

#define INF 1000000007
#define MAX 200001
#define ROOT 450
#define BIG 1000000
#define EPS 1e-6
#define pi  2*acos(0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<ii,ii> pii;

#define MEMSET_INF 127 // about 2B
#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a)); 
#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll ctr[BIG+1],A[MAX+1],answ[MAX+1];
ll ans=0;
struct node{
  int l,r,i;
}Q[MAX+1];

bool cmp(node x,node y){
  if(x.l/ROOT!=y.l/ROOT){
    return x.l/ROOT < y.l/ROOT;
  }
  return x.r<y.r;
}

void add(int pos){
  
}

void remove(int pos){
  
}

int main() {
  fast; 
  int t;
  //cin>>t;
  FOR(_t,1,t){
    int n,q;
    cin>>n>>q;
    FOR(i,0,n-1)cin>>A[i];
    FOR(i,0,q-1){
      cin>>Q[i].l>>Q[i].r;
      Q[i].l--;
      Q[i].r--;
      Q[i].i=i;
    }
    sort(Q,Q+q,cmp);
    int L=1,R=0;
    FOR(i,0,q-1){
      int x=Q[i].l;
      int y=Q[i].r;
      while(L<x)remove(L++);
      while(L>x)add(--L);
      while(R<y)add(++R);
      while(R>y)remove(R--);
      answ[Q[i].i]=ans;
    }
    FOR(i,0,q-1){
      cout<<answ[i]<<"\n";
    }
  }
  return 0;
} 
