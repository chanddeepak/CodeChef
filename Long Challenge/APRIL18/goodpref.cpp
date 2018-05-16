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
        string s;
        ll n;
        cin>>s>>n;
        int m=s.size();
        ll a=0,b=0,ans=0;
        int i,temp1=0;
        for(i=0;i<n;i++) {
            int temp=0;
            for(int j=0;j<m;j++) {
                if(s[j]=='a') {
                    a++;
                }
                else {
                    b++;
                }
                if(a>b) {
                    ans++;
                    temp++;
                }
            }
            if(temp1==temp)
                break;
            temp1=temp;
        }
        if(i==n)
            cout<<ans<<"\n";
        else {
            ans=ans+(n-i-1)*temp1;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
