#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
bool vis[N];
vector<int> g[N];
void dfs(int node){
  vis[node]=true;
  for(auto x:g[node]){
  	if(!vis[x]){
  		dfs(x);
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
   int ans=0;
   vector<int>v;
   for(int i=1;i<=n;i++){
   	if(!vis[i]){
   		v.push_back(i);
   		dfs(i);
   		++ans;
   	}
   }cout<<ans-1<<'\n';
   for(int i=0;i<v.size()-1;i++){
   	cout<<v[i]<<" "<<v[i+1]<<'\n';
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

