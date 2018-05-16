#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long> c(n),t(n);
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    long min1=INT_MAX,min2=INT_MAX,min3=INT_MAX,p=0;
    for(int i=0;i<n;i++) {
        if(t[i]==1) {
            if(min1>c[i])
                min1=c[i];
        }
        if(t[i]==2) {
            if(min2>c[i])
                min2=c[i];
        }
        if(t[i]==3) {
            p++;
            if(min3>c[i])
                min3=c[i];
        }
    }
    if(p==n) {
        cout<<min3<<"\n";
    } else {
    if(min3<min1+min2)
        cout<<min3<<"\n";
    else
        cout<<min2+min1<<"\n";
    }
    return 0;
}
