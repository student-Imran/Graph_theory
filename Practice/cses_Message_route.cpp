#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int>g[N];
bool vis[N];
int dis[N];
int par[N];
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
   while(!q.empty()){
   	int f=q.front();
   	q.pop();
   	for(auto x:g[f]){
       if(!vis[x]){
       	q.push(x);
         par[x]=f;
       	dis[x]=dis[f]+1;
       	vis[x]=true;
       }
   	}
   }
   if(dis[n]==0){
      cout<<"IMPOSSIBLE\n";
      return;
   }
   cout<<dis[n]+1<<'\n';
   int p=n;
   vector<int>path;
   while(p!=1){
      path.push_back(p);
      p=par[p];
   }path.push_back(1);
   reverse(path.begin(),path.end());
   for(auto y:path){
      cout<<y<<" ";
   }cout<<'\n';

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

