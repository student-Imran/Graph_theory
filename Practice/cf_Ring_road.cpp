#include<bits/stdc++.h>
using namespace std; 
const int N=101;
bool vis[N];
vector<pair<int,int>>g[N];
int m_cost;
void dfs(int node,int par){
   vis[node]=true;
   for(auto x:g[node]){
   	if(!vis[x.first]){
   		m_cost+=x.second;
   		dfs(x.first,node);
   	}
   	else if(x.first==1 and par!=1){
   		m_cost+=x.second;
   	}
   }
}
void solve()
{
  int n;cin>>n;
  int m=n;
  int sum=0;
  while(m--){
  	int u,v,cost;cin>>u>>v>>cost;
  	g[u].push_back({v,0});
  	g[v].push_back({u,cost});
  	sum+=cost;
  }
  dfs(1,0);
  cout<<min(m_cost,sum-m_cost)<<'\n';

     
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

