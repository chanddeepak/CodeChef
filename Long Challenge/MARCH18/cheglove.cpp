#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        vector<long> l(n),g(n);
        for(int i=0;i<n;i++) {
            cin>>l[i];
        }
        for(int i=0;i<n;i++) {
            cin>>g[i];
        }
        int f=1,h=1;
        for(int i=0,j=n-1;i<n,j>=0;i++,j--) {
            if(g[i]<l[i]) {
                f=0;
            }
            if(g[j]<l[i]) {
                h=0;
            }
            if(f==0&&h==0)
                break;
        }
        if(f==0&&h==0)
            cout<<"none\n";
        else if(f==1&&h==1)
            cout<<"both\n";
        else if(f==1&&h==0)
            cout<<"front\n";
        else if(f==0&&h==1)
            cout<<"back\n";
    }
    return 0;
}
