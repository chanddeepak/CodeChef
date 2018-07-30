#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

const int MAX=2e5+5;
vector<pair<int,int>> mima(MAX);
vector<int> g[MAX];

int dfs(int root) {
	if(g[root].size()==0)
		return 0;
	int lft=dfs(g[root][0]);
	int rgt=dfs(g[root][1]);
	//cout<<lft<<" "<<rgt<<" ";
	if(lft==-1||rgt==-1)
		return -1;
	if(mima[g[root][0]].se<mima[g[root][1]].fi) {
		mima[root]={mima[g[root][0]].fi,mima[g[root][1]].se};
		return lft+rgt;
	}
	if(mima[g[root][0]].fi>mima[g[root][1]].se) {
		mima[root]={mima[g[root][1]].fi,mima[g[root][0]].se};
		return lft+rgt+1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++) {
    		g[i].clear();
    		mima[i]={MAX,0};
    	}
    	int root;
    	for(int i=1;i<=n;i++) {
    		int l,r;
    		cin>>l>>r;
    		if(l==-1) {
    			mima[i]={r,r};
    		} else {
    			g[i].push_back(l);
    			g[i].push_back(r);
    		}
    	}
    	//cout<<root<<" ";
    	int ans=dfs(1);
    	cout<<ans<<"\n";
    }
    return 0;
}