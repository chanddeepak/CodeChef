#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,s,y;
        cin>>n>>s>>y;
        vector<double> v(n),d(n),p(n),c(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
            cin>>d[i];
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        double ans=0,a=(double)y/s;
        for(int i=0;i<n;i++) {
            if((d[i]==1&&p[i]<=0)||(d[i]==0&&p[i]>=0)) {
            	if(p[i]<0)
            		p[i]=(-p[i]);
                double t1=p[i]/v[i],t2;
                t2=t1-ans;
                if((t2-a)<0.000001) {
                    double t3=t2+c[i]/v[i];
                    if(ans-c[i]/v[i]-t1>=0.000001)
                        ans+=a;
                    else
                        ans+=t3+a;
                } else {
                    ans+=a;
                }
            } else {
                ans+=a;
            }
        }
        cout<<fixed<<setprecision(6);
        cout<<ans<<"\n";
    }
    return 0;
}
