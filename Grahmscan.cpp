pair<pll,int> arr[N];
pll operator -(pll a,pll b){
  return mp(a.X-b.X,a.Y-b.Y);
}
int aclk(pll a,pll b,pll c){
  b=b-a; c=c-a;

  return ((b.X * c.Y) - (b.Y * c.X))>0;
}
int clk(pll a,pll b,pll c){
  b=b-a; c=c-a;
  return b.X*c.Y-b.Y*c.X<0;
}
pll mx; 
int cmp(pair<pll,int> a,pair<pll,int> b){
  return aclk(mx,a.X,b.X);
}
#define tri pair<pii,int>
vector<tri> ans;
vector<int> q;
int main(){
  int n; scanf("%d",&n);
  mx=mp(mod,mod);
  int p=0;
  REP(i,n){
    pll z ; scanf("%lld%lld",&z.X,&z.Y);
    if(z<mx) mx=z,p=i;
    arr[i]=mp(z,i);
  }
  swap(arr[p],arr[0]);
  sort(arr+1,arr+n,cmp);
  REPP(i,1,n-1){
    ans.pb(mp(mp(arr[0].Y,arr[i].Y),arr[i+1].Y));
  }
  
 // printf("zz\n");
  //q.pb(1); q.pb(2);
  REPP(i,1,n){
    //printf("%d\n",(int)q.size());
    while(q.size()>1&&clk(arr[q[q.size()-2]].X,arr[q.back()].X,arr[i].X)) {
      ans.pb(mp(mp(arr[q[q.size()-2]].Y,arr[q.back()].Y),arr[i].Y));
      q.pop_back();
    }
    q.pb(i);
  }
  printf("%d\n",(int) ans.size());
  REP(i,ans.size()){
    printf("%d %d %d\n",ans[i].X.X+1,ans[i].X.Y+1,ans[i].Y+1);
  }
  return 0;
}