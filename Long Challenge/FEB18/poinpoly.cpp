#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t;
    cin>>t;
    while(t--) {
        long n,c=0;
        cin>>n;
        int p=n/10;
        vector<long> x(n),y(n),x1,y1;
        for(int i=0;i<n;i++) {
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<n-2;i++) {
            for(int j=i+2;j<n;j++) {
            if(i==0) {
            if(j!=n-1) {
                
            }
            } else if(j!=i-1) {
                if((x[i]+x[j])%2==0&&(y[i]+y[j])%2==0) {
                    x1.push_back((x[i]+x[j])/2);
                    y1.push_back((y[i]+y[j])/2);
                    c++;
                }
                
            }
                if(c>=p)
                    break;
            }
            if(c>=p)
                break;
        }
        for(int i=0;i<x1.size();i++) {
            cout<<x1[i]<<" "<<y1[i]<<"\n";
        }
    }
    return 0;
}
