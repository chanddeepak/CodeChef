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
    	int a[n];
    	for(int i=0;i<n;i++) 
    		cin>>a[i];
    	int ans,c=0;
    	for(int i=0;i<n;i++)
    		if(a[i]%m==0)
    			c++;
    	ans=pow(2,c)-1;
    	cout<<ans<<"\n";
    }
    return 0;
}