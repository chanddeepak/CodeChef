#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n,m;
    	cin>>n>>m;
    	int P[n+1][m+1];
    	P[0][0]=0;
    	for(int i=1;i<=n;i++) {
    		for(int j=1;j<=m;j++)
    			cin>>P[i][j];
    	}
    	int pre[n+1][m+1],inv[n+1][m+1];
    	for(int i=1;i<=m;i++) {
    		pre[0][i]=inv[0][i]=i;
    		pre[1][i]=P[1][i];
    		inv[1][pre[1][i]]=i;
    	}
    	for(int i=2;i<=n;i++) {
    		for(int j=1;j<=m;j++) {
    			pre[i][j]=P[i][pre[i-1][j]];
    			inv[i][pre[i][j]]=j;
    		}
    	}
    	int q;
    	cin>>q;
    	map<pair<int,int>, long> cache;
    	while(q--) {
    		int l,r;
    		cin>>l>>r;
    		if(cache[{l,r}]) {
    			cout<<cache[{l,r}]<<"\n";
    		} else {
    			long ans=0;
    			for(int i=1;i<=m;i++) {
    				//cout<<pre[r][i]<<" ";
    			//	if(l!=1) {
    					//cout<<pre[r][inv[l-1][i]]<<" ";
    					ans+=(long)i*pre[r][inv[l-1][i]];
    				/*}
    				else {
    					//cout<<pre[r][i]<<" ";
    					ans+=i*pre[r][i];
    				}*/
    			}
    			cache[{l,r}]=ans;
    			cout<<ans<<"\n";
    		}
    	}
    }
    return 0;
}