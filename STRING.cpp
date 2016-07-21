#include <bits/stdc++.h>
 
using namespace std;

/*Problem: Given a list of string(size N) and queries(size M) of the form (l,r),make 
a lexicographically sorted array of size (r-l+1) and 
find sum i*size(s[i]) for that range for all distinct substrings*/

/*Constraints;
  N<=10^4
  Q<=10^4
  T<=10
  1<=l<=r<=N
*/
/*O(n*sqrt(n)*log(n))*/

#define INF 1000000007
#define MAX 10001
#define ROOT 100
#define BIG 1000000
#define EPS 1e-6
#define pi  2*acos(0)

typedef long long ll;

#define set0(a) memset(a,0,sizeof(a));
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

string A[MAX+1];
ll answ[MAX+1];
int POS[MAX+1];
map<string,int> M,F;
int ans=0;

struct node{
  int l,r,i;
}Q[MAX+1];

struct FEN{
  vector<int> T;
  int n;
  FEN(){n=0;T.clear();}
  FEN(int sz){n=sz;T.clear();T.resize(sz+1);}
  void clear(int sz){n=sz;T.clear();T.resize(sz+1);}
  void update(int i, int val){
    while(i<=n){
      T[i]+=val;
      i+=i&-i;
    }
  }
  int query(int i){
    ll ans=0;
    while(i>0){
      ans+=T[i];
      i-=i&-i;
    }
    return ans;
  }
}b1(MAX+1),b2(MAX+1);

bool cmp(node x,node y){
  if(x.l/ROOT!=y.l/ROOT){
    return x.l/ROOT < y.l/ROOT;
  }
  return x.r<y.r;
}

void add(int pos){
  F[A[pos]]++;
  if(F[A[pos]]==1){
    ans+=(b1.query(MAX)-b1.query(POS[pos]));
    ans+=(b2.query(POS[pos]-1)+1)*(sz(A[pos]));
    b1.update(POS[pos],sz(A[pos]));
    b2.update(POS[pos],1);
  }
}

void remove(int pos){
  F[A[pos]]--;
  if(F[A[pos]]==0){
    ans-=(b1.query(MAX)-b1.query(POS[pos]));
    ans-=(b2.query(POS[pos]-1)+1)*(sz(A[pos]));
    b1.update(POS[pos],-sz(A[pos]));
    b2.update(POS[pos],-1);
  }
}

int main() {
  fast; 
  int t;
  cin>>t;
  FOR(_t,1,t){

    M.clear();
    F.clear();
    ans=0;
    b1.clear(MAX+1),b2.clear(MAX+1);

    int n,q;
    cin>>n>>q;
    string s;
    
    FOR(i,0,n-1){
      cin>>A[i];
      M[A[i]]=0;
    }
    
    int N=1;
    tr(M,it)M[it->F]=N++;

    FOR(i,0,n-1){
      POS[i]=M[A[i]];
    }

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
      while(L<x){
        remove(L++);
      }
      while(L>x){
        add(--L);
      }
      while(R<y){
        add(++R);
      }
      while(R>y){
        remove(R--);
      }
      answ[Q[i].i]=ans;
    }
    FOR(i,0,q-1){
      cout<<answ[i]<<"\n";
    }
  }
  return 0;
} 

/*Sample test case: 
1
2 3
hey
dude
1 2
1 1
2 2

Output:
10
3
4
*/