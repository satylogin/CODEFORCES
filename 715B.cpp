#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%lld",&n)
#define scl(n) scanf("%lld",&n)
#define p(n) printf("%d",&n)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1LL*1e18
const ll ma = 1LL*1e14;
set< pair<int,ll> > adj[1005];
set< pair<int,int> >se2,se3;
ll parent[1005];
#define SIZE 1005 
ll dist [SIZE];
bool vis [SIZE];
ll t;
ll dijkstra(ll so){

	memset(vis, false , sizeof vis);            
	dist[so] = 0;
	multiset < pair < ll , ll > > s;   
	s.insert({0 , so});                          
	ll e,w1,w2;
	ll v;
	pair<ll,int> p;
	while(!s.empty()){
		p = *s.begin();        
		s.erase(s.begin());
		v = p.se;
		w1 = p.fi;
		if( vis[v] ) continue;                  
		vis[v] = true;

		for( pair<ll,ll> pi : adj[v]){
			e = pi.fi;
			w2 = pi.se;
			if(dist[v] + w2 < dist[e]  ){
				parent[e] = v;
				dist[e] = dist[v] + w2;
				s.insert({dist[e],e});
			}
		}
	}
	return dist[t];
}

int main()
{
	ll i,j,k,l,m,n,r,cnt,s;
	ll flag;
	ll ans,an;
	cin >> n >> m >> l >> s >> t;
	ll u,v;
	ll w;
	for(i = 0;i < m;i++){
		sc(u),sc(v),scl(w);
		adj[u].insert(mp(v,w));
		adj[v].insert(mp(u,w));
		if(w == 0){
			se2.insert(mp(u,v));
		}
	}
	for( pair<ll,ll> p : se2){
		u = p.fi;
		v = p.se;
		adj[u].erase(mp(v,0));
		adj[v].erase(mp(u,0));
		adj[v].insert(mp(u,ma));
		adj[u].insert(mp(v,ma));
	}
	for(i = 0;i <= n;i++){
		dist[i] = INF;
	}
	ll upp_bo = dijkstra(s);
	if(upp_bo >= ma){
		upp_bo = INF;
	}
	if(upp_bo < l){
		cout << "NO" << endl;
		return 0;
	}
	ll tem;
	do{
		for( pair<ll,ll> p : se2){
			u = p.fi;
			v = p.se;
			adj[u].erase(mp(v,ma));
			adj[v].erase(mp(u,ma));
			adj[v].insert(mp(u,1));
			adj[u].insert(mp(v,1));
		}
		for(i = 0;i <= n;i++){
			dist[i] = INF;
		}
		ll lo_bo = dijkstra(s);
		if(lo_bo > l){
			cout << "NO" << endl;
			return 0;
		}
		if(lo_bo == l){
			break;
		}
		ll p;
		flag = 1;
		ll req = l - lo_bo;
		ll curr = t;
		flag = 0;
		se3.clear();
		while(curr != s){
			p = parent[curr];
			if(se2.find(mp(curr,p)) != se2.end() || se2.find(mp(p,curr)) != se2.end()){
				if(flag == 0){
					adj[curr].erase(mp(p,1));
					adj[p].erase(mp(curr,1));
					adj[curr].insert(mp(p,1+req));
					adj[p].insert(mp(curr,1+req));
					se2.erase(mp(curr,p));
					se2.erase(mp(p,curr));
					flag = 1;
				}
				else{
					se2.erase(mp(curr,p));
					se2.erase(mp(p,curr));
					se3.insert(mp(curr,p));
				}
			}
			curr = parent[curr];
		}
		for( pair<ll,ll> p : se2){
			u = p.fi;
			v = p.se;
			adj[u].insert(mp(v,ma));
			adj[v].insert(mp(u,ma));
			adj[v].erase(mp(u,1));
			adj[u].erase(mp(v,1));
		}
		for(i = 0;i <= n;i++){
			dist[i] = INF;
		}
		tem = dijkstra(s);
		if(tem == l){
			break;
		}
		else{
			se2.clear();
			for(pair<ll,ll> p : se3){
				se2.insert(p);
			}
		}
	}while(tem != l);

	cout << "YES" << endl;
	for(i = 0;i < n;i++){
		for( pair<ll,ll> p : adj[i]){
			printf("%lld %lld %lld\n",i,p.fi,p.se);
			adj[p.fi].erase(mp(i,p.se));
		}
	}
}
