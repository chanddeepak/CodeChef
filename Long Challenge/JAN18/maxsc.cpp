#include<iostream>
#include<vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector< vector<long> > a(n,vector<long>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>a[i][j];
            }
        }
        int f=1;
        long maxElement=0,sum=0,e=0;
        for(int i=n-1;i>=0;i--) {
                e=0;
            for(int j=0;j<n;j++) {
                if(i==n-1) {
                    if(maxElement<a[i][j]) {
                        maxElement=a[i][j];
                    }
                } else {

                    if(a[i][j]<maxElement&&a[i][j]>e) {
                        e=a[i][j];
                    }
                }

            }
            if(i==n-1) {
            sum+=maxElement;
            } else if(e!=0) {
                maxElement=e;
                sum+=maxElement;
            } else {
                f=0;
                break;
            }
        }
        if(f==0)
            cout<<-1<<"\n";
        else
            cout<<sum<<"\n";
    }

    return 0;

}
