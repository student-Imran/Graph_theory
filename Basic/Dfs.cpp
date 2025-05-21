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
   dfs(1);
   for(int i=1;i<=n;i++){
   	cout<<vis[i]<<endl;
   	if(!vis[i]){
   		cout<<"Disconnected\n";
   		return;
   	}
   }cout<<"Connected\n";
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

