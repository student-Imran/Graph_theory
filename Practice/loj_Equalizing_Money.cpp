#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int test;
void dfs(int node,vector<int>*g,bool*vis,vector<int>*ve,int src){
  vis[node]=true;
  ve[src].push_back(node);
  for(auto x:g[node]){
  	if(!vis[x]){
  		dfs(x,g,vis,ve,src);
  	}
  }
}
void solve()
{
   test++;
   cout<<"Case "<<test<<": ";
   int n,m;cin>>n>>m;
   int we;
   int weight=0;
   vector<int> w[N];
   vector<int>g[N];
   bool vis[n+1]={false};
   for(int i=1;i<=n;i++){
    cin>>we;
    w[i].push_back(we);
    weight+=we;
   }
   //cout<<"weight "<<weight<<'\n';
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);
   }
   if(m==0){
    if(weight%n!=0){
      cout<<"No\n";
      return;
    }else{
      cout<<"Yes\n";
      return;
    }
   }
   else if(weight%n!=0){
      cout<<"No\n";
      return;
   }
   int ans=0;
   int pre;
   vector<int>ve[N];
   int source;
   for(int i=1;i<=n;i++){
   	if(!vis[i]){
      source=i;
   		dfs(i,g,vis,ve,source);
   	}
   }
   /*for(int i=1;i<=n;i++){
    cout<<i<<" ";
    for(auto x:ve[i]){
      cout<<x<<" ";
    }cout<<'\n';
   }*/
   int sum=0;
   int mon;
   int re_mon;
   int c=0;
   bool ok=true;
   bool re_vis[N]={false};
   for(int i=1;i<=n;i++){
    if(ve[i].size()>1){
      re_vis[i]=true;
      //sum+=w[i][0];
    for(auto y:ve[i]){
      re_vis[y]=true;
      sum+=w[y][0];
    }
    //cout<<sum<<'\n';
    //cout<<ve[i].size()<<'\n';
    mon=sum/(ve[i].size());
    if(sum%(ve[i].size())!=0){
      ok=false;
      break;
    }
    if(mon!=re_mon and c>0){
      ok=false;
      break;
    }
    else{
      re_mon=mon;
      c=1;
    }
    
   }
   else if(ve[i].size()==1 and !re_vis[i]){
    sum+=w[i][0];
    mon=sum;
    if(mon!=re_mon and c>0){
      ok=false;
      break;
    }
    else{
      re_mon=mon;
      c=1;
    }
   }
   //cout<<"money "<<mon<<'\n';
   sum=0;
  }
  if(ok){
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
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

