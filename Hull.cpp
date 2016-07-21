ii pivot;

ll area2(ii a,ii b,ii c){
  return a.F*b.S - a.S*b.F + b.F*c.S - b.S*c.F + c.F*a.S - c.S*a.F; 
}

ll dist2(ii a,ii b){
  int dx=a.F-b.F;
  int dy=a.S-b.S;
  return dx*dx + dy*dy;
}

bool cmp(ii a,ii b){
  if(area2(pivot,a,b)==0)//collinear
     return dist2(pivot,a) < dist2(pivot,b);
   int d1x=a.F-pivot.F,d1y=a.S-pivot.S;
   int d2x=b.F-pivot.F,d2y=b.S-pivot.S;
   return atan2((double)d1y,(double)d1x)<atan2((double)d2y,(double)d2x);
}
vector<ii> Grah(vector<ii> P){
  int i,p=0,n=sz(P);
  FOR(i,1,n-1){
    if(P[i].S<P[p].S||(P[i].S==P[p].S&&P[i].F>P[p].F))p=i;
  }
  swap(P[p],P[0]);
  pivot=P[0];
  sort(++P.begin(),P.end(),cmp);

  stack<ii> s;
  ii prev,now;
  s.push(P[n-1]);
  s.push(P[0]);

  i=1;
  while(i<n){
    now=s.top();
    s.pop();prev=s.top();s.push(now);
    if(area2(prev,now,P[i])>0){
      s.push(P[i]);
      i++;
    }
    else{
      s.pop();
    }
  }
  vector<ii> C;
  while(!s.empty()){
    C.pb(s.top());
    s.pop();
  }
  C.pop_back();
  return C;
}
void solve(){
	   int n,m;
     vector<ii> N,M;
     cin>>n;
     FOR(i,0,n-1){
      int x,y;
      cin>>x>>y;
      N.pb(mp(x,y));
      M.pb(mp(x,y));
     }
     cin>>m;
     FOR(i,0,m-1){
      int x,y;
      cin>>x>>y;
      M.pb(mp(x,y));
     }
     vector<ii> a=Grah(M);
     tr(a,it){
      cout<<it->F<<" "<<it->S<<"\n";
     }

     sort(all(N));
     sort(all(a));

     if(sz(N)!=sz(a)){
      cout<<"NO\n";
      return;
     }
     int flag=1;
     FOR(i,0,sz(N)-1){
      if(N[i]!=a[i])flag=0;
     }
     if(flag){
      cout<<"YES\n";
     }
     else{
      cout<<"NO\n";
     }

}