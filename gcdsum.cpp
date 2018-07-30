#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    long A[n][m];
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>A[i][j];
    	}
    }
    long ans=0;
    for(int i=0;i<n;i++) {
    	for(int l=0;l<m;l++)
    	for(int k=i+1;k<n;k++) {
	    	for(int j=0;j<m;j++) {
	    		ans=(ans+__gcd(A[i][l],A[k][j]))%MOD;
	    	}
    	}
    }

    cout<<ans<<"\n";
    return 0;
}