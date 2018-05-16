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
        int n;
        cin>>n;
        long a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        long ans=0;
        for(int i=0;i<n;i++) {
            ans=ans^(a[i]+a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
