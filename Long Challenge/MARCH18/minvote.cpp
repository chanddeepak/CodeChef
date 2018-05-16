#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void votes1(vector<ll> &s,vector<ll> &ans,long n,long j) {
    long sum=0;
    for(int i=j+1;i<n;i++) {
        if(s[j]>=sum) {
            ans[i]++;
            sum+=s[i];
        } else {
        	break;
        }
    }
}
void votes2(vector<ll> &s,vector<ll> &ans,long n,long j) {
    long sum=0;
    for(int i=j-1;i>=0;i--) {
        if(s[j]>=sum) {
            ans[i]++;
            sum+=s[i];
        } else {
        	break;
        }
    }
}
int main() {
    long t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        vector<ll> s(n),ans(n,0);
        for(int i=0;i<n;i++) {
            cin>>s[i];
        }
        for(int i=0;i<n;i++) {
            if(i==0) {
               votes1(s,ans,n,i);
            } else if(i==n-1) {
                votes2(s,ans,n,i);
            } else {
                votes1(s,ans,n,i);
            votes2(s,ans,n,i);
            }
        }
        for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
