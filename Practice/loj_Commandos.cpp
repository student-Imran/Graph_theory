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
   for(int i=0;i<n;i++){
      par[i]=-1;
   }
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
      g[v].push_back(u);
   }
   //cout<<par[3]<<'\n';
   int st,meet;cin>>st>>meet;
   queue<int>q;
   q.push(st);
   vis[st]=true;
   dis[st]=0;
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
   int ans=0;
   for(int i=0;i<n;i++){
      if(par[i]==st){
         ans+=dis[i];
      }
      //cout<<dis[i]<<" ";
   }
   for(int i=0;i<n;i++){
      cout<<par[i]<<" ";
   }

   
  

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;

}

