#include<bits/stdc++.h>
using namespace std;
const int N=101;
bool vis[N];
int start[N],finished[N];
int ti=1;
vector<int> g[N];
void dfs(int node){
  vis[node]=true;
  start[node]=ti++;
  for(auto x:g[node]){
  	if(!vis[x]){
  		dfs(x);
  	}
  }finished[node]=ti++;
}
void solve()
{
   int n;cin>>n;
   int u,k;
   for(int i=0;i<n;i++){
      cin>>u>>k;
   	  while(k--){
   		int vertex;
   		cin>>vertex;
   		g[u].push_back(vertex);
   	 }//sort(g[u].begin(),g[u].end());
   	}
   for(int i=1;i<=n;i++){
   	if(!vis[i]){
   		dfs(i);
   	}
   }
   for(int i=1;i<=n;i++){
   	cout<<i<<" "<<start[i]<<" "<<finished[i]<<'\n';
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

