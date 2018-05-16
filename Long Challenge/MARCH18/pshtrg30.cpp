
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	long n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    while(q--) {
        long x,l,r;
        cin>>x>>l>>r;
        if(x==1) {
        	a[l-1]=r;
        } else {
	ll peri=0;
            if((r-l+1)<3) {
               cout<<0<<"\n";
            } else {
                vector<ll> v;
                copy(a.begin()+(l-1),a.begin()+r,back_inserter(v));
                sort(v.begin(),v.end());
                for(int i=v.size()-1;i>=2;i--) {
                //	cout<<v[i]<<" "<<v[i-1]<<" "<<v[i-2]<<" ";
            	if(v[i]<(v[i-1]+v[i-2])) {
            		peri=v[i]+v[i-1]+v[i-2];
            		break;
            	}
                }
                cout<<peri<<"\n";
            }
        }
    }

    return 0;
}
