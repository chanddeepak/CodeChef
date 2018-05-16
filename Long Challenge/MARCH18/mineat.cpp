#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<long> &b,ll q,long h,long n) {
    ll p,th=0,i;
    for(i=n-1;i>=0;i--) {
        if(q>b[i])
            break;
        if(b[i]%q==0) {
          p=b[i]/q;
        } else {
            p=b[i]/q+1;
        }
        th+=p;
    }
    if((th+i+1)>h)
        return false;
    else
        return true;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        long n,h;
        cin>>n>>h;
        vector<long> b(n);
        ll ans=0;
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        if(h==n) {
            ans=b[n-1];
        } else {
            ll l=1,r=b[n-1],q=0;
            while(l<r) {
                q=l+(r-l)/2;
               // cout<<q<<" ";
                //bool b;
               // b=
                //cout<<check(b,q,h,n)<<" ";
                if(check(b,q,h,n))
                    r=q;
                else
                    l=q+1;
                    //cout<<l<<" "<<r<<" ";
            }
            //cout<<l<<r<<q;
            ans=r;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
