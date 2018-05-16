#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
bool cmp(int a,int b) {
    return a>b;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a,b;
        int p;
        for(int i=0;i<n;i++) {
            cin>>p;
            if(i%2==0)
                a.pb(p);
            else
                b.pb(p);
        }
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end());
            int tscore=0,mscore=0,m;
            if(a.size()==b.size())
            	m=a.size();
            else if(a.size()>b.size()) {
            	mscore=a[a.size()-1];
            	m=a.size()-1;
            }

            for(int i=0;i<m;i++) {
                if(b[i]<a[i]&&k!=0) {
                    tscore+=a[i];
                    mscore+=b[i];
                    k--;
                } else {
                    tscore+=b[i];
                    mscore+=a[i];
                }
            }
            //cout<<tscore<<" "<<mscore;
            if(tscore>mscore)
                cout<<"YES\n";
            else
                cout<<"NO\n";

    }
    return 0;
}
