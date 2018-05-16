#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define MAX 50004
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n],gcd;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(i==0)
                gcd=arr[i];
            else
                gcd=__gcd(gcd,arr[i]);
        }
        if(gcd==1) {
            cout<<0<<"\n";
        } else {
            cout<<-1<<"\n";
        }
    }
    return 0;
}
