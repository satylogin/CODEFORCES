#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define p(n) printf("%d",&n)
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
vector<int>adj[200005];
int dp[200005];
bool vis[200005];
int a[200005];
vector<int>v;
int cn[200005];
void dfs1(int node,int gc)
{
	vis[node] = true;
	gc = __gcd(gc,a[node]);
	dp[node] = gc;
	for(auto i : adj[node]){
		if(!vis[i]){
			dfs1(i,gc);
		}
	}
}
void dfs2(int node,int lev)
{
	for(int i = 0;i < v.size();i++){
		if(a[node]%v[i] == 0){
			cn[v[i]]++;
		}
	}
	int an = 0;
	for(int i = 0;i < v.size();i++){
		if(cn[v[i]] >= lev){
			an = max(an,v[i]);
		}
	}
	dp[node] = max(dp[node],an);
	vis[node] = true;
	for(auto i : adj[node]){
		if(!vis[i]){
			dfs2(i,lev+1);
		}
	}
	for(int i = 0;i < v.size();i++){
		if(a[node]%v[i] == 0){
			cn[v[i]]--;
		}
	}
}
int main()
{
	int i,j,k,l,m,n,t;
	cin >> n;
	for(i = 1;i <= n;i++){
		cin >> a[i];
	}
	int u,v2;
	for(i = 0;i < n-1;i++){
		cin >> u >> v2;
		adj[u].pb(v2);
		adj[v2].pb(u);
	}
	for(i = 1;i <= a[1];i++){
		if(a[1]%i == 0){
			v.pb(i);
		}
	}
	dp[1] = a[1];
	vis[1] = true;
	for(auto it : adj[1]){
//		cout << it << " " << a[it] << endl;
		dfs1(it,a[it]);
	}
//	for(i = 1;i <= n;i++){
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	memset(vis,false,sizeof(vis));
	dfs2(1,0);
	for(i = 1;i <= n;i++){
		cout << dp[i] << " ";
	}
	cout<< endl;
}
