#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
bool vis[N];
int colour[N];
bool ok;
vector<int> g[N];
void dfs(int node){
  vis[node]=true;
  for(auto x:g[node]){
  	if(!vis[x]){
        colour[x]=colour[node]^1;
  		dfs(x);
  	}
  	else{
  		if(colour[x]==colour[node]){
  			ok=false;
  		}
  	}
  }
}
void solve()
{
   int n,m;cin>>n>>m;
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);
   }
   ok=true;
   for(int i=1;i<=n;i++){
   	if(!vis[i]){
   		dfs(i);
   	}
   }
   if(ok){
   	cout<<"Yes Bipartite\n";
   }else{
   	cout<<"Not Bipartite\n";
   }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
 	return 0;

}

