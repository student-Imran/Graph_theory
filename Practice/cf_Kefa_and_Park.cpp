#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
bool vis[N];
vector<int> g[N];
int cat[N];
int n,m,c,ans;
void dfs(int node,int c){
  if(cat[node]==1){
    	c++;
    }
    else {
    	c=0;
    }
    if(c>m){
    	return;
    }
    if(g[node].size()==1 and vis[g[node][0]]){
    	ans++;
    }
    vis[node]=true;
  for(auto x:g[node]){
    if(!vis[x]){
  		dfs(x,c);
  	}	
  }


}
void solve()
{
   cin>>n>>m;
   int x;
   for(int i=1;i<=n;i++){
   	cin>>x;
   	cat[i]=x;
   }
   int m1=n-1;
   while(m1--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);
   }
   dfs(1,0);
   cout<<ans<<'\n';

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;

}
