
vector <int> adj[MAX],costs[MAX],indexx[MAX];
int Array[MAX],size;
int chainNo,chainInd[MAX],chainHead[MAX],posInA[MAX];
int depth[MAX], pa[LMAX][MAX], otherEnd[MAX], subsize[MAX];
int st[6*MAX];

void update_tree(int cur,int a,int b,int i,int j,int val){
	
	if( a > b|| a > j|| i > b) return;
	
	if(i <= a && b <= j ) {
		st[cur] = val;
		return;
	}
	
	int c1 = (cur<<1), c2 = c1 | 1, m = (a+b)>>1;
	
	update_tree(c1, a, m, i, j, val);
	update_tree(c2, m+1, b, i, j, val);
	
	st[cur] = max( st[c1] , st[c2] );
}

int query_tree(int cur, int a, int b, int i, int j) {
	
	if( a > b|| a > j|| i > b) return -1;
	
	if(i <= a && b <= j ) return st[cur];
	
	int c1 = (cur<<1), c2 = c1 | 1, m = (a+b)>>1;
	
	return max( query_tree(c1, a, m, i, j), query_tree(c2, m+1, b, i, j) );
	
}

int query_up(int u, int v) {
	
	if(u == v) return 0;
	
	int uchain, vchain = chainInd[v], ans = -1;
	
	while(1) {

		uchain = chainInd[u];
		if(uchain == vchain) {
			if(u==v) break;
			int qt=query_tree(1, 0, size-1, posInA[v]+1, posInA[u]);
			if(qt > ans) ans = qt;
			break;
		}

		int qt = query_tree(1, 0, size-1, posInA[chainHead[uchain]], posInA[u]);

		if(qt > ans) ans = qt;
		u = chainHead[uchain]; 
		u = pa[0][u]; 
	}

	return ans;
}

int LCA(int u, int v) {

	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	FOR(i,0,LMAX-1) if((diff>>i)&1) u = pa[i][u];
	
	if(u == v) return u;
	
	NFOR(i,LMAX-1,0) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	
	return pa[0][u];
}

int query(int u, int v) {

	int lca = LCA(u, v);
	return max(query_up(u, lca), query_up(v, lca)); 
}

void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, size-1, posInA[u], posInA[u], val);
}

void HLD(int Node, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = Node; 
	}
	chainInd[Node] = chainNo;
	posInA[Node] = size; 
	Array[size++] = cost;

	int sc = -1, ncost;
	FOR(i,0,sz(adj[Node])-1) if(adj[Node][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[Node][i]]) {
			sc = adj[Node][i];
			ncost = costs[Node][i];
		}
	}

	if(sc != -1) {
		HLD(sc, ncost, Node);
	}

	FOR(i,0,sz(adj[Node])-1) if(adj[Node][i] != prev) {
		if(sc != adj[Node][i]) {
			chainNo++;
			HLD(adj[Node][i], costs[Node][i], Node);
		}
	}
}

void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	FOR(i,0,sz(adj[cur])-1)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		size = 0;
		int n;
		memset(st,0,sizeof(st));
		cin>>n;
		FOR(i,0,n-1){
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			FOR(j,0,LMAX-1)pa[j][i]=-1;
		}
		FOR(i,1,n-1){
			int u, v, c;
			cin>>u>>v>>c;
			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		chainNo = 0;
		dfs(0, -1); 
		HLD(0, -1, -1);
		FOR(i,0,size-1){
			update_tree(1 ,0 ,size-1 ,i ,i ,Array[i]);
		}

		FOR(i,1,LMAX-1)
			FOR(j,0,n-1)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

		while(1) {
			char s[100];
			scanf("%s",s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				cout<<query(a-1, b-1)<<"\n";
			} else {
				change(a-1, b);
			}
		}
	}
	return 0;
}    