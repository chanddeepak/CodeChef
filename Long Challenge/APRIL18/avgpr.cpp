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
        ll v[2001];
        for(int i=0;i<=2001;i++) {
            v[i]=0;
        }
        int x;
        for(int i=0;i<n;i++) {
            cin>>x;
            if(x<0)
            x=1000+(-x);
            v[x]++;
        }
        ll ans=0;
        for(int i=0;i<=2000;i++) {
            //cout<<v[i]<<" ";
            int l=0;
            if(i>1000)
            l=1000-i;
            else 
            l=i;
            if(v[i]!=0) {
                if(v[i]>1) {
                    ans+=(v[i]*(v[i]-1))/2;
                }
                for(int j=i+1;j<=2000;j++) {
                if(v[j]!=0) {
                    int e=0;
                if(j>1000) 
                e=1000-j;
                else
                e=j;
                    if((l+e)%2==0) {
                        int p=(l+e)/2;
                        if(p<0)
                        p=1000+(-p);
                        if(v[p]>0) {
                            ans+=v[i]*v[j];
                            //cout<<p<<" ";
                        }
 
                    }
                }
 
            }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
 
