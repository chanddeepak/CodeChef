#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n,m,x,k;
        cin>>n>>m>>x>>k;
        string s;
        cin>>s;
        long e=0,o=0;
        for(long i=0;i<k;i++) {
            if(s[i]=='E')
                e++;
            if(s[i]=='O')
                o++;
        }
        long temp=n;
        for(int i=1;i<=m;i++) {
            if(i%2==0) {
                if(x>=e&&e>=0) {
                  temp-=e;
                  e=0;
                } else if(x<e) {
                    temp-=x;
                    e=e-x;
                }
            } else {
                if(x>=o&&o>=0) {
                  temp-=o;
                  o=0;
                } else if(x<o){
                    temp-=x;
                    o=o-x;
                }
            }
            if(temp<=0){
                break;
            }
        }
        if(temp<=0) {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }
    return 0;
}
