#include<bits/stdc++.h>
using namespace std;
 bool a[101][101];
void solve()
{
   int n;cin>>n;
   int u,k;
   for(int i=0;i<n;i++){
      cin>>u>>k;
   	  while(k--){
   		int vertex;
   		cin>>vertex;
   		a[i][vertex-1]=1;
   	 }
   }
   int i,j;
   for(i=0;i<n;i++){
   	for(j=0;j<n-1;j++){
   	   cout<<a[i][j]<<" ";
   	}cout<<a[i][j]<<'\n';
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

