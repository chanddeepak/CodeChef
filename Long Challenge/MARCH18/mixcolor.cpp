#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        vector<long> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        int p=0,ans=0;
        for(int i=0;i<n-1;i++) {
            if(a[i]==a[i+1]) {
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
