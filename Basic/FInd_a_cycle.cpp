#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
int par[N];
bool dfs(int u,int par) {
  vis[u] = true;
  bool cycle=false;
  for (auto v: g[u]) {
     if(vis[v] and v==par){
      continue;
     }
     if(vis[v]){
      return true;
     }
     cycle|=dfs(v,u);
     
     }
  return cycle;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  bool exist_cycle = false;
  for (int i = 1; i <= n; i++) {
    if(vis[i])continue;
    if(dfs(i,0)){
      exist_cycle=true;
      break;
    }
  }
  cout<<exist_cycle<<'\n';
  return 0;
}