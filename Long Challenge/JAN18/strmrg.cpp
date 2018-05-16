#include<iostream>
#include<string>
#include<vector>
using namespace std;
long lcs(string &a,string &b,int n,int m) {
    vector< vector<int> > l(n+1,vector<int>(m+1));

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0) {
                l[i][j]=0;
            } else if(a[i-1]==b[j-1]) {
                l[i][j]=l[i-1][j-1]+1;
            } else {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }

    return l[n][m];

}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        string a,b,c="",d="";
        cin>>a>>b;
        long p=0,q=0,r=0;
        c=a.at(0);
        d=b.at(0);
        for(int i=1;i<n;i++) {
            if(a[i]!=a[i-1])
                c+=a.at(i);
        }
        for(int i=1;i<m;i++) {
            if(b[i]!=b[i-1])
                d+=b.at(i);
        }
	q=c.length();
	r=d.length();
	p=lcs(c,d,q,r);
        cout<<q+r-p<<"\n";

    }
    return 0;
}
