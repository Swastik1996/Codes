vector<int> G[N];
int dep[N];
int _n = 0;
int pos[N],LCA[20][2*N];
void dfslca(int v,int p,int d){
	pos[v] = _n;
	dep[v] = d;
	LCA[0][_n] = v;
	_n++;
	for(int it : G[v]){
		if(it != p){
			dfslca(it,v,d+1);
		}
	}
	if(p != -1){
		LCA[0][_n] = p;
		_n++;
	}
}
void LCApre(){
	for(int i = 1; i < 20 ; ++i){
		for(int j = 0 ; j  + (1<<(i-1)) < _n; ++j){
			if(dep[LCA[i-1][j]] < dep[LCA[i-1][j+(1<<(i-1))]])LCA[i][j] = LCA[i-1][j];
			else LCA[i][j] = LCA[i-1][j+(1<<(i-1))];
		}
	}
}
int lca(int u,int v){
	u = pos[u];
	v = pos[v];
	if(u > v)swap(u,v);
	int lg2 = 31 - __builtin_clz(v-u+1);
	int c1 = LCA[lg2][u];
	int c2 = LCA[lg2][v - (1<<lg2) + 1];
	if(dep[c1] < dep[c2])return c1;
	return c2;
}
