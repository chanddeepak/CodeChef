#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
       long n,k;
       cin>>n>>k;
       vector<long> a(n),b(n),c(n);
       long j=0,sum=0,sum1=0;
       for(long i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]<0)
            j++;
        sum+=a[i];
        sum1+=a[i];
        b[i]=sum;
        c[i]=sum1;
        if(sum<=0) {
            sum=0;
        }
       }
       long temp=*max_element(b.begin(),b.end()-1),temp1=0;
       temp1=temp;
       long ans=0,ans2=0;

            if(j<n-1) {
                if(b[n-1]>0) {
                        for(long i =0;i<n;i++) {
                            if(b[n-1]+c[i]>temp1) {
                                ans2=b[n-1]+c[i];
                                temp1=ans2;
                            }
                        }
                         if(k==1) {
                        	ans=*max_element(b.begin(),b.end());
                         } else {
                        	if(c[n-1]>0) {
                            if(ans2!=0) {
                                if(ans2+c[n-1]*(k-2)>b[n-1]+c[n-1]*(k-1))
                                    ans=c[n-1]*(k-2)+ans2;
                                else {
                                	if(temp>b[n-1]+c[n-1]*(k-1))
                                	ans=temp;
                                	else
                                	ans=b[n-1]+c[n-1]*(k-1);
                                }

                            } else {
                                if(temp<b[n-1]+c[n-1]*(k-1))
                                    ans=b[n-1]+c[n-1]*(k-1);
                                else {
                                    ans=temp;
                                }
                         }
                        	} else {
                        		if(temp>ans2)
                        		ans=temp;
                        		else
                        		ans=ans2;
                        	}
                        }
                } else {
                ans=temp;
                }
            } else {
                ans=*max_element(a.begin(),a.end());
            }

            cout<<ans<<"\n";

    }
    return 0;
}
