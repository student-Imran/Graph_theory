/*
Brute Force Topological Sort
Algorithm

#include<bits/stdc++.h>
using namespace std;
const int N=105;
int indg[N];
bool vis[N];
vector<int> g[N];
void solve()
{
   int n,m;cin>>n>>m;
   while(m--){
   	int u,v;cin>>u>>v;
   	indg[v]++;
   	g[u].push_back(v);
   }
   vector<int>ans;
   while(ans.size()<n){
   	int cur=0;
   for(int i=1;i<=n;i++){
   	
   	if(indg[i]==0 and !vis[i]){
       cur=i;
       break;
   	}
   }
   if(cur==0){
	cout<<"Impossible\n";
	return;
	Here Impossible because existance of Cycle
   }
   	ans.push_back(cur);
   	vis[cur]=true;
   for(auto v:g[cur]){
   			indg[v]--;
   		}
   	}
  for(auto x: ans){
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

}*/
/*
Optimized Topsort O(V + E)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int indeg[N];
vector<int> g[N];
bool vis[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    indeg[v]++;
    g[u].push_back(v);
  }
  vector<int> z;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      z.push_back(i);
      vis[i] = true;
    }
  }
  vector<int> ans;
  while (ans.size() < n) {
    if (z.empty()) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    int cur = z.back();
    z.pop_back();
    ans.push_back(cur);
    for (auto v: g[cur]) {
      indeg[v]--;
      if (!vis[v] and indeg[v] == 0) {
        z.push_back(v);
        vis[v] = true;
      }
    }
  }
  for (auto x: ans) cout << x << ' ';
  return 0;
}*/


