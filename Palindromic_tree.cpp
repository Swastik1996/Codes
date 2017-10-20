#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 1e9+7;
const int N = 1e5+10; 

struct node {
	int next[26];
	int len;
	int sufflink;
	int num,l,r;
};

int len,num,suff;
node tree[N]; 
ll ans;
string s;
bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])     
            break;  
        cur = tree[cur].sufflink;
    }       
    if (tree[cur].next[let]) {  
        suff = tree[cur].next[let];
        tree[suff].num ++;
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[num].r = pos;
    tree[num].l = pos - tree[num].len + 1; 
    tree[cur].next[let] = num;
    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    tree[num].num ++;
    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }       
    }
    return true;
}

void initTree() {
	num = 2; suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
	tree[1].num = tree[2].num = 0;
}
vi G[N];
void dfs(int v){
	for(auto it : G[v]){
		dfs(it);
		tree[v].num += tree[it].num;
	}
}
void GetPalindrome(){
	initTree();
	int len = sz(s);
	for (int i = 0; i < len; i++){
		addLetter(i);
	}
	for(int i = 2 ;i <= num; i++){
		G[tree[i].sufflink].pb(i);
	}
	dfs(1);
	for(int i = 3; i <= num ;i++){
		//cout << tree[i].num << " " << tree[i].l << " " << tree[i].r << "\n";
	}
}
int main() {
	fast;
	int n,q;cin >> n >> q >> s;


	
	return 0;
}   