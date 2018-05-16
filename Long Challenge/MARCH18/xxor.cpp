#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    long n,q;
    cin>>n>>q;
    vector<ll> a(n);
    vector< vector<int> > v(n,vector<int>(32,0));
    for(int i=0;i<n;i++) {
        cin>>a[i];
        for(int j=0;j<31;j++) {
            if(a[i]&(1<<j))
                v[i][j]++;
        }
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<31;j++)
            v[i][j]+=v[i-1][j];
    }
    while(q--) {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        ll ans=0,q=0;
        for(int i=0;i<31;i++) {
        	if(l!=0)
            q=v[r][i]-v[l-1][i];
            else
            q=v[r][i];
            if(q<(r-l+1)-q) {
                ans|=1LL<<i;
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}
