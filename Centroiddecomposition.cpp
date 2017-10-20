int nn = 0;
void dfs1(int node,int p){
	sub[node] = 1;
	nn++;
	for(auto it : G[node]){
		if(it == p)continue;
		dfs1(it,node);
		sub[node] += sub[it];
	}
}
int dfs2(int node,int p){
	for(auto it : G[node]){
		if(it == p)continue;
		if(sub[it] > nn/2)return dfs2(it,node);
	}
	return node;
}
void decompose(int node,int p){
	nn = 0;
	dfs1(node,node);
	int centroid = dfs2(node,node);
	if(p == 0)p = centroid;
	par[centroid] = p;
	for(auto it : G[centroid]){
		G[it].erase(centroid);
		decompose(it,centroid);
	}
	G[centroid].clear();
}