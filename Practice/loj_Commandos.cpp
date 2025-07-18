#include<bits/stdc++.h>
using namespace std;
int test;
void solve()
{
   test++;
   vector<int>dis(110,0);
   vector<bool>vis(110,false);
   vector<int>par(110,0);
   vector<int> g[110];
   int n,m;cin>>n>>m;
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);
   }
   int start,dest;
   cin>>start>>dest;
   queue<int>q;
   q.push(start);
   vis[start]=true;
   dis[start]=0;
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
  int ans=-1;
  for (int i = 0; i <n; ++i)
  {
     queue<int>q1;
     q1.push(i);
     vector<int>dis1(110,0);
     vector<bool>vis1(110,false);
     vis1[i]=true;
     dis1[i]=0;
     while(!q1.empty()){
     int u=q1.front();
     q1.pop();
     for(auto x : g[u]){
      if(!vis1[x]){
         q1.push(x);
         dis1[x]=dis1[u]+1;
         vis1[x]=true;
      }
     }
  }
  ans=max(ans,(dis[i]+dis1[dest]));

  }cout<<"Case "<<test<<": "<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;

}

