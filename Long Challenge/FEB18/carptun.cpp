#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        double mp=0.0;
        vector<double> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(mp<a[i]) {
                mp=a[i];
            }
        }
        double d,s;
        long c;
        cin>>c>>d>>s;
        double ans=(double)((c-1)*mp);
        cout<<setprecision(20);
        cout<<ans<<"\n";
    }
    return 0;
}
