#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int dis[N];
bool vis[N];
int par[N];
vector<int> g[N];
void solve()
{
   int n,m;cin>>n>>m;
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);
   }
   queue<int>q;
   q.push(1);
   vis[1]=true;
   dis[1]=0;
   //Bfs
   while(!q.empty()){
   int u=q.front();
   q.pop();
   for(auto x : g[u]){
      if(!vis[x]){
      	q.push(x);
      	par[x]=u;
      	dis[x]=dis[u]+1;
      	vis[x]=true;
      }
   }
  }
  // Print shortest distance from source node
  for(int i=1;i<=n;i++){
  	cout<<dis[i]<<'\n';
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

