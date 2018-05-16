#include<iostream>
#include<vector>
using namespace std;
vector<long> sum(1000007,0);
int main() {
    int t;
    cin>>t;
    for(long i=1;i<=1000000;i++) {
        sum[i]=(i*(i+1))/2;
    }
    while(t--) {
        long x,n;
        cin>>x>>n;
        vector<char> s(n+7,'a');
        if((sum[n]-x)%2==0) {
            long temp=(sum[n]-x)/2,temp1=0,temp2=0,d=0,temp3=0;
            s[x]='2';
            for(long i=1;i<=n;i++) {
                    if(s[i]=='a') {
                        s[i]='0';
                        temp1+=i;
                        if(temp1==temp)
                            break;
                        else if(temp1>temp) {
                            d=temp1-temp;
                            if(d!=x) {
                                s[d]='1';
                                break;
                            } else if(d==x&&(x!=2)&&(x!=1)) {
                                s[1]='1';
                                s[d-1]='1';
                                break;
                            } else if(d==x&&((x==2)||(x==1))) {
                                s[i]='1';
                                temp1=temp1-i;
                            }
                        }
                    }
            }

            for(long i=1;i<=n;i++) {
                if(s[i]=='a') {
                    s[i]='1';
                }
                if(s[i]=='0') {
                    temp2+=i;
                }
                if(s[i]=='1') {
                	temp3+=i;
                }
            }
            if(temp3==temp2)
            	for(long i=1;i<=n;i++)
                	cout<<s[i];
           else
            	cout<<"impossible";
            cout<<"\n";
        } else {
                cout<<"impossible";
                cout<<"\n";
        }
    }
    return 0;
}
