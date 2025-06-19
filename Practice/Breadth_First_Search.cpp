#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int>g[N];
bool vis[N];
int dis[N];
int par[N];
void solve()
{
   int n;cin>>n;
   for(int i=1;i<=n;i++){
   	int u,k;cin>>u>>k;
   	while(k--){
   		int v;cin>>v;
   		g[u].push_back(v);
   	}
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
       	dis[x]=dis[f]+1;
       	vis[x]=true;
       }
   	}
   }
   for(int i=1;i<=n;i++){
   	cout<<i<<" ";
   	if(dis[i]==0 and i!=1){
   		cout<<-1<<'\n';
   	}
   	else{
   		cout<<dis[i]<<'\n';
   	}
   	
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

