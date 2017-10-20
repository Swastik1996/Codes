int A[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll mulmod(ll a,ll b,ll mod){
    a%=mod;b%=mod;
	long double res=a;
	res*=b;
	ll c=(ll)(res/mod);
	a*=b;
	a-=c*mod;
	a%=mod;
	if(a<0)a+=mod;
	return a;
}
ll expo(ll a,ll b,ll c = mod){
	if(!b)return 1;
	ll temp = expo(a,b/2,c);
	temp = temp*temp%c;
	if(b&1)temp = temp*a%c;
	return temp;
}
bool Miller(ll p){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    for(int i=0;i<25;i++){
		if(p==A[i])return true; 
		else if(p%A[i]==0)return false;
    }	
    ll s=p-1;
    ll d=0;
    while(s%2==0){
        s/=2;d++;
    }
    for(int i=0;i<3;i++)
	{	
		ll a=rand()%(p-1)+1,temp=s;
		ll mod=expo(a,temp,p);
		if(mod==1||mod==p-1) continue;
		int flag=0;
		for(int j=1;j<d;j++)
		{
			mod=mulmod(mod,mod,p);
			if(mod==1)return false;
			if(mod==p-1)
			{	flag=1;
				break;
			}
		}
		if(flag)continue; 
		return false;
	}
	return true;
}