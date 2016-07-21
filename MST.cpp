int p[N];
void init(){
  FOR(i,0,MAXN-1)p[i]=i;
}
int root(int x){
  return p[x]==x?x:p[x]=root(p[x]);
}
void uni(int i,int j){
  p[root(i)]=root(j);
}
int same(int i,int j){
  return root(i)==root(j);
}

priority_queue<pair<int,ii> > Q;
void solve(){
	 int n,m,p;
   cin>>p;
   cin>>n>>m;
   init();
   FOR(i,0,m-1){
    int u,v,x;
    cin>>u>>v>>x;
    u--;v--;
    Q.push(mp(-x,mp(u,v)));
   }
   ll sum=0;
   while(!Q.empty()){
      pair<int,ii> tp=Q.top();
      Q.pop();
      if(!same(tp.S.F,tp.S.S)){
        sum-=tp.F;
        uni(tp.S.F,tp.S.S);
      }
   }
   cout<<sum*p<<"\n";
}

int main(){
  clock_t tm=clock();
  fast;
  int t=1;
  cin>>t;
  FOR(_t,1,t){
      //cout<<"Case #"<<_t<<": ";
       solve();
  }	
  tm=clock()-tm;
  cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";
  return 0;
} 
