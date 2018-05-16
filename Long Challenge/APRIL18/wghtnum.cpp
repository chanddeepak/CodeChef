#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
ll modExp(ll a,ll b) {
	int ans=1;
	while(b) {
		if(b&1==1) {  //for checking rightmost bit
			ans=(ans*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;    //if b=45 i.e 101101 after b/2 it becomes 10110
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v(310,0);
    int p=9,j=301;
    v[309]=1;
    for(int i=0;i<9;i++) {
        v[i]=p;
        v[j+i]=p;
        p--;
    }
    int t;
    cin>>t;
    while(t--) {
        ll n;
        int w;
        cin>>n>>w;
        if(w>8||w<-9) {
            cout<<0<<"\n";
        } else {
        	if(w<0)
        		w=300+(-w);
        	if(n<3)
        		cout<<v[w]<<"\n"; 
        	else {
        		n=(n-2)%(MOD-1);
            	ll ans=(v[w]*modExp(10,n))%MOD;
            	cout<<ans<<"\n";
        	}
        }
    }
    return 0;
}
