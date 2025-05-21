#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+9;
void solve()
{
   vector<int> g[N];
   int n,m;cin>>n>>m;
   while(m--){
   	int u,v;cin>>u>>v;
   	g[u].push_back(v);
   	g[v].push_back(u);// For directed Graph it's remove
   }
   for(auto x:g[1]){
   	cout<<x<<" ";
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

